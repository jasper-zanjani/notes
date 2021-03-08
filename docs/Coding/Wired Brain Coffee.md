# ☕ Wired Brain Coffee

## Basic layout
![](/img/GUI-WBC-01.gif)

<details>
<summary>MainPage.xaml</summary>

```xml
<Window
    x:Class="WiredBrainCoffee.UWP.MainWindow"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d">

    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition/>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="350"/>
            <ColumnDefinition Width="*"/>
        </Grid.ColumnDefinitions>

        <Border Grid.ColumnSpan="2" Background="#f05a28">
            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center">
                <Image Height="90" Margin="5" Source="/Images/logo.png"/>
                <TextBlock Text="Employee Manager" FontSize="40" VerticalAlignment="Center"/>
            </StackPanel>
        </Border>

        <!-- Sidebar -->
        <Grid Grid.Row="1">
            <Grid.RowDefinitions>
                <RowDefinition Height="Auto"/>
                <RowDefinition />
            </Grid.RowDefinitions>

            <Button Content="Refresh" Margin="10"/>
            <ListView Grid.Row="1"/>
        </Grid>
        
        <!--MainArea-->
        <Grid Grid.Row="1" Grid.Column="1">
            <Grid.RowDefinitions>
                <RowDefinition Height="Auto"/>
                <RowDefinition Height="Auto"/>
                <RowDefinition Height="Auto"/>
                <RowDefinition Height="Auto"/> 
                <RowDefinition Height="*"/> 
            </Grid.RowDefinitions>

            <TextBox Header="Firstname" Margin="10"/>
            <DatePicker Grid.Row="1" Header="Entry date" Margin="10"/>
            <ComboBox Grid.Row="2" Header="Job role" Margin="10" HorizontalAlignment="Stretch"/>
            <CheckBox Grid.Row="3" Content="Is coffee drinker?" Margin="10"/>
            <Button Grid.Row="4" Content="Save" Margin="10 10 10 30"
                    VerticalAlignment="Bottom" HorizontalAlignment="Left"/>
        </Grid>
    </Grid>
</Window>
```
</details>

## Custom control

![](/img/GUI-WBC-01.jpg)

<details>
<summary>Controls/HeaderControl.xaml</summary>

```xml
<UserControl
    x:Class="WiredBrainCoffee.UWP.Controls.HeaderControl"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP.Controls"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d"
    d:DesignHeight="300"
    d:DesignWidth="400">

    <Border Background="#F05A28">
        <Grid>
            <Grid.ColumnDefinitions>
                <ColumnDefinition/>
                <ColumnDefinition Width="Auto"/>
            </Grid.ColumnDefinitions>

            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center">
                <Image Source="/Images/WiredBrainLogo.png" Height="90"/>
                <TextBlock Text="Wired Brain Coffee" FontSize="40" VerticalAlignment="Center"/>

            </StackPanel>
            <Button HorizontalAlignment="Right" Grid.Column="1" Margin="10">
                <SymbolIcon Symbol="AlignRight"/>
            </Button>

        </Grid>
    </Border>
</UserControl>
```
</details>

<details>
<summary>MainPage.xaml</summary>

```xml
<Page
    x:Class="WiredBrainCoffee.UWP.MainPage"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
    xmlns:controls="using:WiredBrainCoffee.UWP.Controls"
    mc:Ignorable="d"
    Background="{ThemeResource ApplicationPageBackgroundThemeBrush}">

    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition/>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="350"/>
            <ColumnDefinition/>
        </Grid.ColumnDefinitions>

        <!-- Header -->
        <controls:HeaderControl Grid.ColumnSpan="2"/>

        <!-- Sidebar -->
        <Grid Grid.Row="1">
            <Grid.RowDefinitions>
                <RowDefinition Height="Auto"/>
                <RowDefinition/>
            </Grid.RowDefinitions>
            <StackPanel Orientation="Horizontal">
                <Button Margin="10">
                    <SymbolIcon Symbol="AddFriend"/>
                </Button>
                <Button Margin="10">
                    <SymbolIcon Symbol="Delete"/>
                </Button>
            </StackPanel>
            <ListView Grid.Row="1">
                <ListViewItem>Aristotle</ListViewItem>
                <ListViewItem>Euclid</ListViewItem>
                <ListViewItem>Plato</ListViewItem>
                <ListViewItem>Socrates</ListViewItem>
            </ListView>
        </Grid>
        <StackPanel Grid.Row="1" Grid.Column="1">
            <TextBox Header="First name" Margin="10"/>
            <TextBox Header="Last name" Margin="10"/>
            <CheckBox Content="Drinks coffee" Margin="10"/>
        </StackPanel>
    </Grid>
</Page>
```
</details>

## Sidebar
![](/img/GUI-WBC-Sidebar.gif)

Setting an `x:Name` attribute on an element allows it to be manipulated in C#. ([src](https://app.pluralsight.com/course-player?clipId=8e0d702e-1b6c-40ee-a3e6-5c999e2f9659))

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
private void btn_MoveSideBar_Click(object sender, RoutedEventArgs e)
{
    int column = Grid.GetColumn(customerListGrid);
    int newcolumn;
    if (column == 0)
    {
        newcolumn = 2;
        btn_MoveSideBar_Symbol.Symbol = Symbol.AlignLeft;
    }
    else
    {
        newcolumn = 0;
        btn_MoveSideBar_Symbol.Symbol = Symbol.AlignRight;
    }
    Grid.SetColumn(customerListGrid, newcolumn);
}
```
</details>

## Data provider

A data provider class accomodates the need for [mock data](#mock-data) while also loosely coupling the data with the source. ([src](https://app.pluralsight.com/course-player?clipId=769d2e57-0e51-45f1-960b-781509f5719b))

<details>
<summary>DataProviders/CustomerDataProvider.cs</summary>

```csharp
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.IO;
using Windows.Storage;
using Windows.Storage.Streams;
using WiredBrainCoffee.UWP.Models;

namespace WiredBrainCoffee.UWP.DataProviders
{
    class CustomerDataProvider
    {
        private static readonly string _customersFileName = "customers.json";
        private static readonly StorageFolder _localFolder = ApplicationData.Current.LocalFolder;

        public async Task<IEnumerable<Customer>> LoadCustomersAsync()
        {
            var storageFile = await _localFolder.TryGetItemAsync(_customersFileName) as StorageFile;
            List<Customer> customerList = null;

            if (storageFile == null)
            {
                customerList = new List<Customer>
                {
                    new Customer{FirstName="Clark",LastName="Kent",IsCoffeeDrinker=true},
                    new Customer{FirstName="Bruce",LastName="Wayne",IsCoffeeDrinker=false},
                    new Customer{FirstName="Diana",LastName="Prince",IsCoffeeDrinker=true}
                };
            }

            else
            {
                using (var stream = await storageFile.OpenAsync(FileAccessMode.Read))
                {
                    using (var dataReader = new DataReader(stream))
                    {
                        await dataReader.LoadAsync((uint)stream.Size);
                        var json = dataReader.ReadString((uint)stream.Size);
                        customerList = JsonConvert.DeserializeObject<List<Customer>>(json);
                    }
                }
            }

            return customerList;
        }


        public async Task SaveCustomersAsync(IEnumerable<Customer> customers)
        {
            var storageFile = await _localFolder.CreateFileAsync(_customersFileName, CreationCollisionOption.ReplaceExisting);

            using (var stream = await storageFile.OpenAsync(FileAccessMode.ReadWrite))
            {
                using (var dataWriter = new DataWriter(stream))
                {
                    var json = JsonConvert.SerializeObject(customers, Formatting.Indented);
                    dataWriter.WriteString(json);
                    await dataWriter.StoreAsync();
                }
            }
        }
    }
}
```
</details>

<details>
<summary>Models/Customer.cs</summary>
```csharp
namespace WiredBrainCoffee.UWP.Models
{
    public class Customer
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public bool IsCoffeeDrinker { get; set; }
    }
}
```
</details>

Event hooks are used to populate the `ListView` with data from the data provider.

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
public MainPage()
{
    this.InitializeComponent();
    this.Loaded += MainPage_LoadedAsync;

    App.Current.Suspending += App_SuspendingAsync;

    _customerDataProvider = new CustomerDataProvider();
}

private async void App_SuspendingAsync(object sender, Windows.ApplicationModel.SuspendingEventArgs e)
{
    var deferral = e.SuspendingOperation.GetDeferral();
    await _customerDataProvider.SaveCustomersAsync(customerListView.Items.OfType<Customer>());
    deferral.Complete();
}

private async void MainPage_LoadedAsync(object sender, RoutedEventArgs e)
{
    customerListView.Items.Clear();

    var customers = await _customerDataProvider.LoadCustomersAsync();
    foreach (var customer in customers)
    {
        customerListView.Items.Add(customer);
    }
}
```
</details>

## Data binding using events

![](/img/GUI-WBC-Binding-Events.gif)

Synchronize the customer detail textboxes to the selected item in the ListView.
A rough form of data binding is possible with [event handling](#event-handling). ([src](https://app.pluralsight.com/course-player?clipId=b5de77c9-45fd-49d4-9e15-fe121edf3fe4))

First implement an event handler when the `ListView.SelectionChanged` event is fired.

<details>
<summary>MainPage.xaml</summary>

```xml
<ListView 
    Grid.Row="1" 
    x:Name="customerListView" 
    DisplayMemberPath="FirstName"
    SelectionChanged="customerListView_SelectionChanged"/>
```
</details>

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
private void customerListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
{
    var customer = customerListView.SelectedItem as Customer;
    txtFirstName.Text = customer?.FirstName ?? "";
    txtLastName.Text = customer?.LastName ?? "";
    chkDrinksCoffee.IsChecked = customer?.IsCoffeeDrinker;
}
```
</details>

Implement event handlers on the controls in the main area (`TextBox.TextChanged` and `CheckBox.Checked` and `CheckBox.Unchedked` events) when changes are made.

<details>
<summary>
MainPage.xaml
</summary>
```xml
<StackPanel 
    Grid.Row="1" 
    Grid.Column="1">
    <TextBox 
        x:Name="txtFirstName"
        Header="First name" 
        Margin="10"
        TextChanged="UpdateCustomer"/>
    <TextBox 
        x:Name="txtLastName"
        Header="Last name" 
        Margin="10"
        TextChanged="UpdateCustomer"/>
    <CheckBox 
        x:Name="chkDrinksCoffee"
        Content="Caffeine fiend" 
        Margin="10"
        Checked="UpdateCustomer"
        Unchecked="UpdateCustomer"/>
</StackPanel>
```
</details>

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
private void UpdateCustomer(object sender, RoutedEventArgs e)
{
    var customer = customerListView.SelectedItem as Customer;

    if (customer != null)
    {
        customer.FirstName = txtFirstName.Text;
        customer.LastName = txtLastName.Text;
        customer.IsCoffeeDrinker = chkDrinksCoffee.IsChecked.GetValueOrDefault();
    }
}
```
</details>

## Update ListView
    
`ListView` still won't update as a result of changes.
In order to implement this, you have to raise the `PropertyChanged` event.
We implement the `INotifyPropertyChanged` interface and make it the base class of Customer.
Also, we implement a helper method to fire the event handler whenever a property is changed.
This helper is invoked every time a property is set.
The `CallerMemberName` attribute passes the name of the calling property as a string, and allows us to avoid placing `typeof(FirstName)`, etc with every invocation. ([src](https://app.pluralsight.com/course-player?clipId=5940e51b-bed0-491b-a847-edfcc7ed0981))

<details>
<summary>Models/Customer.cs</summary>

```csharp
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace WiredBrainCoffee.UWP.Models
{
    public class Observable : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }

    public class Customer : Observable
    {
        private string firstName;
        private string lastName;
        private bool isCoffeeDrinker;

        public string FirstName
        {
            get => firstName;
            set
            {
                firstName = value;
                OnPropertyChanged();
            }
        }
        public string LastName
        {
            get => lastName;
            set
            {
                lastName = value;
                OnPropertyChanged();
            }
        }
        public bool IsCoffeeDrinker
        {
            get => isCoffeeDrinker; 
            set
            {
                isCoffeeDrinker = value;
                OnPropertyChanged();
            }
        }

    }
}
```
</details>

## Add/remove customers

![](/img/GUI-WBC-Binding-Events3.gif)

Implement event handlers for the Add and Delete buttons. ([src](https://app.pluralsight.com/course-player?clipId=2465d7f7-d53d-4a57-b29d-a9547bb9afe8))

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
private void DeleteCustomer_Click(object sender, RoutedEventArgs e)
{
    var customer = customerListView.SelectedItem;
    if (customer != null)
    {
        customerListView.Items.Remove(customer);
    }
}
private void AddCustomer_Click(object sender, RoutedEventArgs e)
{
    var customer = new Customer { FirstName = "New" };
    customerListView.Items.Add(customer);
    customerListView.SelectedItem = customer;
}
```
</details>

<details>
<summary>MainPage.xaml</summary>
```xml
<Button x:Name="AddCustomer" Margin="10" 
        Click="AddCustomer_Click" >
    <SymbolIcon Symbol="AddFriend"/>
</Button>
<Button x:Name="DeleteCustomer" Margin="10" 
        Click="DeleteCustomer_Click">
    <SymbolIcon Symbol="Delete"/>
</Button>
```
</details>

## Custom control

We abstract controls in the main area of the app into a new CustomerDetailControl.
As before, we cut the UI elements into a new XAML file and reference the new control in MainPage.
However, now, customerListView is inaccessible.

The lynchpin is forming a property on customerDetailControl that is populated with the customer object by the `SelectionChanged` event handler

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
private void customerListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
{
    var customer = customerListView.SelectedItem as Customer;
    customerDetailControl.Customer = customer;
}
```
</details>

<details>
<summary>Controls/CustomerDetailControl.xaml</summary>

```xml
<UserControl
    x:Class="WiredBrainCoffee.UWP.Controls.CustomerDetailControl"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP.Controls"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d"
    d:DesignHeight="300"
    d:DesignWidth="400">

    <StackPanel>
        <TextBox 
                x:Name="txtFirstName"
                Header="First name" 
                Margin="10"
                TextChanged="UpdateCustomer"/>
        <TextBox 
                x:Name="txtLastName"
                Header="Last name" 
                Margin="10"
                TextChanged="UpdateCustomer"/>
        <CheckBox 
                x:Name="chkDrinksCoffee"
                Content="Caffeine fiend" 
                Margin="10"
                Checked="UpdateCustomer"
                Unchecked="UpdateCustomer"/>
    </StackPanel>
</UserControl>

```
</details>

<details>
<summary>Controls/CustomerDetailControl.xaml.cs</summary>

```csharp
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using WiredBrainCoffee.UWP.Models;

namespace WiredBrainCoffee.UWP.Controls
{
    public sealed partial class CustomerDetailControl : UserControl
    {
        public CustomerDetailControl()
        {
            this.InitializeComponent();
        }

        private Customer _customer;

        public Customer Customer
        {
            get { return _customer; }
            set
            {
                _customer = value;

                txtFirstName.Text = _customer?.FirstName ?? "";
                txtLastName.Text = _customer?.LastName ?? "";
                chkDrinksCoffee.IsChecked = _customer?.IsCoffeeDrinker;
            }
        }



        private void UpdateCustomer(object sender, RoutedEventArgs e)
        {
            if (Customer != null)
            {
                Customer.FirstName = txtFirstName.Text;
                Customer.LastName = txtLastName.Text;
                Customer.IsCoffeeDrinker = chkDrinksCoffee.IsChecked.GetValueOrDefault();

            }

        }
    }
}

```
</details>

## Assign mock content

We combine two different **namespace mappings** (one for the Customer model and another for the CustomerDetailControl) to prepopulate the CustomerDetailControl with a customer defined in XAML.
Because CustomerDetailControl exposes a public Customer property, this data can be assigned to the `Customer` property using property-element syntax. ([src](https://app.pluralsight.com/course-player?clipId=cc660abb-9cf2-4d46-ad11-6c653102b18b))

<details>
<summary>MainPage.xaml</summary>
```xml
<controls:CustomerDetailControl x:Name="customerDetailControl" Grid.Row="1" Grid.Column="1">
    <controls:CustomerDetailControl.Customer>
        <model:Customer FirstName="Clark" LastName="Kent" IsCoffeeDrinker="True"/>
    </controls:CustomerDetailControl.Customer>
</controls:CustomerDetailControl>
```
</details>

In order to be able to assign the customer as direct content without specifying the property explicitly, the custom control class has to be decorated with the `ContentProperty` attribute. 
This is because by default any direct child is assigned to the `Content` property, which does not exist for this custom control.
Using the `ContentProperty` allows us to specify a property to which to assign direct children.

<details>
<summary>Controls/CustomerDetailControl.xaml.cs</summary>

```csharp
[ContentProperty(Name = nameof(Customer))]
public sealed partial class CustomerDetailControl : UserControl 
{ 
    /* ... */ 
}
```
</details>

<details>
<summary>MainPage.xaml</summary>

```xml
<controls:CustomerDetailControl x:Name="customerDetailControl" Grid.Row="1" Grid.Column="1">
    <model:Customer FirstName="Clark" LastName="Kent" IsCoffeeDrinker="True"/>
</controls:CustomerDetailControl>
```
</details>

## XAML Type conversion

Passing the customer as an attribute requires custom logic to parse the string.
The target model is then decorated with the `CreateFromString` attribute.
This is only for custom classes: primitive types and enumerations can be parsed by the XAML processor automatically.

<details>
<summary>Models/CustomerConverter.cs</summary>

```csharp
namespace WiredBrainCoffee.UWP.Models
{
    public static class CustomerConverter
    {
        public static Customer ParseStringAsCustomer(string s)
        {
            string[] values = s.Split(';');
            return new Customer { FirstName = values[0], LastName = values[1], IsCoffeeDrinker = bool.Parse(values[2]) };
        }
    }
}
```
</details>
<details>
<summary>Models/Customer.cs</summary>
```csharp
[CreateFromString(MethodName ="WiredBrainCoffee.UWP.Models.CustomerConverter.ParseCustomerFromString")]
public class Customer : Observable
{
    /* ... */
}
```
</details>

## StaticResource

You can use the **StaticResource Markup Extension** to define the equivalent of XAML variables to store elements for attribution using attribute syntax.

Every UI element has a property named `Resources` to which you can assign elements.
Unlike the `Items` property of a ListView, however, this property is a Dictionary type, which means you must specify a key for these values (i.e. specify `x:Key`).
Because the XAML processor looks for resources as it crawls up the element tree, these resources can be organized at any level of the application, even in the App.xaml where it will become available to other files: ([src](https://app.pluralsight.com/course-player?clipId=ebab5c50-5407-4831-8d55-b2609ed3772b))

<details>
<summary>MainPage.xaml</summary>

```xml
<Page.Resources>
    <model:Customer x:Key="Shazam" FirstName="William" LastName="William Batson" IsCoffeeDrinker="false"/>
</Page.Resources>

<!-- ... -->
<controls:CustomerDetailControl Customer="{StaticResource Shazam}"/>
```
</details>

However, mocking data in XAML is an anti-pattern; Resource dictionaries are typically used for colors and predefined strings.

Resource dictionaries are consolidated into their own files: ([src](https://app.pluralsight.com/course-player?clipId=207b422a-35f8-495d-99e1-ad4e2e2921b0))

<details>
<summary>Resources/Brushes.xaml</summary>

```xml
<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
    <SolidColorBrush x:Key="customerListBackgroundBrush" Color="#EEEEEE"/>
</ResourceDictionary>
```
</details>

<details>
<summary>Resources/Strings.xaml</summary>

```xml
<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
    <x:String x:Key="applicationTitle">Wired Brain Coffee</x:String>
</ResourceDictionary>
```
</details>

These can then be referenced from App.xaml and are available for assignment in any appropriate attribute

<details>
<summary>App.xaml</summary>
```xml
<Application
    x:Class="WiredBrainCoffee.UWP.App"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP">
    <Application.Resources>
        <ResourceDictionary>
            <ResourceDictionary.MergedDictionaries>
                <ResourceDictionary Source="Resources/Brushes.xaml"/>
                <ResourceDictionary Source="Resources/Strings.xaml"/>
            </ResourceDictionary.MergedDictionaries>
        </ResourceDictionary>
    </Application.Resources>
</Application>
```
</details>

<details>
<summary>Controls/HeaderControl.xaml</summary>

```xml
<UserControl
    x:Class="WiredBrainCoffee.UWP.Controls.HeaderControl"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP.Controls"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d"
    d:DesignHeight="300"
    d:DesignWidth="400">

    <Border Background="#F05A28">
        <Grid>
            <Grid.ColumnDefinitions>
                <ColumnDefinition/>
                <ColumnDefinition Width="Auto"/>
            </Grid.ColumnDefinitions>

            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center">
                <Image Source="/Images/WiredBrainLogo.png" Height="90"/>
                <TextBlock Text="{StaticResource applicationTitle}" FontSize="40" VerticalAlignment="Center"/>

            </StackPanel>
            <Button x:Name="ButtonMove" HorizontalAlignment="Right" Grid.Column="1" Margin="10" Click="ButtonMove_Click">
                <SymbolIcon x:Name="ButtonMove_Symbol" Symbol="AlignRight"/>
            </Button>

        </Grid>
    </Border>
</UserControl>

```
</details>


## ThemeResource

![](/img/GUI-WBC-ThemeResource.gif)

The **ThemeResource Markup Extension** makes UWP-specific theme resource dictionaries available.
These same resources are available using StaticResource, but with ThemeResource they will be updated if the user changes his Windows theme from light to dark. ([src](https://app.pluralsight.com/course-player?clipId=97c44891-d8ee-4870-b15e-72adf3df9dda))

<details>
<summary>Resources/Brushes.xaml</summary>

```xml
<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
    <ResourceDictionary.ThemeDictionaries>
        <ResourceDictionary x:Key="Dark">
            <SolidColorBrush x:Key="customerListBackgroundBrush" Color="#222222"/>
        </ResourceDictionary>
        <ResourceDictionary x:Key="Light">
            <SolidColorBrush x:Key="customListBackgroundBrush" Color="#EEEEEE"/>
        </ResourceDictionary>
                            
    </ResourceDictionary.ThemeDictionaries>
</ResourceDictionary>
```
</details>

## Theme selection

![](/img/GUI-WBC-ThemeButton.gif)

A specific theme can be specified at any element by specifying a `RequestedTheme` attribute.
However, this property cannot be changed at runtime.

<details>
<summary>App.xaml</summary>
```xml
<Application
    x:Class="WiredBrainCoffee.UWP.App"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP"
    RequestedTheme="Dark">
    <Application.Resources>
        <ResourceDictionary>
            <ResourceDictionary.MergedDictionaries>
                <ResourceDictionary Source="Resources/Brushes.xaml"/>
                <ResourceDictionary Source="Resources/Strings.xaml"/>
            </ResourceDictionary.MergedDictionaries>
        </ResourceDictionary>
    </Application.Resources>
</Application>
```
</details>

A button to manually change theme involves simply assigning an `ElementTheme` enum value to the MainPage's `RequestedTheme` property.
However, because on startup this has an `ApplicationTheme` enum value that is not evailable in `ElementTheme`, the MainPage's constructor must be changed to set the correct theme enum.
Without this change, the first click after the application's startup will not change the theme at all, only set the correct `ElementTheme`. 
([src](https://app.pluralsight.com/course-player?clipId=0b405418-8135-4526-a1bc-499cf54751ff))

<details>
<summary>MainPage.xaml</summary>
```xml
<!-- Header -->
<controls:HeaderControl Grid.ColumnSpan="3"/>

<Button Grid.ColumnSpan="3" Click="ChangeTheme" Margin="10" VerticalAlignment="Top" HorizontalAlignment="Right">
    <SymbolIcon Symbol="Placeholder"/>
</Button>
```
</details>

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
public MainPage()
{
    this.InitializeComponent();
    this.Loaded += MainPage_LoadedAsync;

    App.Current.Suspending += App_SuspendingAsync;

    _customerDataProvider = new CustomerDataProvider();
    RequestedTheme = App.Current.RequestedTheme == ApplicationTheme.Dark
        ? ElementTheme.Dark
        : ElementTheme.Light;
}

private void ChangeTheme(object sender, RoutedEventArgs e)
{
    this.RequestedTheme = RequestedTheme == ElementTheme.Dark ? ElementTheme.Light : ElementTheme.Dark;
}
```
</details>

## Color theme

The **Fluent XAML Theme Editor** on the Microsoft Store can generate ThemeResource dictionaries 

## Data binding

Use the **Binding markup extension** to establish a binding on the CustomerDetailControl to the Customer property of customerListView

Here, the Customer property is the **target property**, and the SelectedItem property of customerListView is the **source property**. So this data binding makes the information in the customerDetailControl (target) dependent on which item is selected (source).

<details>
<summary>MainPage.xaml.cs</summary>

```xml
<controls:CustomerDetailControl 
    x:Name="customerDetailControl" Grid.Row="1" Grid.Column="1"
    Customer="{Binding ElementName=customerListView,Path=SelectedItem,Mode=OneWay}">
```
</details>

However, the target of a data binding needs to be a [**Dependency Property**](https://docs.microsoft.com/en-us/dotnet/desktop/wpf/advanced/dependency-properties-overview?view=netframeworkdesktop-4.8#dependency-properties-and-clr-properties).
The purpose of dependency properties is to provide a way to compute the value of a property based on the value of other inputs.
The Visual Studio snippet for a dependency property is **`propdp`**.

A dependency property includes a static readonly field of type `DependencyProperty` and a normal property that works as a frontend for that field by wrapping `GetValue` and `SetValue`.

We implement the logic to update the controls with the selected customer as a **callback** function passed as the second argument of the `PropertyMetadata` object in the dependency property definition.
This callback must be a static void function, and as such it has no access to the instantiated objects we have already named with `x:Name`.
However, these objects are retrievable from the `DependencyObject` and `DependencyPropertyChangedEventArgs` parameters that are passed to the callback. ([src](https://app.pluralsight.com/course-player?clipId=cf59b1e5-2393-46ad-a397-264239af5983))

<details>
<summary>Controls/CustomerDetailControl.xaml.cs</summary>

```csharp
public Customer Customer
{
    get { return (Customer)GetValue(CustomerProperty); }
    set { SetValue(CustomerProperty, value); }
}

// Using a DependencyProperty as the backing store for Customer.  This enables animation, styling, binding, etc...
public static readonly DependencyProperty CustomerProperty =
    DependencyProperty.Register("Customer", typeof(Customer), typeof(CustomerDetailControl), new PropertyMetadata(null, CustomerChangedCallback));

private static void CustomerChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
{
    if (d is CustomerDetailControl customerDetailControl)
    {
        var customer = e.NewValue as Customer;
        
        customerDetailControl.txtFirstName.Text = customer?.FirstName ?? "";
        customerDetailControl.txtLastName.Text = customer?.LastName ?? "";
        customerDetailControl.chkDrinksCoffee.IsChecked = customer?.IsCoffeeDrinker;
    }
}
```
</details>
This bound the customerDetailControl to the item selected in customerListView. 

Now we implement the data bindings on each control of customerDetailControl.
We give the root UserControl an `x:Name` so that we can refer to it in the binding markup extensions of the children as the value of `ElementName`. 
We can also remove the `x:Name`s of the individual controls, as well any trace of the event handlers!
([src](https://app.pluralsight.com/course-player?clipId=12b1f374-efdc-4eff-b987-ba6c1959f766))

<details>
<summary>Controls/CustomerDetailControl.xaml</summary>

```xml
<UserControl
    x:Class="WiredBrainCoffee.UWP.Controls.CustomerDetailControl"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="using:WiredBrainCoffee.UWP.Controls"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    mc:Ignorable="d"
    d:DesignHeight="300"
    d:DesignWidth="400"
    x:Name="root">

    <StackPanel>
        <TextBox 
                Header="First name" 
                Margin="10"
                Text="{Binding ElementName=root,Path=Customer.FirstName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
            />
        <TextBox 
                Header="Last name" 
                Margin="10"
                Text="{Binding ElementName=root,Path=Customer.LastName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
                
            />
        <CheckBox 
                Content="Caffeine fiend" 
                Margin="10"
                IsChecked="{Binding ElementName=root,Path=Customer.FirstName,Mode=TwoWay}"
            />
    </StackPanel>
</UserControl>
```
</details>

## ViewModel

In the work above, we used the binding markup extension to bind one element to another, using that other element as a data source

```xml
<TextBlock Text="{Binding ElementName=root,...}">
```

We can use the MVVM pattern to assign the object to be bound to customerDetailControl as a **data context**.
Every UI element has a `DataContext` property that can be set, and if it is set to an object then it can be placed there as a default data source that the XAML processor will find as it walks up the element tree. ([src](https://app.pluralsight.com/course-player?clipId=ddc60a64-f8c5-48bd-bbf5-83a1ace7199f))

This will allow us to simplify the markup, removing the `x:Name` from the root and the `ElementName` from the data bindings of the children. 

First we create the ViewModel, which incorporates some of the logic from the former `App_SuspendingAsync` and `MainPage_LoadedAsync` event handler methods.
The ViewModel can dispose of the references to customerDetailControl and customerListView and replace them with its own Customers property.
<details>
<summary>ViewModel/MainViewModel.cs</summary>

```csharp
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using WiredBrainCoffee.UWP.DataProviders;
using WiredBrainCoffee.UWP.Models;

namespace WiredBrainCoffee.UWP.ViewModel
{
    public class MainViewModel
    {
        public ObservableCollection<Customer> Customers { get; }
        public MainViewModel()
        {
            _customerDataProvider = new CustomerDataProvider();
            Customers = new ObservableCollection<Customer>();
        }

        private CustomerDataProvider _customerDataProvider;


        public async Task LoadAsync()
        {
            Customers.Clear();

            var customers = await _customerDataProvider.LoadCustomersAsync();
            foreach (var customer in customers)
            {
                Customers.Add(customer);
            }
        }

        public async Task SaveAsync()
        {
            await _customerDataProvider.SaveCustomersAsync(Customers);
        }
    }
}
```
</details>

To further decouple the ViewModel from the data provider, in order to facilitate testing, we extract an interface from CustomerDataProvider.

<details>
<summary>DataProviders/ICustomerDataProvider.cs</summary>

```csharp
using System.Collections.Generic;
using System.Threading.Tasks;
using WiredBrainCoffee.UWP.Models;

namespace WiredBrainCoffee.UWP.DataProviders
{
    public interface ICustomerDataProvider
    {
        Task<IEnumerable<Customer>> LoadCustomersAsync();
        Task SaveCustomersAsync(IEnumerable<Customer> customers);
    }
}
```
</details>

Now we implement an `ICustomerDataProvider` parameter to the ViewModel constructor, and remember to pass in a new data provider as an argument implementing that interface.
The private field _customerDataProvider can be removed.

<details>
<summary>ViewModel/MainViewModel.cs</summary>

```csharp
private ICustomerDataProvider _customerDataProvider;
public MainViewModel(ICustomerDataProvider customerDataProvider)
{
    _customerDataProvider = customerDataProvider;
    Customers = new ObservableCollection<Customer>();
}
```
</details>

<details>
<summary>MainPage.xaml.cs</summary>

```csharp
this.ViewModel = new MainViewModel(new CustomerDataProvider());
DataContext = ViewModel;
```
</details>

Finally, since we have a data context on MainPage, we can set it as a source for the ListView

<details>
<summary>MainPage.xaml</summary>
```xml
<ListView 
    ItemsSource="{Binding Customers,Mode=OneWay}"
    Grid.Row="1" 
    x:Name="customerListView" 
    DisplayMemberPath="FirstName">
```
</details>

## Binding the selected customer

At this moment, customerDetailControl is still tied to customerListView's SelectedItem property directly, and not through the ViewModel.
To change this, we implement a SelectedCustomer property on the ViewModel that will be bound to both.
We reuse the Observable base class that implement the `INotifyPropertyChanged` interface.
This allows us to use the `OnPropertyChanged()` method in the setter of the new SelectedItem property.
We replace the element binding of customerListView with a binding to the SelectedCustomer property in the data context.

<details>
<summary>ViewModel/MainViewModel.cs</summary>

```csharp
public class MainViewModel : Observable
{
    private Customer selectedCustomer;

    public Customer SelectedCustomer
    {
        get { return selectedCustomer; }
        set 
        { 
            selectedCustomer = value;
            OnPropertyChanged();
        }
    }

    // ...
}

```
</details>

<details>
<summary>MainPage.xaml</summary>
```xml
<ListView 
    ItemsSource="{Binding Customers,Mode=OneWay}"
    Grid.Row="1" 
    x:Name="customerListView" 
    DisplayMemberPath="FirstName"
    SelectedItem="{Binding SelectedCustomer,Mode=TwoWay}">
</ListView>
```
</details>

## DataTemplate

At this moment, customerListView is being populated by a single property of each Customer - their first name.
If we want to compose more complex information, we can assign **DataTemplate** to the ListView's ItemTemplate property.
This will create the enclosed controls for each element in the ListView.
Remember to remove the `DisplayMemberPath` attribute!

```xml
<ListView 
    ItemsSource="{Binding Customers,Mode=OneWay}"
    Grid.Row="1" 
    x:Name="customerListView" 
    SelectedItem="{Binding SelectedCustomer,Mode=TwoWay}">
    <ListView.ItemTemplate>
        <DataTemplate>
            <StackPanel Orientation="Horizontal">
                <TextBlock Text="{Binding FirstName}"/>
                <TextBlock Text="{Binding LastName}" Margin="5 0 0 0" FontWeight="Bold"/>
            </StackPanel>
        </DataTemplate>
    </ListView.ItemTemplate>
</ListView>
```

## x:Bind

There are two data binding types available in XAML ([src](https://app.pluralsight.com/course-player?clipId=5cfb0a48-8455-4217-a83e-f93fc4aa5c24))

- **Binding markup extension** resolves the binding path at runtime.
- **x:Bind** resolves the binding path at **compile-time**, generating C# code and offering better performance and compile-time errors. You can also step into the compiled code, providing a better debugging experience. x:Bind should generally be preferred, however it is available only in UWP.

Binding markup extension can have several different data sources, depending on defined attributes.

- `ElementName`
- `Source`
- `RelativeSource`

If none of these are defined, then the binding markup extension resolves to the DataContext property.

x:Bind, in contrast, binds only to the parent Page or UserControl element. So any property of MainPage will be accessible, and any property of that object will also be accessible using dot notation.

Most bindings are easily translated between the two types if the ViewModel has already been implemented as a property of MainPage:

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

Notably, the default binding mode of the Binding markup extension is **`OneWay`** `x:Bind` is **`OneTime`**, although this can be changed by setting `x:DefaultBindMode` on the root element.

=== "Set explicitly"

    ```xml
    <Page>

        <Listview ItemsSource="{x:Bind ViewModelCustomers,Mode=OneWay}"/>
    </Page>
    ```

=== "Changing default binding mode"

    ```xml
    <Page
        x:DefaultBindMode="OneWay">
        <Listview ItemsSource="{x:Bind ViewModelCustomers}"/>
    </Page>
    ```


customDetailControl, which previously used the binding markup extension but set the root element as an explicitly named source property, is notably simplified after replacing with `x:Bind`. We can now directly access the user control's property.

=== "Before"

    ```xml
    <UserControl
        x:Class="WiredBrainCoffee.UWP.Controls.CustomerDetailControl"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="using:WiredBrainCoffee.UWP.Controls"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        mc:Ignorable="d"
        d:DesignHeight="300"
        d:DesignWidth="400"
        x:Name="root">

        <StackPanel>
            <TextBox 
                    Header="First name" 
                    Margin="10"
                    Text="{Binding ElementName=root,Path=Customer.FirstName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
                />
            <TextBox 
                    Header="Last name" 
                    Margin="10"
                    Text="{Binding ElementName=root,Path=Customer.LastName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
                    
                />
            <CheckBox 
                    Content="Caffeine fiend" 
                    Margin="10"
                    IsChecked="{Binding ElementName=root,Path=Customer.FirstName,Mode=TwoWay}"
                />
        </StackPanel>
    </UserControl>
    ```

=== "After"

    ```xml
    <UserControl
        x:Class="WiredBrainCoffee.UWP.Controls.CustomerDetailControl"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="using:WiredBrainCoffee.UWP.Controls"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        mc:Ignorable="d"
        d:DesignHeight="300"
        d:DesignWidth="400"
        >

        <StackPanel>
            <TextBox 
                    Header="First name" 
                    Margin="10"
                    Text="{x:Bind Customer.FirstName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
                />
            <TextBox 
                    Header="Last name" 
                    Margin="10"
                    Text="{x:Bind Customer.LastName,Mode=TwoWay,UpdateSourceTrigger=PropertyChanged}"
                    
                />
            <CheckBox 
                    Content="Caffeine fiend" 
                    Margin="10"
                    IsChecked="{x:Bind Customer.IsCoffeeDrinker,Mode=TwoWay}"
                />
        </StackPanel>
    </UserControl>
    ```

x:Bind can also be implemented in the ListView's ItemTemplate, so long as the **x:DataType** attribute is set on DataTemplate.
We must also remember to set the Mode binding property, since x:Bind's default is OneTime! ([src](https://app.pluralsight.com/course-player?clipId=7d74b6fa-29a6-4d22-be47-7d0ee37f4082))

```xml
<ListView Grid.Row="1" ItemsSource="{x:Bind ViewModel.Customers}" SelectedItem="{x:Bind ViewModel.SelectedCustomer,Mode=TwoWay}">
    <ListView.ItemTemplate>
        <DataTemplate x:DataType="model:Customer">
            <StackPanel Orientation="Horizontal">
                <TextBlock Text="{x:Bind FirstName}"/>
                <TextBlock Text="{x:Bind LastName}" Margin="5 0 0 0" FontWeight="Bold"/>
            </StackPanel>
        </DataTemplate>
    </ListView.ItemTemplate>
</ListView>
```

x:Bind can also hide or reveal controls depending on boolean value.
A new boolean property is formed on the ViewModel, and we wire the `OnPropertyChanged` event handler to it.
We also bind this value to the Visibility attribute of customerDetailControl.
This will hide the customerDetailControl on application startup before the user selects a customer. ([src](https://app.pluralsight.com/course-player?clipId=54cc2694-7a4b-4a2c-846c-c4d4bc405958))

```csharp
public Customer SelectedCustomer
{
    get { return selectedCustomer; }
    set
    {
        if (selectedCustomer != value)
        {

            selectedCustomer = value;
            OnPropertyChanged();
            OnPropertyChanged(nameof(IsCustomerSelected));
        }
    }
}

public bool IsCustomerSelected => SelectedCustomer != null;
```
```xml
<controls:CustomerDetailControl 
    x:Name="customerDetailControl" 
    Grid.Row="1" Grid.Column="1"
    Customer="{x:Bind ViewModel.SelectedCustomer,Mode=TwoWay}"
    Visibility="{x:Bind ViewModel.IsCustomerSelected}"/>
```

We can also implement a third TextBlock in the ListView's ItemTemplate to show a string depending on the value of the CheckBox.

```xml
<ListView 
    Grid.Row="1" 
    ItemsSource="{x:Bind ViewModel.Customers}"
    SelectedItem="{x:Bind ViewModel.SelectedCustomer,Mode=TwoWay}">
    <ListView.ItemTemplate>
        <DataTemplate x:DataType="model:Customer">
            <StackPanel Orientation="Horizontal">
                <TextBlock Text="Dev" Opacity="0.5" Visibility="{x:Bind IsCoffeeDrinker}" Margin="0 0 5 0"/>
                <TextBlock Text="{x:Bind FirstName}" />
                <TextBlock Text="{x:Bind LastName}" Margin="5 0 0 0" FontWeight="Bold"/>
            </StackPanel>
        </DataTemplate>
    </ListView.ItemTemplate>
</ListView>
```

## Toggling visibility

In order to fully implement the logic of the MVVM pattern, we should move functionality that deals with the logic of the app as a whole to the ViewModel.
That would include the Add and Delete buttons. ([src](https://app.pluralsight.com/course-player?clipId=639efe6a-f667-4cf5-a9ca-7ce1b7a7b9f3))

=== "Before"

    ```xml
    <CommandBar>

        <AppBarButton x:Name="AddCustomer" Click="AddCustomer_Click" Label="Add">
            <SymbolIcon Symbol="Add"/>
        </AppBarButton>
        <AppBarButton x:Name="DeleteCustomer" Click="DeleteCustomer_Click" Label="Delete">
            <SymbolIcon Symbol="Delete"/>
        </AppBarButton>
        <AppBarButton x:Name="btn_MoveSideBar" Click="btn_MoveSideBar_Click" Label="Move sidebar">
            <SymbolIcon x:Name="btn_MoveSideBar_Symbol" Symbol="AlignRight"/>
        </AppBarButton>

    </CommandBar>
    ```

=== "After"

    ```xml
    <CommandBar>

        <AppBarButton x:Name="AddCustomer" Click="{x:Bind ViewModel.AddCustomer_Click}" Label="Add">
            <SymbolIcon Symbol="Add"/>
        </AppBarButton>
        <AppBarButton x:Name="DeleteCustomer" Click="{x:Bind ViewModel.DeleteCustomer_Click}" Label="Delete">
            <SymbolIcon Symbol="Delete"/>
        </AppBarButton>
        <AppBarButton x:Name="btn_MoveSideBar" Click="btn_MoveSideBar_Click" Label="Move sidebar">
            <SymbolIcon x:Name="btn_MoveSideBar_Symbol" Symbol="AlignRight"/>
        </AppBarButton>

    </CommandBar>
    ```

## Styling

You can define a style that has to be used more than once by declaring a Style element on a UserControl's Resources property. ([src](https://app.pluralsight.com/course-player?clipId=b638b95b-5d93-41bf-ac87-c7f2ac7355f4))

```xml
<UserControl>
    <UserControl.Resources>
        <Style x:Key="myTextBoxStyle" TargetType="TextBox">
            <Style.Setters>
                <Setter Property="Margin" Value="10"/>
                <Setter Property="CornerRadius" Value="10"/>
            </Style.Setters>
        </Style>
    </UserControl.Resources>
</UserControl>
```

This Style can then be used as a StaticResource, setting the value of the Style attribute.