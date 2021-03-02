Polybar configuration is in `dosini` format, with comments preceded by `;` and values set with `=`. 

```ini
[bar/bar]
width=100%
height=40
background=#c00
foreground=#000
font-0 = Noto Sans Mono:style=Regular:size=18;0
modules-center=i3
[module/i3]
type=internal/i3
format=<label-state>
; vim:ft=dosini
```

Although whitespace appears to be ignored in most places, any whitespace after the closing bracket on the line reading "`[module/i3]`",for example, will cause that module not to be loaded.

Each module has to have one of a few accepted `type` values which will determine what other values it can accept and the module's behavior in the finished bar.

| Option           | Effect                |
| ---------------- | --------------------- |
| `-c $CONFIGFILE` | specify {$CONFIGFILE} |


The established demos appear to rely on old versions of Font Awesome, the following font names should be used after installing.
The following changes fixed the error where "-1" would appear for every workspace:
```ini
label-focused = %name%
label-unfocused=%name%
label-visible=%name%
label-urgent=%name%
```

Syntax                        | Description
`; Comment`                   | comments marked by semicolon
`[bar/BARNAME]`               | begin definition of `BARNAME`
`[module/mpd]`                | disabling this module by commenting it out removed a lot of error
`polybar -vvv`                : "+i3" will appear in the output if this module is installed
`pin-workspaces = true`       | will show monitor-specific workspaces
`format`                      | appears to interpolate or concatenate various values enclosed in `<>` angle brackets

ANY extraneous whitespace is likely to cause issues.
Here, `label` needs to match name of the i3 workspace
```ini
aws-icon-n=label;icon`
```

Appears to display the raw name of the workspace as configured in the i3 config file, and is common to many of the polybar configs
```ini
format = <label-state> <label-mode>
```
