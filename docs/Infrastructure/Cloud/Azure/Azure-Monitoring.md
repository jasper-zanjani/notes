A robust monitoring strategy implementing proactive notifications helps to increase uptime and optimize performance. Azure offers **Azure Monitor** and **Azure Advisor**.

- [**Azure Monitor**](#azure-monitor) brings a unified alerting experience to Azure, with a single pane of glass for interacting with metrics, the **Activity Log**, **Log Analytics**, service and resource health and service-specific insights. 
    - Alerts can be filtered by subscription (maximum of 5), resource group (maximum of 1), resource type (available selections depend on resources deployed to selected group) time range (past hour, past day, past week, and past 30 days), and other criteria.
    - Azure Monitor can create [**alert rules**](#alerts) that are built on target resources or resource type and that proactively notify you of the health of resources and can also leverage action groups that automate actions to take in certain conditions.
- **Azure Advisor** is a free, personalized guide to Azure best practices that provides recommendations to help you optimize resources. 
Azure Advisor offers personalized recommendations across 4 domains: High availability, Security, Performance, and Cost

| Feature               | Logs                                                                                    | Metrics                                                                                              |
| :-------------------- | :-------------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------- |
| **Retention**         | Stored in Log Analytics (2 years)                                                       | Stored in Monitor for 93 days, but metrics can be sent to Log Analytics and Storage accounts as well |
| **Properties**        | Varying properties for each log, with support for rich data types such as date and time | Fixed set of properties (or attributes): time, type, resource, value, and (optionally) dimensions.   |
| **Data availability** | Triggered by an event, requiring time to process before they are available for querying | Gathered at intervals and available for immediate querying.                                          |

Virtual machines can be one of the most expensive resources in a cloud implementation, and there are several ways to reduce their cost

- Deallocate compute when not needed
- Delete unused virtual machines and allocate them only on demand
- Right-size VMs so that you don't overuse resources

Advisor can also identify

- ExpressRoute circuits that have been "Not Provisioned" for more than 30 days
- Gateways that have been idle for more than 90 days

There are two monitoring data streams:

- **Metrics** are the numerical time series data produced by resources and services within Azure. They are collected at 1-minute intervals, identified by a metric name and namespace (category). Metrics can be one-dimensional or have up to 10 dimensions.
    - Metrics have the following properties:
        - **Time** the value was collected
        - **Type** of measurement made
        - **Resource** associated with value
        - **Value**
    - Metrics can be stored in:
        - Azure Monitor for 93 days
        - Log Analytics for 2 years
        - Storage account, where they are treated according to the retention policy and storage limits of the account.
- **Logs** come in various types
  - **Diagnostics logs** (including **resource logs** and **tenant logs**) are a type of log data that can be configured to send data to other locations, such as a Storage account or [Log Analytics workspace](#log-analytics). Diagnostics logs have to be enabled for each resource to be monitored through the Portal by enabling Diagnostics Settings, and not all resource types support diagnostic logs. Of those that do, not all resources support a retention policy or sending metric data.
  - **Azure Activity logs** is a subscription level log that captures events that range from operational data (i.e. resource creation, deletion) to service health events for a subscription, but lacks resource-level detail..
  - **Guest telemetry** can relay logs from VMs with the use of diagnostics agents

## Log Analytics
A **Log Analytics workspace** is a form of abstracting the process of log collection and is used to collect and aggregate logs. Like any other resource, it must be associated with a location and a resource group. Any Azure resource can only report logs to a single workspace, but Azure Monitor allows multiple workspaces to be queried simultaneously. The logs can be queried through Log Analytics or Monitor. Because a workspace is a resource, RBAC can be applied to control access to it. 

Log Analytics is based on Azure Data Explorer and uses [Kusto](Kusto).

Log Analytics [pricing](https://azure.microsoft.com/en-us/pricing/details/monitor/) is divided into **data ingestion** and **data retention**:
- Under **Pay-As-You-Go** data ingestion the first 5 GB per month are free and further data is charged at a rate of $2.76/GB/month
- **Capacity Reservations** offer a discount on Pay-as-you-go by charging a fixed amount per day ($219.52/day for 100 GB), with further discounts at higher tiers
- Data retention is free for any amount of data up to 31 days, and 90 days for [Azure Sentinel](Azure-Sentinel)-enabled workspaces

### Operational Insights
Log Analytics was previously named **Operational Insights**, which was named [**System Center Advisor**](https://en.wikipedia.org/wiki/System_Center_Advisor) prior to 2014.

## Application Insights
Application Insights is a platfrom separate from Log Analytics which is intended to monitor web applications.

## Alerts
Alerts can be created from the Alerts pane in the Monitor blade:
![](/img/az-monitor-alerts.png)

Most resource blades also have Alerts in the resource menu under Monitoring.

**Alert rules**, which are used to generate alerts, contain
- **Target resource**, any Azure resource that generates signals, defines the scope and signals available for the alert.
- **Signal** (i.e. metric or Activity Log) emitted by target resource. Signals are of 3 types: 
  1. Metrics
  2. Log search queries 
  3. Activity logs
- **Conditional logic** for alert combines the signal and a logical test to trigger alert.
- **Action Group** determines what will happen when the alert is trigged. Action groups are themselves resources, and thus located in a subscription and resource group, and have:
  - **Name**
  - **Short name** is used to identify the Action Group in emails and notifications and is limited to 12 characters
  - [**Actions**](#actions) define the configuration for a specific action type. 
- Severity (0-4)

Alerts can have 3 states:

- **New** and not reviewed
- **Acknowledged** issue is being actioned by an admin
- **Closed** issue that generated the alerts has been resolved and the alert has been marked as closedAlerts have many notification options, including email, SMS, mobile app, voice, and integration with automation. 

### Actions
![](/img/az-action-group.png)

A single action group can trigger multiple actions. Available types include: Email/SMS/Push/Voice, Azure Function, Logic App, Webhook, ITSM, and Automation Runbook

- **IT Service Management Connector** up to 10 ITSM actions can be configured with an ITSM connection
  - Supported providers include ServiceNow, System Center Service Manager, Provance, and Cherwell :point_right: [Connect Azure to ITSM tools using ITSMC](https://docs.microsoft.com/en-us/azure/azure-monitor/platform/itsmc-overview)
- [Webhooks](https://docs.microsoft.com/azure/monitoring-and-diagnos-tics/insights-webhooks-alerts)
- Runbook runs in Azure Automation Service [Runbooks](https://azure.microsoft.com/blog/automatically-remediate-azure-vm-alerts-with-automation-run-books/)

The maximum number of alert notifications per hour:
- Email: 60
- Voice: 12
- SMS: 12

## VMs

![](/img/az-vm-insights.png)

"Virtual Machine **Insights**" (or "Azure Monitor for VMs") is the successor to older monitoring workflow that used "guest OS diagnostics" in conjunction with Metrics Explorer. It requires a [log analytics workspace](#log-analytics).
**Diagnostic settings**, conventionally, was the feature that would be enabled to allow Azure to collect metrics and logs from VMs, including **event logs** and performance counters.


Two primary views:
- **Performance** is a successor to the old Metrics Explorer
- **Map** (originally "Service Map")


# Tasks
### Enable diagnostics on a VM
Sources:
- [`az vm diagnostics set`](https://docs.microsoft.com/en-us/cli/azure/vm/diagnostics?view=azure-cli-latest#az_vm_diagnostics_set)

```sh

```
### Diagnostics log collection with a storage account
Browse to the resource itself. Alternatively, open **Azure Monitor** and then the **Diagnostics Settings** blade. From there you can view all eligible resouce types and view status of log collection. 
```powershell
$resource = Get-AzResource -Name $resourceName -ResourceGroupName $resourceGroupName
$storage = Get-AzResource -Name $resourceName -ResourceGroupName $resourceGroupName
Set-AzDiagnosticSetting -ResourceId $resource.ResourceId -StorageAccountId $storage.ResourceId -Enabled $true
```
```sh
resourceId=$(az resource show -resource-group $resourceGroupName -name $resourceName --resource-type $resourceType --query id --output tsv)
az monitor diagnostic-settings create --name $diagnosticName --storage-account $storageId --resource $resouceId --resource-group $resourceGroup \
  --logs '[ {
    "category": <categoryName>,
    "enabled": true,
    "retentionPolicy": {
      "days": <numberOfDays>,
      "enabled": true } } ] '
```
### Diagnostics log streaming to an Event Hub
```powershell
$rule = Get-AzServiceBusRule -ResourceGroup $resourceGroupName -Namespace $namespace -Topic $topic -Subscription $subscription -Name $ruleName
Set-AzDiagnosticSetting -ResourceId $resource.ResourceId -ServiceBusRuleId $rule.Id -Enabled $true
```
```sh
resourceId=$(az resource show -resource-group $resourceGroupName -name $resourceName --resource-type $resourceType --query id --output tsv)
az monitor diagnostic-settings create --name $diagnosticName --event-hub $eventHubName --event-hub-rule $eventHubRuleId --resource $resourceId \
  --logs '[{
    "category": <categoryName>,
    "enabled": true }]'
```
### Diagnostics log collection in a Log Analytics workspace
The [PowerShell module](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/get-azoperationalinsightsworkspace?view=azps-5.0.0) that allows interaction with Log Analytics still refers to the service's [old name](#operational-insights).

```powershell
$workspace = Get-AzOperationalInsightsWorkspace -Name $logAnalyticsName -ResourceGroupName $g
Set-AzDiagnosticSetting -ResourceId $r.ResourceId -WorkspaceId $workspace.ResourceId -Enabled $true
```
```sh
az monitor diagnostic-settings create --name $diagnosticName --workspace $logAnalyticsName --resource $rid --resouce-group $g \
  --logs '[{
    "category": <categoryName>,
    "enabled": true }]'
```
### Create an alert rule
Sources:
- [Create, view, and manage activity log alerts by using Azure Monitor](https://docs.microsoft.com/en-us/azure/azure-monitor/platform/alerts-activity-log)

![](/img/manage-action-groups.png)

![](/img/create-new-alert-rule-options.png)

### Create Log Analytics workspace
# Sources
- AZ-103: [<code>1.2</code>](AZ-103#12-analyze-resource-utilization-and-consumption "Analyze resource utilization and consumption")
- AZ-104: [<code>5.1</code>](AZ-104#51-monitor-resources-by-using-azure-monitor "Monitor resources by using Azure Monitor")

- [Azure Monitor for VMs](https://app.pluralsight.com/course-player?clipId=f281d048-7e2a-4312-9200-4665a12fd126)