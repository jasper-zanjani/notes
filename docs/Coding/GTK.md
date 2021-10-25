# GTK

<figure><img src="/img/Logos/GTK_logo.svg" width="200px"></figure>

??? info "Resources"
    - [PyGObject API reference](https://lazka.github.io/pgi-docs/)
    - [PyGObject docs](https://pygobject.readthedocs.io/en/latest/index.html)

Because GTK+ class properties are implemented as Python properties, with few exceptions they can usually be set either at instantiation or using dedicated setter methods.

=== "kwarg"

    ```py
    window = Gtk.Window(title="Hello World")
    ```

=== "setter"

    ```py
    window.set_title(f"Hello, {name}!")
    ```

=== "Setting property"

    ```py
    window.props.title=f"Hello, {name}"
    ```

## Tasks

--8<-- "includes/Coding/GTK/Tasks.md"

## Glade

--8<-- "includes/Coding/GTK/Glade.md"

## API

--8<-- "includes/Coding/GTK/API.md"

## Glossary

--8<-- "includes/Coding/GTK/Glossary.md"

## Examples

### [GNOME Tweaks](https://gitlab.gnome.org/GNOME/gnome-tweaks)

**GnomeTweaks** is the [application](#application) class and is defined in **gtweak/app.py**.

**Window** is the [window](#window) class, and its constructor takes the application and liststore subclass instances as arguments.

```py
class GnomeTweaks(Gtk.Application):
    def do_activate(self):
        if not self.win:
            model = TweakModel()
            self.win = Window(self, model)
            self.win.show_all()
        self.win.present()
```
**TweakModel** inherits from [Gtk.ListStore](#liststore) and stores **tweak groups** which correspond to the pages of settings in the app.
These tweak groups are defined as classes in Python modules placed in **gtweak/tweaks**, each of them subclassing parent classes like GSettingsSwitchTweak and GetterSetterSwitchTweak, which are defined in **gtweak/widgets.py**.

Each of the tweak group modules defines a top-level list named **`TWEAK_GROUPS`** with only a single element - an instance of **ListBoxTweakGroup**, which is also defined in widgets.py.
ListBoxTweakGroup, in turn, is a subclass of [Gtk.ListBox](#listbox) and **TweakGroup** (tweakmodel.py) by multiple inheritance.

Some `TWEAK_GROUP`s like that of the Desktop group are only populated conditionally.

=== "Desktop"

    ```py
    from gtweak.widgets import ListBoxTweakGroup, GSettingsSwitchTweak, Title

    dicons = GSettingsSwitchTweak(_("Show Icons"),"org.gnome.desktop.background","show-desktop-icons")
    home = GSettingsSwitchTweak(_("Home"),"org.gnome.nautilus.desktop",
                                "home-icon-visible", depends_on=dicons,
                                schema_filename="org.gnome.nautilus.gschema.xml")

    TWEAK_GROUPS = []

    if home.loaded:
        TWEAK_GROUPS.append(ListBoxTweakGroup(_("Desktop"),
            Title(_("Icons on Desktop"), "", uid="title-theme", top=True),
            dicons,
            home,
            GSettingsSwitchTweak(_("Network Servers"),"org.gnome.nautilus.desktop", "network-icon-visible", depends_on=dicons, schema_filename="org.gnome.nautilus.gschema.xml"),
            GSettingsSwitchTweak(_("Trash"),"org.gnome.nautilus.desktop", "trash-icon-visible", depends_on=dicons, schema_filename="org.gnome.nautilus.gschema.xml"),
            GSettingsSwitchTweak(_("Mounted Volumes"),"org.gnome.nautilus.desktop", "volumes-visible", depends_on=dicons, schema_filename="org.gnome.nautilus.gschema.xml"),
        ))

    ```
=== "General"

    ```py
    TWEAK_GROUPS = [
        ListBoxTweakGroup(_("General"),
            GSettingsSwitchTweak(_("Animations"), "org.gnome.desktop.interface", "enable-animations"),
            IgnoreLidSwitchTweak(),
            # Don't show this setting in the Ubuntu session since this setting is in gnome-control-center there
            GSettingsSwitchTweak(_("Over-Amplification"), "org.gnome.desktop.sound", "allow-volume-above-100-percent",
                desc=_("Allows raising the volume above 100%. This can result in a loss of audio quality; it is better to increase application volume settings, if possible."), loaded=_shell_not_ubuntu),
        ),
    ]
    ```

ListBoxTweakGroup is instantiated with a series of arguments, starting with its name and followed by individual **tweaks** or settings.
These tweaks are also defined as classes in **gtweak/widgets.py**, although some like IgnoreLidSwitchTweak are defined inline with the `TWEAK_GROUP` lists where they are instantiated.
I'm still not sure what the **`_()`** means, but it is apparently some function call.

All tweaks share some features:

- Their names reflect the control used in their interface ("Switch", "SpinButton", "ComboEnum", etc) in the form "**GSettings...Tweak**
- They subclass [Gtk.Box](#box), **\_GSettingsTweak**, and **\_DependableMixin** by multiple inheritance
- They instantiate a horizontally oriented Gtk.Box with a curious syntax.
```py
Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
```
- They instantiate \_GSettingsTweak with a similar syntax
```py
_GSettingsTweak.__init__(self, name, schema_name, key_name, **options)
```
- The rest of the widget is defined procedurally and added to **self** in the constructor as normal

By far the most common tweak is **GSettingsSwitchTweakValue**.


=== "GSettingsSwitchTweak"

    ```py
    class GSettingsSwitchTweak(Gtk.Box, _GSettingsTweak, _DependableMixin):
        def __init__(self, name, schema_name, key_name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            w = Gtk.Switch()
            self.settings.bind(key_name, w, "active", Gio.SettingsBindFlags.DEFAULT)

            self.add_dependency_on_tweak(
                    options.get("depends_on"),
                    options.get("depends_how")
            )

            vbox1 = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
            vbox1.props.spacing = UI_BOX_SPACING
            lbl = Gtk.Label(label=name)
            lbl.props.ellipsize = Pango.EllipsizeMode.END
            lbl.props.xalign = 0.0
            vbox1.pack_start(lbl, True, True, 0)

            if options.get("desc"):
                description = options.get("desc")
                lbl_desc = Gtk.Label()
                lbl_desc.props.xalign = 0.0
                lbl_desc.set_line_wrap(True)
                lbl_desc.get_style_context().add_class("dim-label")
                lbl_desc.set_markup("<span size='small'>"+GLib.markup_escape_text(description)+"</span>")
                vbox1.pack_start(lbl_desc, True, True, 0)

            vbox2 = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
            vbox2_upper = Gtk.Box()
            vbox2_lower = Gtk.Box()
            vbox2.pack_start(vbox2_upper, True, True, 0)
            vbox2.pack_start(w, False, False, 0)
            vbox2.pack_start(vbox2_lower, True, True, 0)

            self.pack_start(vbox1, True, True, 0)
            self.pack_start(vbox2, False, False, 0)
            self.widget_for_size_group = None
    ```

=== "GSettingsSwitchTweakValue"

    ```py
    class GSettingsSwitchTweakValue(Gtk.Box, _GSettingsTweak):

        def __init__(self, name, schema_name, key_name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            sw = Gtk.Switch()
            sw.set_active(self.get_active())
            sw.connect("notify::active", self._on_toggled)

            vbox1 = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
            vbox1.props.spacing = UI_BOX_SPACING
            lbl = Gtk.Label(label=name)
            lbl.props.ellipsize = Pango.EllipsizeMode.END
            lbl.props.xalign = 0.0
            vbox1.pack_start(lbl, True, True, 0)

            if options.get("desc"):
                description = options.get("desc")
                lbl_desc = Gtk.Label()
                lbl_desc.props.xalign = 0.0
                lbl_desc.set_line_wrap(True)
                lbl_desc.get_style_context().add_class("dim-label")
                lbl_desc.set_markup("<span size='small'>"+GLib.markup_escape_text(description)+"</span>")
                vbox1.pack_start(lbl_desc, True, True, 0)

            vbox2 = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
            vbox2_upper = Gtk.Box()
            vbox2_lower = Gtk.Box()
            vbox2.pack_start(vbox2_upper, True, True, 0)
            vbox2.pack_start(sw, False, False, 0)
            vbox2.pack_start(vbox2_lower, True, True, 0)

            self.pack_start(vbox1, True, True, 0)
            self.pack_start(vbox2, False, False, 0)
            self.widget_for_size_group = None

        def _on_toggled(self, sw, pspec):
            self.set_active(sw.get_active())

        def set_active(self, v):
            raise NotImplementedError()

        def get_active(self):
            raise NotImplementedError()
    ```

=== "GSettingsFontButtonTweak"

    ```py
    class GSettingsFontButtonTweak(Gtk.Box, _GSettingsTweak, _DependableMixin):
        def __init__(self, name, schema_name, key_name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            w = Gtk.FontButton()
            w.set_use_font(True)
            self.settings.bind(key_name, w, "font-name", Gio.SettingsBindFlags.DEFAULT)
            build_label_beside_widget(name, w, hbox=self)
            self.widget_for_size_group = w
    ```

=== "GSettingsRangeTweak"

    ```py
    class GSettingsRangeTweak(Gtk.Box, _GSettingsTweak, _DependableMixin):
        def __init__(self, name, schema_name, key_name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            # returned variant is range:(min, max)
            _min, _max = self.settings.get_range(key_name)[1]

            w = Gtk.HScale.new_with_range(_min, _max, options.get('adjustment_step', 1))
            self.settings.bind(key_name, w.get_adjustment(), "value", Gio.SettingsBindFlags.DEFAULT)

            build_label_beside_widget(self.name, w, hbox=self)
            self.widget_for_size_group = w
    ```

=== "GSettingsSpinButtonTweak"

    ```py
    class GSettingsSpinButtonTweak(Gtk.Box, _GSettingsTweak, _DependableMixin):
        def __init__(self, name, schema_name, key_name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            # returned variant is range:(min, max)
            _min, _max = self.settings.get_range(key_name)[1]

            adjustment = Gtk.Adjustment(value=0, lower=_min, upper=_max, step_increment=options.get('adjustment_step', 1))
            w = Gtk.SpinButton()
            w.set_adjustment(adjustment)
            w.set_digits(options.get('digits', 0))
            self.settings.bind(key_name, adjustment, "value", Gio.SettingsBindFlags.DEFAULT)

            build_label_beside_widget(name, w, hbox=self)
            self.widget_for_size_group = w

            self.add_dependency_on_tweak(
                    options.get("depends_on"),
                    options.get("depends_how")
            )
    ```

=== "GSettingsComboEnumTweak"

    ```py
    class GSettingsComboEnumTweak(Gtk.Box, _GSettingsTweak, _DependableMixin):
        def __init__(self, name, schema_name, key_name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            _type, values = self.settings.get_range(key_name)
            value = self.settings.get_string(key_name)
            self.settings.connect('changed::'+self.key_name, self._on_setting_changed)

            w = build_combo_box_text(value, *[(v, v.replace("-", " ").title()) for v in values])
            w.connect('changed', self._on_combo_changed)
            self.combo = w

            build_label_beside_widget(name, w, hbox=self)
            self.widget_for_size_group = w

        def _values_are_different(self):
            # to stop bouncing back and forth between changed signals. I suspect there must be a nicer
            # Gio.settings_bind way to fix this
            return self.settings.get_string(self.key_name) != \
                self.combo.get_model().get_value(self.combo.get_active_iter(), 0)

        def _on_setting_changed(self, setting, key):
            assert key == self.key_name
            val = self.settings.get_string(key)
            model = self.combo.get_model()
            for row in model:
                if val == row[0]:
                    self.combo.set_active_iter(row.iter)
                    break

        def _on_combo_changed(self, combo):
            val = self.combo.get_model().get_value(self.combo.get_active_iter(), 0)
            if self._values_are_different():
                self.settings.set_string(self.key_name, val)
    ```

=== "GSettingsComboTweak"

    ```py
    class GSettingsComboTweak(Gtk.Box, _GSettingsTweak, _DependableMixin):
        def __init__(self, name, schema_name, key_name, key_options, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            _GSettingsTweak.__init__(self, name, schema_name, key_name, **options)

            # check key_options is iterable
            # and if supplied, check it is a list of 2-tuples
            assert len(key_options) >= 0
            if len(key_options):
                assert len(key_options[0]) == 2
            self._key_options = key_options

            self.combo = build_combo_box_text(
                        self.settings.get_string(self.key_name),
                        *key_options)
            self.combo.connect('changed', self._on_combo_changed)
            self.settings.connect('changed::'+self.key_name, self._on_setting_changed)

            build_label_beside_widget(name, self.combo, hbox=self)
            self.widget_for_size_group = self.combo

        def _on_setting_changed(self, setting, key):
            assert key == self.key_name
            val = self.settings.get_string(key)
            model = self.combo.get_model()
            for row in model:
                if val == row[0]:
                    self.combo.set_active_iter(row.iter)
                    return

            self.combo.set_active(-1)

        def _on_combo_changed(self, combo):
            _iter = combo.get_active_iter()
            if _iter:
                value = combo.get_model().get_value(_iter, 0)
                self.settings.set_string(self.key_name, value)

        @property
        def extra_info(self):
            if self._extra_info is None:
                self._extra_info = self.settings.schema_get_summary(self.key_name)
                self._extra_info += " " + " ".join(op[0] for op in self._key_options)
            return self._extra_info
    ```

**IgnoreLidSwitchTweak** is unusual as a tweak that inherits from GetterSetterSwitchTweak, which inherits in turn from the **Tweak** base class that is actually in gtweak/tweakmodel.py


=== "IgnoreLidSwitchTweak"

    ```py
    class IgnoreLidSwitchTweak(GetterSetterSwitchTweak):
        def __init__(self, **options):
            self._inhibitor_name = "gnome-tweak-tool-lid-inhibitor"
            self._inhibitor_path = "%s/%s" % (gtweak.LIBEXEC_DIR, self._inhibitor_name)

            self._dfile = AutostartFile(None,
                                        autostart_desktop_filename = "ignore-lid-switch-tweak.desktop",
                                        exec_cmd = self._inhibitor_path)

            GetterSetterSwitchTweak.__init__(self, _("Suspend when laptop lid is closed"), **options)

        def get_active(self):
            return not self._sync_inhibitor()

        def set_active(self, v):
            self._dfile.update_start_at_login(not v)
            self._sync_inhibitor()

        def _sync_inhibitor(self):
            if (self._dfile.is_start_at_login_enabled()):
                GLib.spawn_command_line_async(self._inhibitor_path)
                return True
            else:
                bus = Gio.bus_get_sync(Gio.BusType.SESSION, None)
                bus.call('org.gnome.tweak-tool.lid-inhibitor',
                        '/org/gnome/tweak_tool/lid_inhibitor',
                        'org.gtk.Actions',
                        'Activate',
                        GLib.Variant('(sava{sv})', ('quit', [], {})),
                        None, 0, -1, None)
                return False
    ```

=== "GetterSetterSwitchTweak"

    ```py
    class GetterSetterSwitchTweak(Gtk.Box, Tweak):
        def __init__(self, name, **options):
            Gtk.Box.__init__(self, orientation=Gtk.Orientation.HORIZONTAL)
            Tweak.__init__(self, name, options.get("description", ""), **options)

            sw = Gtk.Switch()
            sw.set_active(self.get_active())
            sw.connect("notify::active", self._on_toggled)

            build_label_beside_widget(name, sw, hbox=self)

        def _on_toggled(self, sw, pspec):
            self.set_active(sw.get_active())

        def get_active(self):
            raise NotImplementedError()

        def set_active(self, v):
            raise NotImplementedError()
    ```

=== "Tweak"

    ```py
    class Tweak(object):

        main_window = None
        widget_for_size_group = None
        extra_info = ""

        def __init__(self, name, description, **options):
            self.name = name or ""
            self.description = description or ""
            self.uid = options.get("uid", self.__class__.__name__)
            self.group_name = options.get("group_name", _("Miscellaneous"))
            self.loaded = options.get("loaded", True)
            self.widget_sort_hint = None

            self._search_cache = None

        def search_matches(self, txt):
            if self._search_cache is None:
                self._search_cache = string_for_search(self.name) + " " + \
                    string_for_search(self.description)
                try:
                    self._search_cache += " " + string_for_search(self.extra_info)
                except:
                    LOG.warning("Error adding search info", exc_info=True)
            return txt in self._search_cache

        def notify_logout(self):
            self._logoutnotification = LogoutNotification()

        def notify_information(self, summary, desc=""):
            self._notification = Notification(summary, desc)
    ```