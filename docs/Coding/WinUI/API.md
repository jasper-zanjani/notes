# API

#### ComboBox
:   
    ![](/img/GUI-ComboBox.gif)

    Important attributes:

    - `Items` or `ItemsSource` specify the collection (preferably `IObservableCollection` to support event handling on value changes) to be used to [populate](#mock-data) the control.
    - `SelectedItem` defines the element that appears selected by the control by default. 
    If not defined, no element will be selected.
    - `DisplayMemberPath` defines the name of the property to be used to display each individual choice.

    ```xml
    <ComboBox 
        ItemsSource="{x:Bind Items}" 
        SelectedItem="{x:Bind Items[0]}"
        DisplayMemberPath="Display" />
    ```

#### CommandBar
:   
    [**CommandBar**](https://docs.microsoft.com/en-us/windows/uwp/design/controls-and-patterns/app-bars) is a lightweight control that can organize a bar of buttons.

    ![](/img/GUI-WBC-CommandBar.jpg)

    ```xml
    <CommandBar>
        <AppBarButton x:Name="AddCustomer" Click="AddCustomer_Click" Label="Add">
            <SymbolIcon Symbol="AddFriend"/>
        </AppBarButton>
        <AppBarButton x:Name="DeleteCustomer" Click="DeleteCustomer_Click" Label="Delete">
            <SymbolIcon Symbol="Delete"/>
        </AppBarButton>
        <AppBarButton x:Name="btn_MoveSideBar" Click="btn_MoveSideBar_Click" Label="Move sidebar">
            <SymbolIcon x:Name="btn_MoveSideBar_Symbol" Symbol="AlignRight"/>
        </AppBarButton>
    </CommandBar>
    ```

#### [DataGrid](https://docs.microsoft.com/en-us/windows/communitytoolkit/controls/datagrid)
:   



#### Dialog boxes

In XAML, the **MessageDialog** object can be used to create a **modal** dialog box (i.e. one that does not allow interaction with the main window until the dialog box has been cleared).

The MessageDialog object can take a string argument containing the text of the dialog box.
It is actually displayed by calling the object's ShowAsync() method.
Because this is an asynchronous call, it must be `await`ed, which requires the `System` namespace. ([src](https://app.pluralsight.com/course-player?clipId=45b6766d-40bf-4be9-b3c9-26800ca4974e))

```csharp
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Windows.UI.Popups;
using System;

namespace WiredBrainCoffee.UWP
{
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private async void AddCustomer(object sender, RoutedEventArgs e)
        {
            var messageDialog = new MessageDialog("Customer added!");
            await messageDialog.ShowAsync();
        }
    }
}
```

#### Grid
:   
    The **`Grid`** layout panel is analogous to the **grid** geometry manager in tkinter.
    However, in XAML you are forced to explicitly declare **RowDefinition`** and **`ColumnDefinition** elements. 
    Whereas in tkinter, the widget being placed declares its own grid position.
    If the grid is sparse, the empty rows and columns appear to be ignored.

    Grid **star-sizing** works similar to `flex-grow` and `flex-shrink` CSS style statements used with Flexbox.

    === "Rows"

        <details>
        <summary>![](/img/GUI-Rainbow-Rows.gif)</summary>

        ```xml
        <Grid>
            <Grid.RowDefinitions>
                <RowDefinition/>
                <RowDefinition/>
                <RowDefinition/>
                <RowDefinition/>
                <RowDefinition/>
                <RowDefinition/>
                <RowDefinition/>
                <RowDefinition/>
            </Grid.RowDefinitions>

            <Rectangle Fill="LightGray"/>
            <Rectangle Fill="LightSteelBlue" Grid.Row="1"/>
            <Rectangle Fill="LightBlue" Grid.Row="2"/>
            <Rectangle Fill="LightCyan" Grid.Row="3"/>
            <Rectangle Fill="LightSeaGreen" Grid.Row="4"/>
            <Rectangle Fill="LightGreen" Grid.Row="5"/>
            <Rectangle Fill="LightGoldenrodYellow" Grid.Row="6" />
            <Rectangle Fill="LightSalmon" Grid.Row="7"/>
            <Rectangle Fill="LightCoral" Grid.Row="8"/>
        </Grid>
        ```
        </details>

    === "Columns"

        <details>
        <summary>
        ![](/img/GUI-Rainbow-Columns.gif)
        </summary>

        ```xml
        <Grid>
            <Grid.ColumnDefinitions>
                <ColumnDefinition/>
                <ColumnDefinition/>
                <ColumnDefinition/>
                <ColumnDefinition/>
                <ColumnDefinition/>
                <ColumnDefinition/>
                <ColumnDefinition/>
                <ColumnDefinition/>
            </Grid.ColumnDefinitions>

            <Rectangle Fill="LightGray"/>
            <Rectangle Fill="LightSteelBlue" Grid.Column="1"/>
            <Rectangle Fill="LightBlue" Grid.Column="2"/>
            <Rectangle Fill="LightCyan" Grid.Column="3"/>
            <Rectangle Fill="LightSeaGreen" Grid.Column="4"/>
            <Rectangle Fill="LightGreen" Grid.Column="5"/>
            <Rectangle Fill="LightGoldenrodYellow" Grid.Column="6" />
            <Rectangle Fill="LightSalmon" Grid.Column="7"/>
            <Rectangle Fill="LightCoral" Grid.Column="8"/>
        </Grid>
        ```
        </details>



#### ListDetailsView [:material-microsoft:](https://docs.microsoft.com/en-us/windows/communitytoolkit/controls/masterdetailsview "Microsoft Docs - ListDetailsView")
:   
    **ListDetailsView** is a custom control available from the [Windows Community Toolkit](https://docs.microsoft.com/en-us/windows/communitytoolkit/) (Nuget package `Microsoft.Toolkit.UWP`) that implements the [Master/Details pattern](#master-details-pattern).

    === "Illustration"

        ![](/img/ListDetailsView.gif)

    === "Basic structure"

        - `xmlns:toolkit="using:Microsoft.Toolkit.Uwp.UI.Controls`: namespace
            - **toolkit:ListDetailsView**
                - `toolkit:ListDetailsView.`**ItemTemplate** property-element for how items are rendered in sidebar
                - `toolkit:ListDetailsView.`**DetailsTemplate** property-element for how items are rendered in the main pane
                - `toolkit:ListDetailsView.`**NoSelectionContentTemplate** property-element for how the main pane is rendered with no item selected
                - `toolkit:ListDetailsView.`**AppCommandBar**

    === "XAML"

        ```xml
        <Page
            <!-- ... -->
            xmlns:toolkit="using:Microsoft.Toolkit.Uwp.UI.Controls">
            <toolkit:ListDetailsView>
                <toolkit:ListDetailsView.ItemTemplate>
                </toolkit:ListDetailsView.ItemTemplate>

                <toolkit:ListDetailsView.DetailsTemplate>
                </toolkit:ListDetailsView.DetailsTemplate>

                <toolkit:ListDetailsView.NoSelectionContentTemplate>
                </toolkit:ListDetailsView.NoSelectionContentTemplate>

                <toolkit:ListDetailsView.AppCommandBar>
                </toolkit:ListDetailsView.AppCommandBar>
            </toolkit:ListDetailsView>
        </Page>
        ```


#### ListView
:   
    ![](/img/GUI-ListView.gif)

    ```xml
    <ListView
        ItemsSource="{x:Bind Items}" 
        SelectedItem="{x:Bind Items[0]}"
        DisplayMemberPath="Display"/>
    ```

    Important attributes:

    - `Items` or `ItemsSource` specify the collection (preferably `IObservableCollection` to support event handling on value changes) to be used to [populate](#mock-data) the control.
    - `SelectedItem` defines the element that appears selected by the control by default. 
    If not defined, no element will be selected.
    - `DisplayMemberPath` defines the name of the property to be used to display each individual choice.




    === "MainWindow.xaml"

        ```xml
        <Window
            x:Class="Scratchpad1.MainWindow"
            xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
            xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
            xmlns:local="using:Scratchpad1"
            xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
            xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
            mc:Ignorable="d">

            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center" VerticalAlignment="Center">
                <ComboBox 
                    ItemsSource="{x:Bind Items}" 
                    SelectedItem="{x:Bind Items[0]}"
                    DisplayMemberPath="Name" />
            </StackPanel>
        </Window>
        ```

    === "MainWindow.xaml.cs"

        ```csharp
        using System.Collections.Generic;
        using Microsoft.UI.Xaml;

        namespace Scratchpad1
        {

            public class Starship
            {
                public string Name { get; set; }
                public string Registry { get; set; }
                public int Crew { get; set; }

                public Starship(string name, string registry, int crew)
                {
                    Name = name;
                    Registry = registry;
                    Crew = crew;
                }
            }


            public sealed partial class MainWindow : Window
            {
                //List<string> Items = new List<string>();
                Starship[] Items = new Starship[3];


                public MainWindow()
                {
                    this.InitializeComponent();
                    Items[0]=new Starship("USS Enterprise","NCC-1701",204);
                    Items[1]=new Starship("USS Constitution","NCC-1700",203);
                    Items[2]=new Starship("USS Defiant","NCC-1764",202);
                }
            }
        }
        ```

#### NavigationView 
:   
    [**NavigationView**](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.navigationview?view=winrt-19041 "Microsoft Docs - NavigationView Class") provides [top-level navigation](https://docs.microsoft.com/en-us/windows/uwp/design/controls-and-patterns/navigationview) by implementing a collapsible navigation bar ("hamburger menu") that is reactive to window size.
    It organizes two areas - **Pane** and **Content** - into two layout options that differ in the placement of the Pane. 
    The **Header** content is placed above the Content in both layouts.


    === "Left"

        ![](/img/NavigationView-anatomy-Left.png)

    === "Top"

        ![](/img/NavigationView-anatomy-Top.png)



    It has various **display modes** that can be specified by setting **PaneDisplayMode**.
    By default, PaneDisplayMode is set to **Auto**, which enables **adaptive** (i.e. reactive) behavior, switching between Left, LeftCompact, and LeftMinimal display modes depending on window size.


    === "Left"

        ![](/img/NavigationView-Left.png)

    === "LeftCompact"

        ![](/img/NavigationView-LeftCompact.png)

    === "LeftMinimal"

        ![](/img/NavigationView-LeftMinimal.png)

    === "Top"

        ![](/img/NavigationView-Top.png)

    The Pane is the central feature of NavigationView, and it can contain many items organized into several sections.

    - [**MenuItems** :material-microsoft:](https://docs.microsoft.com/en-us/uwp/api/microsoft.ui.xaml.controls.navigationview.MenuItems) is the main section containing NavigationView items at the beginning of the control. 
    - [FooterMenuItems :material-microsoft:](https://docs.microsoft.com/en-us/uwp/api/microsoft.ui.xaml.controls.navigationview.FooterMenuItems) is similar but they are added to the end of the control.
    - [PaneTitle :material-microsoft:](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.navigationview.PaneTitle) can accept text, which will appear next to the menu button.
    - [PaneHeader :material-microsoft:](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.navigationview.PaneHeader) is similar but can accept non-text content.
    - [PaneFooter :material-microsoft:](https://docs.microsoft.com/en-us/uwp/api/microsoft.ui.xaml.controls.navigationview.PaneFooter) can also accept any content.

    NavigationView items can be of various types:

    1. **NavigationViewItemHeader** can visually organize other navigation items
    2. [**NavigationViewItem** :material-microsoft:](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.navigationviewitem) exposes Content and Icon properties.
    3. **NavigationViewItemSeparator**
    4. **AutoSuggestBox**
    5. **Settings button** visible by default but can be hidden by setting **IsSettingsVisible**

    === "Left"

        ![](/img/NavigationView-anatomy-items-Left.png)

    === "Top"

        ![](/img/NavigationView-anatomy-items-Top.png)

    === "MenuItems"

        ```xml
        <Page>
            <NavigationView>
                <NavigationView.MenuItems/>
            </NavigationView>
        </Page>
        ```


    Navigation using NavigationView is not automatically implemented but relies on event handling. 
    NavigationView raises an **ItemInvoked** event when selected, and if the selection has changed then **SelectionChanged** is also raised.

    NavigationView also feature a Back button, which can be disabled or removed by setting **IsBackButtonVisible** or **IsBackEnabled** to false.
    If enabled, this button raises the **BackRequested** event.

    Typical implementations pair NavigationView with a **Frame** nested within **ScrollViewer** to support navigating to different views while supporting the back button (see below).

    === "XAML"

        ```xml
        <Page>
            <Grid>
                <NavigationView>
                    <ScrollViewer>
                        <Frame x:Name="ContentFrame"/>
                    </ScrollViewer>
                </NavigationView>
            </Grid>
        </Page>
        ```

    === "Code-behind"

        ```csharp
        private void Navigation_ItemInvoked(NavigationView sender, NavigationViewItemInvokedArgs args)
        {
            ContentFrame.Navigate(typeof(Page1));
        }
        ```

#### Page
:   
    The **Page** element in [UWP](#uwp) is equivalent to `Window` in WPF.

    Page elements can only accept a single Content sub-element, necessitating the use of a [layout panel](#layout) like [Grid](#grid), [StackPanel](#stackpanel), etc.



#### RelativePanel
:   
    **RelativePanel** allows children to declare attributes (e.g. `RelativePanel.RightOf` ) to specify position relative to the `x:Name` of other children. This is useful in building responsive layouts.

    Supports several attached properties that allow elements to be aligned with siblings or with the panel itself.

    - **Panel alignment relations** like `AlignLeftWithPanel`, `AlignTopWithPanel`, `AlignRightWithPanel`, `AlignBottomWithPanel`,  align controls to the border of the RelativePanel containing them.
    - **Sibling alignment relationships** like `AlignLeftWith`, `AlignTopWith`, `AlignVerticalCenterWith` etc. specify the name of a sibling control to provide alignment.
    - **Sibling positional relations** like `LeftOf`, `Above`, `RightOf`, and `Below` also specify a sibling control.

#### ResourceDictionary
:   
    [**Resource dictionaries**]()

    Here, [Buttons](#button) will now be able to be styled using a [ markup extension ](Markup-extensions)
    ```xml
    <Button Style="{StaticResource SubmitButton}" Content="Submit"/>
    ```

    === "App.xaml"

        ```xml
        <Application>
            <Application.Resources>
                <ResourceDictionary Source="ResourceDictionaries/ButtonDictionary.xaml"/>
            </Application.Resources>
        </Application>
        ```

    === "/ResourceDictionaries/ButtonDictionary.xaml"

        ```xml
        <ResourceDictionary>
            <Style TargetType="Button" x:Key="SubmitButton">
                <Setter Property="Background" Value="Green"/>
                <Setter Property="Padding" Value="5"/>
            </Style>
        </ResourceDictionary>
        ```


    Managing a consistent style will typically necessitate using multiple resource dictionaries.
    But some elements can only contain a single ResourceDictionary element.

    The solution is to place a **ResourceDictionary.MergedDictionaries** property element within the outermost `ResourceDictionary`.
    Multiple `ResourceDictionary` objects can be placed as children of it.

    ```xml
    <Page>
        <Page.Resources>
            <ResourceDictionary>
                <ResourceDictionary.MergedDictionaries>
                    <ResourceDictionary Source="Dictionary1.xaml" />
                    <ResourceDictionary Source="Dictionary2.xaml" />
                </ResourceDictionary.MergedDictionaries>
            </ResourceDictionary>
        </Page.Resources>
    </Page>
    ```

    Sources

    - :material-file-document-multiple-outline: [ResourceDictionary](https://docs.microsoft.com/en-us/uwp/api/Windows.UI.Xaml.ResourceDictionary)
    - :octicons-play-24: [YouTube](https://www.youtube.com/watch?v=Y9hElE-vx34 "XAML WPF - Styles Part 3, Resource Dictionaries")

#### SplitView
:   
    [**SplitView**](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.splitview?view=winrt-19041) can be used to implement hamburger-style navigation.
    SplitView has two attributes into which controls can be placed, `Pane` and `Content`. Pane is not displayed by default.
    However, by setting the SplitView instance's `IsPaneOpen` attribute to True it can be displayed.

    The `DisplayMode` attribute controls how the Pane interacts with Content with opened:

    - **Overlay**: Pane covers up Content
    - **Inline**: Pane pushes Content to the right.
    - **CompactInline**: Where Pane will fit Pane elements closely, if `CompactPaneLength` is not specified
    - **CompactOverley**: Pane's dimensions can be specified using `CompactPaneLength` and `OpenPaneLength`

#### StackPanel
:   
    The [**StackPanel**](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.stackpanel?view=winrt-22000) layout panel in XAML is similar in function to the **pack()** geometry manager in tkinter, although its default behavior appears to horizontally center elements and stack them vertically.

    Notably, StackPanel does not support scroll bars. ([src](https://app.pluralsight.com/course-player?clipId=9600c619-e37a-445b-890e-d9da71d048cf))

#### TabView
:   
    ![](/img/xaml-tabview.png)

#### Textbox
:   
    === "XAML"

        ```xml
        <Window
            x:Class="EmployeeManager.WinUI.MainWindow"
            xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
            xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
            xmlns:local="using:EmployeeManager.WinUI"
            xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
            xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
            mc:Ignorable="d">
            
            <TextBox Header="First name"/>
        </Window>
        ```

    === "tkinter"

        ```python
        import tkinter as tk
        from tkinter.ttk import Entry
        from tkinter.ttk import LabelFrame

        win = tk.Tk()
        frame=LabelFrame(win, text="First name")
        frame.pack()
        Entry(frame).pack()
        tk.mainloop()
        ```


#### VariableSizedWrapGrid
:   
    **VariableSizedWrapGrid** can be used to define a field of tiles similar to an HTML flex container (`display: flex;` with `flex-wrap: wrap;`). The `Orientation` property is similar to a flex container's `flex-direction`, in that the direction of alignment can be specified.

    <details>
    <summary><img src="/img/GUI-VariableSizedWrapGrid.gif"/></summary>
    ```xml
    <Page>
        <VariableSizedWrapGrid Orientation="Horizontal" ItemWidth="100" ItemHeight="100">
            <Rectangle Fill="LightGray"/>
            <Rectangle Fill="LightSteelBlue" />
            <Rectangle Fill="LightBlue" />
            <Rectangle Fill="LightCyan" />
            <Rectangle Fill="LightSeaGreen" />
            <Rectangle Fill="LightGreen" />
            <Rectangle Fill="LightGoldenrodYellow"  />
            <Rectangle Fill="LightSalmon" />
            <Rectangle Fill="LightCoral" />
            <Rectangle Fill="Gray"/>
            <Rectangle Fill="SteelBlue" />
            <Rectangle Fill="CadetBlue" />
            <Rectangle Fill="Cyan" />
            <Rectangle Fill="SeaGreen" />
            <Rectangle Fill="Green" />
            <Rectangle Fill="Goldenrod"  />
            <Rectangle Fill="Salmon" />
            <Rectangle Fill="Coral" />
        </VariableSizedWrapGrid>
    </Page>
    ```
    </details>

    Notably, the horizontal or vertical alignment of XAML controls is defined on each control, whereas in HTML alignment is specified at the level of the enclosing container.

    === "XAML"
        ```xml
        <TextBlock Content="Hello, world!" HorizontalAlignment="Left" VerticalAlignment="Top"/>
        ```

    === "HTML and CSS"
        ```pug
        .container
            p Hello, world!
        ```
        ```css
        .container {
            text-align: right top;
        }
        ```
