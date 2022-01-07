# WinUI

## Syntax

Every XAML **element** maps to a C# **class**, and every XAML **attribute** maps to a class **property** or an [ **event** ](#event-handling). 

There are [several syntaxes](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/xaml-syntax-guide "XAML syntax guide") available for use that correspond to various methods of declaring objects:

- **Object-element syntax** has the type's name within angle brackets, similar to HTML.
When the object contains other objects, it is called a **container**.
If the object does not contain other objects, it can be declared with a self-closing tag:
- **Attribute syntax** has the property value set by declaring an attribute.
- In **property-element syntax**, signified by a period in the element name, where the portion of the element following the dot representing the identifier of the property.
- **Content-property syntax** is similar to the property element syntax in that a property's value is set by a child. 
However, in this case the XAML processor interpolates the correct property element, typically Content. 
Some controls can accept more than one child element. In the background, this is actually using the **content-property syntax** to assign to the `Children` property.

=== "Object-element"

    ```xml
    <Canvas>
        <Rectangle />
    </Canvas>
    ```

=== "Attribute"

    ```xml
    <Rectangle Name="rectangle1" Width="100" Height="100" Fill="Blue" />
    ```
    
=== "Property-element"

    ```xml
    <Rectangle Name="rectangle1" Width="100" Height="100"> 
        <Rectangle.Fill> 
            <SolidColorBrush Color="Blue"/> 
        </Rectangle.Fill>
    </Rectangle>
    ```

=== "Content-property"

    ```xml
    <Button>
        Add customer
    </Button>
    ```

=== "Multiple children"

    ```xml
    <StackPanel>
        <TextBlock>Hello</TextBlock>
        <TextBlock>World</TextBlock>
    </StackPanel>
    ```


### Namespaces

A XAML file usually declares a **default XAML namespace** in its root element.
This default namespace defines elements that can be declared without qualifying them by a prefix (e.g. `x:`).

XAML namespaces apply only to the specific element on which they are declared and its children, which explains why they are typically placed on the root element.
([src](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/xaml-namespaces-and-namespace-mapping "XAML namespaces and namespace mappings"))

Most XAML files have two `xmlns` declarations

- **xmlns** maps a default XAML namespace
- **xmlns:x** maps a separate XAML namespace for XAML-defined **language elements** to the `x:` prefix:
- **xmlns:mc** indicates and supports a markup compatibility mode for reading XAML.
```xml
xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
mc:Ignorable="d"
```
### Directives

- [**x:Name**](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/x-name-attribute "x:Name attribute") uniquely identifies object elements for access to the object from code-behind 
- [**x:Key**](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/x-key-attribute "x:Key attribute") sets a unique key for each resource in a **ResourceDictionary** 
- [**x:Class**](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/x-key-attribute) specifies the CLR namespace and class name for the class that provides code-behind 
for a XAML page. The `x:Class` directive configures XAML markup compilation to join partial classes 
between markup and code-behind. In this example it can be seen how it refers to the `MainPage` 
class within the `Project` namespace. ([src](https://app.pluralsight.com/course-player?clipId=392e67d1-49ec-4c5c-987a-cd83ff56623b))
- [**x:Bind**](#data-binding) is a form of [data-binding](#data-binding)



**Language elements** are commonly used features necessary for Windows Runtime apps.
For example, to join any code-behind to a XAML file through a partial class, you must name that class as the `x:Class` attribute in the root element of the XAML file.

=== "XAML"

    ```xml
    <Page x:Class="Project.MainPage"/>
    ```

=== "Code-behind"

    ```csharp
    namespace Project
    {
        public sealed partial class MainPage : Page
        {
            public MainPage()
            {
                this.InitializeComponent();
            }
        }
    }
    ```


### Attached property

Attached properties can be modified or queried in C# code as well, as long as the XAML element has an **x:Name** defined, which gives that particular element an identifier.
For the column property of `Grid`, the static methods `GetColumn` and `SetColumn` are available.

Here a button press changes the column value of an enclosing Grid and toggles between two different [`Symbol`](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.controls.symbol?view=winrt-19041) values. ([src](https://app.pluralsight.com/course-player?clipId=8e0d702e-1b6c-40ee-a3e6-5c999e2f9659))


```csharp
private void ButtonMove_Click(object sender, RoutedEventArgs e)
{
    int column = Grid.GetColumn(customerListGrid);
    int newcolumn = column == 0 ? 2 : 0;
    Grid.SetColumn(customerListGrid, newcolumn);
    moveSymbolIcon.Symbol = newcolumn == 0 ? Symbol.Forward : Symbol.Back;
}
```



### Event handling

Event hooks can be used to subscribe to events.
For example, the `MainPage` class exposes a `Loaded` event that can be used to fill a prototype app with dogfood data, rather than putting hardcoding it in the XAML markup.
Notably, these event handlers must return only `void` types.

```c#
public sealed partial class MainPage : Page
{
    public MainPage()
    {
        this.InitializeComponent();
        this.Loaded += MainPage_Loaded;
    }

    private void MainPage_Loaded(object sender, RoutedEventArgs e)
    {
        throw new NotImplementedException();
    }
}
```

Some XAML controls have attributes that map to events:

| Element                 | Property               |
| ----------------------- | ---------------------- |
| `Button`                | `Click`                |
| `CheckBox`              | `Checked`, `Unchecked` |
| [`ListView`](#listview) | `SelectionChanged`     |
| [`TextBox`](#textbox)   | `TextChanged`          |

Defining an event handler in XAML is equivalent to doing so in C#.

=== "XAML"

    ```xml
    <Button Content="Add customer" Click="Button_ClickHandler">
    ```

=== "C#"

    ```csharp
    var btn = new Button 
    { 
        Content = "Add customer"
        this.Click = // No clue if this is right...
    };
    ```

-----

=== "SelectionChanged"

    === "Markup"

        ```xml
        <ListView 
            x:Name="customerListView" 
            SelectionChanged="CustomerListView_SelectionChanged"/>
        ```

    === "Code-behind"

        ```csharp
        private void CustomerListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var customer = customerListView.SelectedItem as Customer;
            txtFirstName.Text = customer?.FirstName ?? ""; 
            txtLastName.Text = customer?.LastName ?? "";
            chkIsDeveloper.IsChecked = customer?.IsDeveloper;
        }
        ```

=== "TextChanged"

    === "Markup"

        ```xml
        <StackPanel>
            <TextBox 
                x:Name="txtFirstName" 
                Header="Firstname" 
                TextChanged="TextBox_TextChanged"
                Margin="10" />
            <TextBox 
                x:Name="txtLastName" 
                Header="Lastname" 
                TextChanged="TextBox_TextChanged"
                Margin="10" />
            <CheckBox 
                x:Name="chkIsDeveloper"
                Content="IsDeveloper" 
                Margin="10" 
                Checked="CheckBox_IsCheckedChanged" 
                Unchecked="CheckBox_IsCheckedChanged"/>
        </StackPanel>
        ```

    === "Code-behind"

        ```csharp
        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            UpdateCustomer();
        }

        private void CheckBox_IsCheckedChanged(object sender, RoutedEventArgs e)
        {
            UpdateCustomer();
        }

        private void UpdateCustomer()
        {
            var customer = customerListView.SelectedItem as Customer;
            if (customer != null)
            {
                customer.FirstName = txtFirstName.Text;
                customer.LastName = txtLastName.Text;
                customer.IsDeveloper = chkIsDeveloper.IsChecked.{{c4::GetValueOrDefault}}();
            }
        }
        ```

Handlers for Loaded and Unloaded are automatically attached to any [Page](#page) that uses the `NavigationHelper` class.

- [Loaded](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.frameworkelement.loaded?view=winrt-19041)
- [Unloaded](https://docs.microsoft.com/en-us/uwp/api/windows.ui.xaml.frameworkelement.unloaded?view=winrt-19041)


### Custom controls

You can take a group of controls and create a [custom control](https://docs.microsoft.com/en-us/archive/msdn-magazine/2019/may/xaml-custom-xaml-controls) using what is called a **namespace mapping**, where a C# class is made available in the XAML markup.

More specifically, a custom control defined in XAML along with its accompanying code-behind file must use `UserControl` as its base class.
In this sense, a custom control is really a special case of a namespace mapping, which can also be used to populate an application with mock data during development.

=== "Markup"

    ```xml
    <UserControl
        x:Class="Project.Controls.CustomControl"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="using:WiredBrainCoffee.UWP.Controls"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        mc:Ignorable="d">

        <TextBlock Text="Hello, world!"/>
    </UserControl>
    ```

=== "Code-behind"

    ```csharp
    namespace Project.Controls
    {
        public sealed partial class CustomControl : UserControl
        {
            public CustomControl()
            {
                this.InitializeComponent();
            }
        }
    }
    ```

### Mock data

The most basic method of adding mock data is by **hardcoding data in the XAML markup**.

Somewhat more sophisticated is the option of **hardcoding data in the code-behind**.
The `x:Bind` directive can be used to bind an `IEnumerable` data source to either the `Items` or `ItemsSource` attributes.
An **ObservableCollection<T>** is preferred in WinUI programming because it raises events when properties are changed, but Lists and Arrays also work. 
If the collection is made of objects, the `DisplayMemberPath` allows the specification of a particular property on those objects to be displayed.
Notably, **classes** specifically need to be used, and not structs, for the members of these collections.

With **namespace mapping**, classes within the C# namespace can be used in XAML markup. ([src](https://app.pluralsight.com/course-player?clipId=67d02b8e-5dd4-4be1-8c3d-d89476e4448a))

Most robust of all is creating a Data Provider class which will fall back to mock data when the data source is not available. 
This will allow any number of other data sources to be plugged in, such as databases or REST services. ([src](https://app.pluralsight.com/course-player?clipId=769d2e57-0e51-45f1-960b-781509f5719b))

=== "Hardcoding in XAML"
    ```xml
    <ListView>
        <ListViewItem>Aristotle</ListViewItem>
        <ListViewItem>Euclid</ListViewItem>
        <ListViewItem>Plato</ListViewItem>
        <ListViewItem>Socrates</ListViewItem>
    </ListView>
    ```

=== "Hardcoding in C#"

    === "Markup"

        ```xml
        <Page>


            <ListView
                ItemsSource="{x:Bind Starships}" 
                SelectedItem="{x:Bind Starships[0]}"
                DisplayMemberPath="Display"/>
        </Page>
        ```

    === "Code-behind"    

        ```csharp
        namespace Starships.Models
        {
            class Starship
            {
                public string Name;
                public string Registry;
                public int Crew;
                public string Display
                {
                    get { return Name + Registry; }
                }            
            }
        }
        ```

=== "Namespace mapping"

    === "Markup"

        ```xml
        <Page 
            xmlns:model="using:Project.Models">
            
            <ListView DisplayMemberPath="Display">
                <model:Starship Name="USS Enterprise" Registry="NCC-1701" Crew="140"/>
            </ListView>
        </Page>
        ```

    === "Code-behind"

        ```csharp
        namespace Starships.Models
        {
            class Starship
            {
                public string Name;
                public string Registry;
                public int Crew;
                public string Display
                {
                    get { return Name + Registry; }
                }
            }
        }
        ```



=== "Data provider"


---

### Themes

Windows 10 [themes](https://docs.microsoft.com/en-us/windows/uwp/design/controls-and-patterns/xaml-theme-resources "XAML theme resources") ([ "Light" ](#light-theme), [ "Dark" ](#dark-theme), and "HighContrast" can be specified as a property of the 
Application element:

=== "Light"
    ![](/img/GUI-WBC-01-Light.gif)
    ```xml
    <Application
        x:Class="Scratchpad.App"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="using:Scratchpad"
        RequestedTheme="Light">
        <Application.Resources>
            <ResourceDictionary>
                <ResourceDictionary.MergedDictionaries>
                    <XamlControlsResources xmlns="using:Microsoft.UI.Xaml.Controls" />
                    <!-- Other merged dictionaries here -->
                </ResourceDictionary.MergedDictionaries>
                <!-- Other app resources here -->
            </ResourceDictionary>
        </Application.Resources>
    </Application>
    ```
=== "Dark"
    ![](/img/GUI-WBC-01.gif)
    ```xml
    <Application
        x:Class="Scratchpad.App"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="using:Scratchpad"
        RequestedTheme="Dark">
        <Application.Resources>
            <ResourceDictionary>
                <ResourceDictionary.MergedDictionaries>
                    <XamlControlsResources xmlns="using:Microsoft.UI.Xaml.Controls" />
                    <!-- Other merged dictionaries here -->
                </ResourceDictionary.MergedDictionaries>
                <!-- Other app resources here -->
            </ResourceDictionary>
        </Application.Resources>
    </Application>
    ```
=== "Theme colors"
    ![](/img/light-base.png)
    ![](/img/light-alt.png)
    ![](/img/light-chrome.png)
    ![](/img/light-list.png)
    ![](/img/dark-base.png)
    ![](/img/dark-alt.png)
    ![](/img/dark-chrome.png)
    ![](/img/dark-list.png)


### Layout

The **layout panels** in XAML serve a similar function to the geometry manager methods in tkinter. 
There are [various](https://docs.microsoft.com/en-us/windows/uwp/design/layout/layouts-with-xaml#layout-panels) layout panels available.

- [Grid](#grid)
- [RelativePanel](#relativepanel)
- [StackPanel](#stackpanel)
- [VariableSizeWrapGrid](#variablesizedwrapgrid)




### Data binding

There are two data binding types available in XAML ([src](https://app.pluralsight.com/course-player?clipId=5cfb0a48-8455-4217-a83e-f93fc4aa5c24))

- [**Binding markup extension**](https://docs.microsoft.com/en-us/dotnet/desktop/wpf/advanced/binding-markup-extension?view=netframeworkdesktop-4.8) resolves the binding path at runtime. It can accept data sources from the **binding properties**
`ElementName`, `Source`, and `RelativeSource`.
If none of these are defined, then the binding markup extension resolves to the DataContext property.
- [**x:Bind**](https://docs.microsoft.com/en-us/windows/uwp/xaml-platform/x-bind-markup-extension) resolves the binding path at **compile-time**, generating C# code and offering better performance and compile-time errors. You can also step into the compiled code, providing a better debugging experience. `x:Bind` should generally be preferred, however it is available only in UWP.


`x:Bind`, in contrast, binds only to the parent `Page` or `UserControl` element. So any property of MainPage will be accessible, and any property of that object will also be accessible using dot notation.

Most bindings are easily translated between the two types:

=== "Binding markup extension"

    ```csharp
    public MainPage()
    {
        this.InitializeComponent;
        this.ViewModel = new MainViewModel();
        DataContext = ViewModel;
    }
    ```
    ```xml
    <ListView
        ItemsSource="{Binding Customers,Mode=OneWay}">
        <!-- ...-->
    </ListView>
    ```

=== "x:Bind"

    ```csharp
    public MainPage()
    {
        this.InitializeComponent;
        this.ViewModel = new MainViewModel();
        // DataContext = ViewModel;
    }
    ```
    ```xml
    <ListView
        ItemsSource="{x:Bind ViewModel.Customers,Mode=OneWay}">
        <!-- ...-->
    </ListView>
    ```

Notably, the default binding mode of the binding markup extension is **OneWay`**, whereas that of `x:Bind` is **`OneTime**, although this can be changed by setting `x:DefaultBindMode` on the root element.

=== "Changing default bind mode"

    ```xml
    <Page
        x:DefaultBindMode="OneWay">
        <Listview ItemsSource="{x:Bind ViewModelCustomers}"/>
    </Page>
    ```

=== "Set explicitly"

    ```xml
    <Page>
        <Listview ItemsSource="{x:Bind ViewModelCustomers,Mode=OneWay}"/>
    </Page>
    ```

### Type conversion

By default, XAML attribute values are strings. In order for the XAML processor to interpret them
as objects, they must be converted.

**Type converters** can convert string representations of attribute values to property elements.
For example, a type converter is what is used with the XAML declaration `HorizontalAlignment="Left"`, 
which is mapped to a specific enumeration within the **Windows.UI.XAML** namespace.
<sup>[ref](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/typeconverters-and-xaml "TypeConverters and XAML")</sup>

In UWP, the XAML processor integrates the conversion logic to convert the Margin declaration to a `Thickness` object. 
But in [ WPF ](WPF), TypeConverters are used.

=== "Markup"

    ```xml
    <Button Margin="10,20,10,30" Content="Click me"/>
    ```

=== "Code-behind"

    ```cs
    var btn = new Button
    {
        Margin = new Thickness(10, 20, 10, 30);
    };
    ```


### Markup Extensions

**Markup extensions** are placed between curly braces `{` and `}` and create a reference to a 
[ **ResourceDictionary** ](Resource-dictionaries).  They can be used to unify styling across an 
application.

The most common markup extensions are:

- `StaticResource` refers to resources defined in [ resource dictionaries ](#resourcedictionary)
- `ThemeResource` for Windows native themeing [colors](#themes)
- `Binding` for data binding expressions, which require the bound property to be a [dependency property](#dependency-properties)

Here, the background of the grid is bound to a color from the Windows-native theming
and the TextBlock's Foreground property is bound to a color defined in a resource dictionary
defined on the same page.

Multiple properties can be set at the same time by setting a `Style` property element.
```xml
<Page>
    <Page.Resources>
        <Style TargetType="Button" x:Key="MyButtonStyle">
            <Setter Property="Background" Value="Blue"/>
            <Setter Property="FontFamily" Value="Arial Black"/>
            <Setter Property="FontSize" Value="36"/>
        </Style>
    </Page.Resources>

    <Button Content="Hello world" Style="{StaticResource MyButtonStyle}"/>
</Page>
```


```xml
<Page>
    <Page.Resources>
            <SolidColorBrush x:Key="MyBrush" Color="Brown" />
    </Page.Resources>

    <Grid Background="{ThemeResource ApplicationPageBackgroundThemeBrush}">
        <TextBlock Text="Hello World" Foreground="{StaticResource MyBrush}" />
    </Grid>
</Page>
```

[src](https://channel9.msdn.com/Series/Windows-10-development-for-absolute-beginners/UWP-028-XAML-Styles "UWP course - XAML Styles")




### Dependency properties

Only [dependency properties](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/dependency-properties-overview) can be targets for data binding in [UWP](UWP) and [WPF](WPF).
The **propdp** snippet in Visual Studio can be used to create one.

The **DependencyObject** class, which is a base class of all UI elements in UWP and WPF, exposes the `GetValue` and `SetValue` methods, which are used to ...


### Multi-instance

A **multi-instance** application is one that can run in several instances, which is necessary to allow users to open new windows.

A collection of templates is available as a Visual Studio [extension](https://marketplace.visualstudio.com/items?itemName=AndrewWhitechapelMSFT.MultiInstanceApps).
These templates modify the appxmanifest file by setting the **SupportsMultipleInstances** attribute to true:

```xml
<Package
  ...
  xmlns:desktop4="http://schemas.microsoft.com/appx/manifest/desktop/windows10/4"
  xmlns:iot2="http://schemas.microsoft.com/appx/manifest/iot/windows10/2"  
  IgnorableNamespaces="uap mp desktop4 iot2">
  ...
  <Applications>
    <Application Id="App"
      ...
      desktop4:SupportsMultipleInstances="true"
	  iot2:SupportsMultipleInstances="true">
      ...
    </Application>
  </Applications>
   ...
</Package>
```

Resources:

- :material-file-document-multiple-outline: [Create a multi-instance UWP app](https://docs.microsoft.com/en-us/windows/uwp/launch-resume/multi-instance-uwp)


## Patterns

### Action on focus

UI elements expose the **GotFocus** event hook for when a user clicks or tabs into a control.

Example handler selecting all text in a TextBox: ([src](https://asp-net-example.blogspot.com/2016/12/uwp-select-textbox-all-text-when-get.html))

=== "Markup"

    ```xml
    <Page>
        <TextBox GotFocus="TextBox_GotFocus"/>
    </Page>
    ```

=== "Code-behind"

    ```csharp
    void TextBox_GotFocus(object sender, RoutedEventArgs e)
    {
        TextBox textBox = sender as TextBox;
        textBox.SelectAll();
    }
    ```

### List/Details

<figure><img src="/img/GUI/list-detail-pattern.png"/></figure>

The [**list/details pattern**](https://docs.microsoft.com/en-us/windows/uwp/design/controls-and-patterns/master-details) has a master pane (usually a [ListView](#listview)) and a details pane for content.

### MVVM

In the **Model, View, ViewModel (MVVM)** pattern, which implicitly relies on OOP principles, the **Model** represents the data model for the objects being manipulated, 
and the **ViewModel** is the model for the **View**, that is, the state of the application as represented in a class.

In WinUI, the project that contains the Views (that is, the XAML files) must first add references to the projects where the Models and ViewModel are contained. 
These will allow the code-behind file of the **MainWindow** to reference those classes.

The class representing the ViewModel is instantiated and assigned to an attribute.
That class's methods can then be called by using the `x:Bind` attribute syntax on, for instance, a `ListView` element.

=== "Markup"
    ```xml
    <Window>
        <ListView 
            ItemsSource="{x:Bind ViewModel.Employees, Mode=OneWay}"
            SelectedItem="{x:Bind ViewModel.SelectedEmployee, Mode=OneWay}"
            DisplayMemberPath="FirstName"/>
    </Window>
    ```

=== "Code-behind"

    ```csharp
    using EmployeeManager.DataAccess;
    using EmployeeManager.ViewModel;
    using Microsoft.UI.Xaml;

    namespace EmployeeManager.WinUI
    {
        public sealed partial class MainWindow : Window
        {
            public MainWindow()
            {
                ViewModel = new MainViewModel(new EmployeeDataProvider());
                this.InitializeComponent();
            }

            public MainViewModel ViewModel { get; }
        }
    }
    ```

### Navigation

App layout typically begins with the choice of **navigation model**, which defines how users navigate between pages in the app.
There are two common navigation models: **left nav** and **top nav**

![](/img/xaml-nav.svg)

## Examples

### List and details

<details>
<summary><img src="/img/GUI-Heroes.gif"></summary>

```xml
<Page
    x:Class="Superheroes.MainPage"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:Superheroes"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d"
    Background="{ThemeResource ApplicationPageBackgroundThemeBrush}">

    <StackPanel>
        <CommandBar>
            <AppBarButton x:Name="AddHero" Click="AddHero_Click" Label="Add hero">
                <SymbolIcon Symbol="Add"/>
            </AppBarButton>
            <AppBarButton x:Name="DelHero" Click="DelHero_Click" Label="Remove hero">
                <SymbolIcon Symbol="Delete"/>
            </AppBarButton>
        </CommandBar>

        <TextBox Header="First name" Text="{Binding ElementName=heroesListView,Path=SelectedItem.FirstName,Mode=TwoWay}"/>
        <TextBox Header="Last name" Text="{Binding ElementName=heroesListView,Path=SelectedItem.LastName,Mode=TwoWay}"/>
        <TextBox Header="Alias" Text="{Binding ElementName=heroesListView,Path=SelectedItem.Superhero,Mode=TwoWay}"/>
        
        <ListView 
            x:Name="heroesListView" 
            ItemsSource="{Binding Heroes,Mode=TwoWay}" 
            SelectedItem="{Binding SelectedHero,Mode=TwoWay}">
            
            <ListView.ItemTemplate>
                <DataTemplate>
                    <StackPanel Orientation="Horizontal">
                        <TextBlock Text="{Binding Superhero}" FontWeight="Bold"/>
                        <TextBlock Text="{Binding FirstName}" Margin="5 0 0 0"/>
                        <TextBlock Text="{Binding LastName}" Margin="5 0 0 0"/>
                    </StackPanel>
                </DataTemplate>
            </ListView.ItemTemplate>
        </ListView>
        
    </StackPanel>
</Page>
```
</details>

In order to link two controls, some form of [data binding](#data-binding) is necessary.
Here, TextBox elements are individually bound to the string properties of the selected ListView element with the Binding markup extension using the `ElementName` binding property.
The selected item and the path to the string property are combined using dot notation and assigned to the `Path` binding property. 


#### Custom control

The textboxes can also be consolidated into a custom control using **UserControl**. 
In this case, the custom control must expose a target property that will be bound to the ListView's SelectedItem property. 


=== "Individual TextBoxes bound to ListView"

    ```xml
    <TextBox Header="First name" Text="{Binding ElementName=heroesListView,Path=SelectedItem.FirstName,Mode=TwoWay}"/>
    <TextBox Header="Last name" Text="{Binding ElementName=heroesListView,Path=SelectedItem.LastName,Mode=TwoWay}"/>
    <TextBox Header="Alias" Text="{Binding ElementName=heroesListView,Path=SelectedItem.Superhero,Mode=TwoWay}"/>

    <!-- <local:MyTextBoxes Hero="{Binding ElementName=heroesListView,Path=SelectedItem,Mode=TwoWay}"/> -->
    ```

=== "UserControl"

    ```xml
    <!--<TextBox Header="First name" Text="{Binding ElementName=heroesListView,Path=SelectedItem.FirstName,Mode=TwoWay}"/>
    <TextBox Header="Last name" Text="{Binding ElementName=heroesListView,Path=SelectedItem.LastName,Mode=TwoWay}"/>
    <TextBox Header="Alias" Text="{Binding ElementName=heroesListView,Path=SelectedItem.Superhero,Mode=TwoWay}"/>-->

    <local:MyTextBoxes Hero="{Binding ElementName=heroesListView,Path=SelectedItem,Mode=TwoWay}"/>
    ```

In order to accept the data binding, the target property must be implemented as a [**dependency property**](#dependency-properties).
This dependency property works through a static callback function which sets the individual textbox values to the bound target property.

Naively, the callback function can be made to change the individual TextBox elements, provided they have `x:Name` defined.
But a better technique is using the Binding markup extension to bind the individual TextBoxes to the root node using the `ElementName` binding property.
This requires the root node to have `x:Name` defined.

Both MyTextBoxes's binding to heroesListView and the individual TextBox bindings to the Hero property of root need to be TwoWay in order for changes made in the TextBox to take effect.
Notably, the ListView does not reflect any changes made yet.

=== "Callback"

    ```xml
    <TextBox 
        x:Name="FirstNameTextbox"
        Header="First name" 
        Margin="10"
        />
    <TextBox 
        x:Name="LastNameTextbox"
        Header="Last name" 
        Margin="10"
        />
    <TextBox 
        x:Name="SuperheroTextbox"
        Header="Alias" 
        Margin="10"
        />
    ```

    ```csharp
    private static void HeroChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
    {
        if (d is MyTextBoxes myTextBoxes)
        {
        var hero = e.NewValue as Hero;

        myTextBoxes.FirstNameTextbox.Text = hero.FirstName;
        myTextBoxes.LastNameTextbox.Text = hero.LastName;
        myTextBoxes.SuperheroTextbox.Text = hero.Superhero;
        }
    }
    ```

=== "Binding"

    ```xml
    <TextBox 
        x:Name="FirstNameTextbox"
        Header="First name" 
        Margin="10"
        Text="{Binding ElementName=root,Path=Hero.FirstName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"/>
    <TextBox 
        x:Name="LastNameTextbox"
        Header="Last name" 
        Margin="10"
        Text="{Binding ElementName=root,Path=Hero.LastName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"/>
    <TextBox 
        x:Name="SuperheroTextbox"
        Header="Alias" 
        Margin="10"
        Text="{Binding ElementName=root,Path=Hero.Superhero,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"/>
    ```

    ```csharp
    private static void HeroChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
    {
        //if (d is MyTextBoxes myTextBoxes)
        //{
        //    var hero = e.NewValue as Hero;

        //    myTextBoxes.FirstNameTextbox.Text = hero.FirstName;
        //    myTextBoxes.LastNameTextbox.Text = hero.LastName;
        //    myTextBoxes.SuperheroTextbox.Text = hero.Superhero;
        //}
    }
    ```

#### ListView

In order for the ListView to update, the **underlying model** must raise the **PropertyChanged** event.
I really don't understand this very well, so here is the Observable class that implements the **INotifyPropertyChanged** interface.
The model must inherit from this base class and the Set accessor of any property should fire `OnPropertyChanged()`.

```csharp
public class Observable : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;
    protected void OnPropertyChanged([CallerMemberName] string propertyName = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }
}
```

#### ViewModel

#### x:Bind

Binding markup extensions are trivially changed to [compiled data bindings](#data-binding) by replacing `Binding` with `x:Bind`.

!!!
    Note that ListView will enter an infinite loop if the SelectedHero property does not incorporate additional logic.

    ```csharp
    public Hero SelectedHero
    {
        get { return _selectedHero; }
        set
        {
            if (_selectedHero != value)
            {
                _selectedHero = value;
                OnPropertyChanged();
                OnPropertyChanged(nameof(IsHeroSelected));
            }
        }
    }
    ```

=== "Binding markup extension"
    ```xml
    <ListView 
        x:Name="heroesListView" 
        ItemsSource="{Binding Heroes,Mode=OneWay}" 
        SelectedItem="{Binding SelectedHero,Mode=TwoWay}"
        Margin="0">
    ```
    ```xml
    <TextBox 
        x:Name="FirstNameTextbox"
        Header="First name" 
        Margin="10"
        Text="{Binding ElementName=root,Path=Hero.FirstName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
        GotFocus="Textbox_GotFocus"
        />
    <TextBox 
        x:Name="LastNameTextbox"
        Header="Last name" 
        Margin="10"
        Text="{Binding ElementName=root,Path=Hero.LastName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
        GotFocus="Textbox_GotFocus"
        />
    <TextBox 
        x:Name="SuperheroTextbox"
        Header="Alias" 
        Margin="10"
        Text="{Binding ElementName=root,Path=Hero.Superhero,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
        GotFocus="Textbox_GotFocus"
        />
    ```

=== "Compiled data binding"
    ```xml
    <ListView 
        x:Name="heroesListView" 
        ItemsSource="{x:Bind ViewModel.Heroes,Mode=OneWay}" 
        SelectedItem="{x:Bind ViewModel.SelectedHero,Mode=TwoWay}"
        Margin="0">
    ```
    ```xml
    <TextBox 
        x:Name="FirstNameTextbox"
        Header="First name" 
        Margin="10"
        Text="{x:Bind Hero.FirstName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
        GotFocus="Textbox_GotFocus"
        />
    <TextBox 
        x:Name="LastNameTextbox"
        Header="Last name" 
        Margin="10"
        Text="{x:Bind Hero.LastName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
        GotFocus="Textbox_GotFocus"
        />
    <TextBox 
        x:Name="SuperheroTextbox"
        Header="Alias" 
        Margin="10"
        Text="{x:Bind Hero.Superhero,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
        GotFocus="Textbox_GotFocus"
        />
    ```

x:Bind can also be implemented in the ListView's ItemTemplate, so long as the **x:DataType** attribute is set on DataTemplate.
We must also remember to set the Mode binding property, since x:Bind's default is OneTime!

=== "Binding markup extension"

    ```xml
    <ListView.ItemTemplate>
        <DataTemplate>
            <StackPanel Orientation="Horizontal">
                <TextBlock Text="{Binding Superhero}" FontWeight="Bold"/>
                <TextBlock Text="{Binding FirstName}" Margin="5 0 0 0"/>
                <TextBlock Text="{Binding LastName}" Margin="5 0 0 0"/>
            </StackPanel>
        </DataTemplate>
    </ListView.ItemTemplate>
    ```

=== "Compiled data binding"

    ```xml
    <ListView.ItemTemplate>
        <DataTemplate x:DataType="local:Hero">
            <StackPanel Orientation="Horizontal">
                <TextBlock Text="{x:Bind Superhero}" FontWeight="Bold"/>
                <TextBlock Text="{x:Bind FirstName}" Margin="5 0 0 0"/>
                <TextBlock Text="{x:Bind LastName}" Margin="5 0 0 0"/>
            </StackPanel>
        </DataTemplate>
    </ListView.ItemTemplate>
    ```

x:Bind can also hide or reveal controls depending on boolean value.
A new boolean field is formed on the ViewModel.

```csharp
public class ViewModel
{
    public bool IsHeroSelected => SelectedHero != null;
}
```

=== "Before"

    ```xml
    <CommandBar>
        <AppBarButton x:Name="AddHero" Click="AddHero_Click" Label="Add hero">
            <SymbolIcon Symbol="Add"/>
        </AppBarButton>
        <AppBarButton 
            x:Name="DelHero" Click="DelHero_Click" Label="Remove hero" >

            <SymbolIcon Symbol="Delete"/>
        </AppBarButton>
    </CommandBar>
    ```

=== "After"

    ```xml
    <CommandBar>
        <AppBarButton x:Name="AddHero" Click="AddHero_Click" Label="Add hero">
            <SymbolIcon Symbol="Add"/>
        </AppBarButton>
        <AppBarButton 
            x:Name="DelHero" Click="DelHero_Click" Label="Remove hero" 
            IsEnabled="{x:Bind ViewModel.IsHeroSelected,Mode=OneWay}">
            <SymbolIcon Symbol="Delete"/>
        </AppBarButton>
    </CommandBar>
    ```

## History

Windows has a long history of introducing UI frameworks to facilitate the creation of GUI applications:

- **MFC** (1992) was based on Native C++
- **WinForms** (2002) was based on .NET Framework
- **WPF** (2006) was also based on .NET Framework
- [**UWP XAML**](#uwp) (2012) was based on C++ and .NET
- [**WinUI 2**](#winui) is a NuGet package containing controls and styles for UWP Apps, intended to decouple UWP applications from the latest version of Windows
- [**WinUI 3**](#winui) (2020) is meant to provide a UX framework for both Win32 and UWP applications

XAML is a declarative markup language used to create UIs for .NET Core apps.
The logic of the app is separated in **code-behind** files that are joined to the markup through partial class definitions.
In Visual Studio this is emphasized by the fact that the code-behind file is literally presented as a child node of the XAML document.


The root element (of which there must be only one in order to be a valid XAML file) contains attributes 
that define the XAML [ namespaces ](#namespaces) for the program that will be parsing the XAML file, or a [ **namescope** ](https://docs.microsoft.com/en-us/dotnet/framework/wpf/advanced/wpf-xaml-namescopes).
