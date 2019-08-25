# PowerShell commands for Azure
Azure Powershell Modules
:---
[accounts](#azaccounts) [advisor](#azadvisor) [aks](#azaks) [alertsmanagement](#azalertsmanagement) [analysisservices](#azanalysisservices) [apimanagement](#azapimanagement) [applicationinsights](#azapplicationinsights) [attestation](#azattestation) [automation](#azautomation) [batch](#azbatch) [billing](#azbilling) [blueprint](#azblueprint) [cdn](#azcdn) [cognitiveservices](#azcognitiveservices) [compute](#azcompute) [containerinstance](#azcontainerinstance) [containerregistry](#azcontainerregistry) [databox](#azdatabox) [datafactory](#azdatafactory) [datalakeanalytics](#azdatalakeanalytics) [datalakestore](#azdatalakestore) [datamigration](#azdatamigration) [deploymentmanager](#azdeploymentmanager) [deviceprovisioningservices](#azdeviceprovisioningservices) [devspaces](#azdevspaces) [devtestlabs](#azdevtestlabs) [eventgrid](#azeventgrid) [eventhub](#azeventhub) [frontdoor](#azfrontdoor) [guestconfiguration](#azguestconfiguration) [hdinsight](#azhdinsight) [iothub](#aziothub) [keyvault](#azkeyvault) [kusto](#azkusto) [logicapp](#azlogicapp) [machinelearning](#azmachinelearning) [managedserviceidentity](#azmanagedserviceidentity) [managedservices](#azmanagedservices) [managementpartner](#azmanagementpartner) [maps](#azmaps) [marketplaceordering](#azmarketplaceordering) [media](#azmedia) [mixedreality](#azmixedreality) [netappfiles](#aznetappfiles) [network](#aznetwork) [notificationhubs](#aznotificationhubs) [operationalinsights](#azoperationalinsights) [peering](#azpeering) [policyinsights](#azpolicyinsights) [powerbiembedded](#azpowerbiembedded) [privatedns](#azprivatedns) [recoveryservices](#azrecoveryservices) [rediscache](#azrediscache) [relay](#azrelay) [reservations](#azreservations) [resourcegraph](#azresourcegraph) [resources](#azresources) [search](#azsearch) [security](#azsecurity) [servicebus](#azservicebus) [servicefabric](#azservicefabric) [signalr](#azsignalr) [sql](#azsql) [storage](#azstorage) [storagesync](#azstoragesync) [streamanalytics](#azstreamanalytics) [subscription](#azsubscription) [trafficmanager](#aztrafficmanager) [websites](#azwebsites)

Azure PowerShell commands
:---
**Accounts** [Add-AzEnvironment](#add-azenvironment) [Clear-AzContext](#clear-azcontext) [Clear-AzDefault](#clear-azdefault) [**Connect-AzAccount**](#connect-azaccount) [Disable-AzContextAutosave](#disable-azcontextautosave) [Disable-AzDataCollection](#disable-azdatacollection) [Disable-AzureRmAlias](#disable-azurermalias) [Disconnect-AzAccount](#disconnect-azaccount) [Enable-AzContextAutosave](#enable-azcontextautosave) [Enable-AzDataCollection](#enable-azdatacollection) [Enable-AzureRmAlias](#enable-azurermalias) [Get-AzContext](#get-azcontext) [Get-AzContextAutosaveSetting](#get-azcontextautosavesetting) [Get-AzDefault](#get-azdefault) [Get-AzEnvironment](#get-azenvironment) [Get-AzProfile](#get-azprofile) [Get-AzSubscription](#get-azsubscription) [Get-AzTenant](#get-aztenant) [Import-AzContext](#import-azcontext) [Register-AzModule](#register-azmodule) [Remove-AzContext](#remove-azcontext) [Remove-AzEnvironment](#remove-azenvironment) [Rename-AzContext](#rename-azcontext) [Resolve-AzError](#resolve-azerror) [Save-AzContext](#save-azcontext) [Select-AzContext](#select-azcontext) [Select-AzProfile](#select-azprofile) [Send-Feedback](#send-feedback) [Set-AzContext](#set-azcontext) [Set-AzDefault](#set-azdefault) [Set-AzEnvironment](#set-azenvironment) [Uninstall-AzureRm](#uninstall-azurerm)
**Advisor** [Disable-AzAdvisorRecommendation](#disable-azadvisorrecommendation) [Enable-AzAdvisorRecommendation](#enable-azadvisorrecommendation) [Get-AzAdvisorConfiguration](#get-azadvisorconfiguration) [Get-AzAdvisorRecommendation](#get-azadvisorrecommendation) [Set-AzAdvisorConfiguration](#set-azadvisorconfiguration)
**Aks** [Get-AzAks](#get-azaks) [Import-AzAksCredential](#import-azakscredential) [New-AzAks](#new-azaks) [Remove-AzAks](#remove-azaks) [Set-AzAks](#set-azaks) [Start-AzAksDashboard](#start-azaksdashboard) [Stop-AzAksDashboard](#stop-azaksdashboard)
**Alertsmanagement** [Get-AzActionRule](#get-azactionrule) [Get-AzAlert](#get-azalert) [Get-AzAlertObjectHistory](#get-azalertobjecthistory) [Get-AzSmartGroup](#get-azsmartgroup) [Get-AzSmartGroupHistory](#get-azsmartgrouphistory) [Measure-AzAlertStatistic](#measure-azalertstatistic) [Remove-AzActionRule](#remove-azactionrule) [Set-AzActionRule](#set-azactionrule) [Update-AzActionRule](#update-azactionrule) [Update-AzAlertState](#update-azalertstate) [Update-AzSmartGroupState](#update-azsmartgroupstate)
**Analysisservices** [Add-AzAnalysisServicesAccount](#add-azanalysisservicesaccount) [Export-AzAnalysisServicesInstanceLog](#export-azanalysisservicesinstancelog) [Get-AzAnalysisServicesServer](#get-azanalysisservicesserver) [New-AzAnalysisServicesFirewallConfig](#new-azanalysisservicesfirewallconfig) [New-AzAnalysisServicesFirewallRule](#new-azanalysisservicesfirewallrule) [New-AzAnalysisServicesServer](#new-azanalysisservicesserver) [Remove-AzAnalysisServicesServer](#remove-azanalysisservicesserver) [Restart-AzAnalysisServicesInstance](#restart-azanalysisservicesinstance) [Resume-AzAnalysisServicesServer](#resume-azanalysisservicesserver) [Set-AzAnalysisServicesServer](#set-azanalysisservicesserver) [Suspend-AzAnalysisServicesServer](#suspend-azanalysisservicesserver) [Sync-AzAnalysisServicesInstance](#sync-azanalysisservicesinstance) [Test-AzAnalysisServicesServer](#test-azanalysisservicesserver)
**Apimanagement** [Add-AzApiManagementApiToProduct](#add-azapimanagementapitoproduct) [Add-AzApiManagementProductToGroup](#add-azapimanagementproducttogroup) [Add-AzApiManagementRegion](#add-azapimanagementregion) [Add-AzApiManagementUserToGroup](#add-azapimanagementusertogroup) [Backup-AzApiManagement](#backup-azapimanagement) [Export-AzApiManagementApi](#export-azapimanagementapi) [Get-AzApiManagement](#get-azapimanagement) [Get-AzApiManagementApi](#get-azapimanagementapi) [Get-AzApiManagementApiRelease](#get-azapimanagementapirelease) [Get-AzApiManagementApiRevision](#get-azapimanagementapirevision) [Get-AzApiManagementApiSchema](#get-azapimanagementapischema) [Get-AzApiManagementApiVersionSet](#get-azapimanagementapiversionset) [Get-AzApiManagementAuthorizationServer](#get-azapimanagementauthorizationserver) [Get-AzApiManagementBackend](#get-azapimanagementbackend) [Get-AzApiManagementCache](#get-azapimanagementcache) [Get-AzApiManagementCertificate](#get-azapimanagementcertificate) [Get-AzApiManagementDiagnostic](#get-azapimanagementdiagnostic) [Get-AzApiManagementGroup](#get-azapimanagementgroup) [Get-AzApiManagementIdentityProvider](#get-azapimanagementidentityprovider) [Get-AzApiManagementLogger](#get-azapimanagementlogger) [Get-AzApiManagementNetworkStatus](#get-azapimanagementnetworkstatus) [Get-AzApiManagementOpenIdConnectProvider](#get-azapimanagementopenidconnectprovider) [Get-AzApiManagementOperation](#get-azapimanagementoperation) [Get-AzApiManagementPolicy](#get-azapimanagementpolicy) [Get-AzApiManagementProduct](#get-azapimanagementproduct) [Get-AzApiManagementProperty](#get-azapimanagementproperty) [Get-AzApiManagementSsoToken](#get-azapimanagementssotoken) [Get-AzApiManagementSubscription](#get-azapimanagementsubscription) [Get-AzApiManagementTenantAccess](#get-azapimanagementtenantaccess) [Get-AzApiManagementTenantGitAccess](#get-azapimanagementtenantgitaccess) [Get-AzApiManagementTenantSyncState](#get-azapimanagementtenantsyncstate) [Get-AzApiManagementUser](#get-azapimanagementuser) [Get-AzApiManagementUserSsoUrl](#get-azapimanagementuserssourl) [Import-AzApiManagementApi](#import-azapimanagementapi) [New-AzApiManagement](#new-azapimanagement) [New-AzApiManagementApi](#new-azapimanagementapi) [New-AzApiManagementApiRelease](#new-azapimanagementapirelease) [New-AzApiManagementApiRevision](#new-azapimanagementapirevision) [New-AzApiManagementApiSchema](#new-azapimanagementapischema) [New-AzApiManagementApiVersionSet](#new-azapimanagementapiversionset) [New-AzApiManagementAuthorizationServer](#new-azapimanagementauthorizationserver) [New-AzApiManagementBackend](#new-azapimanagementbackend) [New-AzApiManagementBackendCredential](#new-azapimanagementbackendcredential) [New-AzApiManagementBackendProxy](#new-azapimanagementbackendproxy) [New-AzApiManagementBackendServiceFabric](#new-azapimanagementbackendservicefabric) [New-AzApiManagementCache](#new-azapimanagementcache) [New-AzApiManagementCertificate](#new-azapimanagementcertificate) [New-AzApiManagementContext](#new-azapimanagementcontext) [New-AzApiManagementCustomHostnameConfiguration](#new-azapimanagementcustomhostnameconfiguration) [New-AzApiManagementDiagnostic](#new-azapimanagementdiagnostic) [New-AzApiManagementGroup](#new-azapimanagementgroup) [New-AzApiManagementHttpMessageDiagnostic](#new-azapimanagementhttpmessagediagnostic) [New-AzApiManagementIdentityProvider](#new-azapimanagementidentityprovider) [New-AzApiManagementLogger](#new-azapimanagementlogger) [New-AzApiManagementOpenIdConnectProvider](#new-azapimanagementopenidconnectprovider) [New-AzApiManagementOperation](#new-azapimanagementoperation) [New-AzApiManagementPipelineDiagnosticSetting](#new-azapimanagementpipelinediagnosticsetting) [New-AzApiManagementProduct](#new-azapimanagementproduct) [New-AzApiManagementProperty](#new-azapimanagementproperty) [New-AzApiManagementRegion](#new-azapimanagementregion) [New-AzApiManagementSamplingSetting](#new-azapimanagementsamplingsetting) [New-AzApiManagementSslSetting](#new-azapimanagementsslsetting) [New-AzApiManagementSubscription](#new-azapimanagementsubscription) [New-AzApiManagementSystemCertificate](#new-azapimanagementsystemcertificate) [New-AzApiManagementUser](#new-azapimanagementuser) [New-AzApiManagementUserToken](#new-azapimanagementusertoken) [New-AzApiManagementVirtualNetwork](#new-azapimanagementvirtualnetwork) [Publish-AzApiManagementTenantGitConfiguration](#publish-azapimanagementtenantgitconfiguration) [Remove-AzApiManagement](#remove-azapimanagement) [Remove-AzApiManagementApi](#remove-azapimanagementapi) [Remove-AzApiManagementApiFromProduct](#remove-azapimanagementapifromproduct) [Remove-AzApiManagementApiRelease](#remove-azapimanagementapirelease) [Remove-AzApiManagementApiRevision](#remove-azapimanagementapirevision) [Remove-AzApiManagementApiSchema](#remove-azapimanagementapischema) [Remove-AzApiManagementApiVersionSet](#remove-azapimanagementapiversionset) [Remove-AzApiManagementAuthorizationServer](#remove-azapimanagementauthorizationserver) [Remove-AzApiManagementBackend](#remove-azapimanagementbackend) [Remove-AzApiManagementCache](#remove-azapimanagementcache) [Remove-AzApiManagementCertificate](#remove-azapimanagementcertificate) [Remove-AzApiManagementDiagnostic](#remove-azapimanagementdiagnostic) [Remove-AzApiManagementGroup](#remove-azapimanagementgroup) [Remove-AzApiManagementIdentityProvider](#remove-azapimanagementidentityprovider) [Remove-AzApiManagementLogger](#remove-azapimanagementlogger) [Remove-AzApiManagementOpenIdConnectProvider](#remove-azapimanagementopenidconnectprovider) [Remove-AzApiManagementOperation](#remove-azapimanagementoperation) [Remove-AzApiManagementPolicy](#remove-azapimanagementpolicy) [Remove-AzApiManagementProduct](#remove-azapimanagementproduct) [Remove-AzApiManagementProductFromGroup](#remove-azapimanagementproductfromgroup) [Remove-AzApiManagementProperty](#remove-azapimanagementproperty) [Remove-AzApiManagementRegion](#remove-azapimanagementregion) [Remove-AzApiManagementSubscription](#remove-azapimanagementsubscription) [Remove-AzApiManagementUser](#remove-azapimanagementuser) [Remove-AzApiManagementUserFromGroup](#remove-azapimanagementuserfromgroup) [Restore-AzApiManagement](#restore-azapimanagement) [Save-AzApiManagementTenantGitConfiguration](#save-azapimanagementtenantgitconfiguration) [Set-AzApiManagement](#set-azapimanagement) [Set-AzApiManagementApi](#set-azapimanagementapi) [Set-AzApiManagementApiRevision](#set-azapimanagementapirevision) [Set-AzApiManagementApiSchema](#set-azapimanagementapischema) [Set-AzApiManagementApiVersionSet](#set-azapimanagementapiversionset) [Set-AzApiManagementAuthorizationServer](#set-azapimanagementauthorizationserver) [Set-AzApiManagementBackend](#set-azapimanagementbackend) [Set-AzApiManagementCertificate](#set-azapimanagementcertificate) [Set-AzApiManagementDiagnostic](#set-azapimanagementdiagnostic) [Set-AzApiManagementGroup](#set-azapimanagementgroup) [Set-AzApiManagementIdentityProvider](#set-azapimanagementidentityprovider) [Set-AzApiManagementLogger](#set-azapimanagementlogger) [Set-AzApiManagementOpenIdConnectProvider](#set-azapimanagementopenidconnectprovider) [Set-AzApiManagementOperation](#set-azapimanagementoperation) [Set-AzApiManagementPolicy](#set-azapimanagementpolicy) [Set-AzApiManagementProduct](#set-azapimanagementproduct) [Set-AzApiManagementProperty](#set-azapimanagementproperty) [Set-AzApiManagementSubscription](#set-azapimanagementsubscription) [Set-AzApiManagementTenantAccess](#set-azapimanagementtenantaccess) [Set-AzApiManagementUser](#set-azapimanagementuser) [Update-AzApiManagementApiRelease](#update-azapimanagementapirelease) [Update-AzApiManagementCache](#update-azapimanagementcache) [Update-AzApiManagementRegion](#update-azapimanagementregion)
**Applicationinsights** [Get-AzApplicationInsights](#get-azapplicationinsights) [Get-AzApplicationInsightsApiKey](#get-azapplicationinsightsapikey) [Get-AzApplicationInsightsContinuousExport](#get-azapplicationinsightscontinuousexport) [New-AzApplicationInsights](#new-azapplicationinsights) [New-AzApplicationInsightsApiKey](#new-azapplicationinsightsapikey) [New-AzApplicationInsightsContinuousExport](#new-azapplicationinsightscontinuousexport) [Remove-AzApplicationInsights](#remove-azapplicationinsights) [Remove-AzApplicationInsightsApiKey](#remove-azapplicationinsightsapikey) [Remove-AzApplicationInsightsContinuousExport](#remove-azapplicationinsightscontinuousexport) [Set-AzApplicationInsightsContinuousExport](#set-azapplicationinsightscontinuousexport) [Set-AzApplicationInsightsDailyCap](#set-azapplicationinsightsdailycap) [Set-AzApplicationInsightsPricingPlan](#set-azapplicationinsightspricingplan)
**Attestation** [Get-AzAttestation](#get-azattestation) [New-AzAttestation](#new-azattestation) [Remove-AzAttestation](#remove-azattestation)
**Automation** [Export-AzAutomationDscConfiguration](#export-azautomationdscconfiguration) [Export-AzAutomationDscNodeReportContent](#export-azautomationdscnodereportcontent) [Export-AzAutomationRunbook](#export-azautomationrunbook) [Get-AzAutomationAccount](#get-azautomationaccount) [Get-AzAutomationCertificate](#get-azautomationcertificate) [Get-AzAutomationConnection](#get-azautomationconnection) [Get-AzAutomationCredential](#get-azautomationcredential) [Get-AzAutomationDscCompilationJob](#get-azautomationdsccompilationjob) [Get-AzAutomationDscCompilationJobOutput](#get-azautomationdsccompilationjoboutput) [Get-AzAutomationDscConfiguration](#get-azautomationdscconfiguration) [Get-AzAutomationDscNode](#get-azautomationdscnode) [Get-AzAutomationDscNodeConfiguration](#get-azautomationdscnodeconfiguration) [Get-AzAutomationDscNodeConfigurationDeployment](#get-azautomationdscnodeconfigurationdeployment) [Get-AzAutomationDscNodeConfigurationDeploymentSchedule](#get-azautomationdscnodeconfigurationdeploymentschedule) [Get-AzAutomationDscNodeReport](#get-azautomationdscnodereport) [Get-AzAutomationDscOnboardingMetaconfig](#get-azautomationdsconboardingmetaconfig) [Get-AzAutomationHybridWorkerGroup](#get-azautomationhybridworkergroup) [Get-AzAutomationJob](#get-azautomationjob) [Get-AzAutomationJobOutput](#get-azautomationjoboutput) [Get-AzAutomationJobOutputRecord](#get-azautomationjoboutputrecord) [Get-AzAutomationModule](#get-azautomationmodule) [Get-AzAutomationRegistrationInfo](#get-azautomationregistrationinfo) [Get-AzAutomationRunbook](#get-azautomationrunbook) [Get-AzAutomationSchedule](#get-azautomationschedule) [Get-AzAutomationScheduledRunbook](#get-azautomationscheduledrunbook) [Get-AzAutomationSoftwareUpdateConfiguration](#get-azautomationsoftwareupdateconfiguration) [Get-AzAutomationSoftwareUpdateMachineRun](#get-azautomationsoftwareupdatemachinerun) [Get-AzAutomationSoftwareUpdateRun](#get-azautomationsoftwareupdaterun) [Get-AzAutomationSourceControl](#get-azautomationsourcecontrol) [Get-AzAutomationSourceControlSyncJob](#get-azautomationsourcecontrolsyncjob) [Get-AzAutomationSourceControlSyncJobOutput](#get-azautomationsourcecontrolsyncjoboutput) [Get-AzAutomationVariable](#get-azautomationvariable) [Get-AzAutomationWebhook](#get-azautomationwebhook) [Import-AzAutomationDscConfiguration](#import-azautomationdscconfiguration) [Import-AzAutomationDscNodeConfiguration](#import-azautomationdscnodeconfiguration) [Import-AzAutomationRunbook](#import-azautomationrunbook) [New-AzAutomationAccount](#new-azautomationaccount) [New-AzAutomationCertificate](#new-azautomationcertificate) [New-AzAutomationConnection](#new-azautomationconnection) [New-AzAutomationCredential](#new-azautomationcredential) [New-AzAutomationKey](#new-azautomationkey) [New-AzAutomationModule](#new-azautomationmodule) [New-AzAutomationRunbook](#new-azautomationrunbook) [New-AzAutomationSchedule](#new-azautomationschedule) [New-AzAutomationSoftwareUpdateConfiguration](#new-azautomationsoftwareupdateconfiguration) [New-AzAutomationSourceControl](#new-azautomationsourcecontrol) [New-AzAutomationVariable](#new-azautomationvariable) [New-AzAutomationWebhook](#new-azautomationwebhook) [Publish-AzAutomationRunbook](#publish-azautomationrunbook) [Register-AzAutomationDscNode](#register-azautomationdscnode) [Register-AzAutomationScheduledRunbook](#register-azautomationscheduledrunbook) [Remove-AzAutomationAccount](#remove-azautomationaccount) [Remove-AzAutomationCertificate](#remove-azautomationcertificate) [Remove-AzAutomationConnection](#remove-azautomationconnection) [Remove-AzAutomationConnectionType](#remove-azautomationconnectiontype) [Remove-AzAutomationCredential](#remove-azautomationcredential) [Remove-AzAutomationDscConfiguration](#remove-azautomationdscconfiguration) [Remove-AzAutomationDscNodeConfiguration](#remove-azautomationdscnodeconfiguration) [Remove-AzAutomationHybridWorkerGroup](#remove-azautomationhybridworkergroup) [Remove-AzAutomationModule](#remove-azautomationmodule) [Remove-AzAutomationRunbook](#remove-azautomationrunbook) [Remove-AzAutomationSchedule](#remove-azautomationschedule) [Remove-AzAutomationSoftwareUpdateConfiguration](#remove-azautomationsoftwareupdateconfiguration) [Remove-AzAutomationSourceControl](#remove-azautomationsourcecontrol) [Remove-AzAutomationVariable](#remove-azautomationvariable) [Remove-AzAutomationWebhook](#remove-azautomationwebhook) [Resume-AzAutomationJob](#resume-azautomationjob) [Set-AzAutomationAccount](#set-azautomationaccount) [Set-AzAutomationCertificate](#set-azautomationcertificate) [Set-AzAutomationConnectionFieldValue](#set-azautomationconnectionfieldvalue) [Set-AzAutomationCredential](#set-azautomationcredential) [Set-AzAutomationDscNode](#set-azautomationdscnode) [Set-AzAutomationModule](#set-azautomationmodule) [Set-AzAutomationRunbook](#set-azautomationrunbook) [Set-AzAutomationSchedule](#set-azautomationschedule) [Set-AzAutomationVariable](#set-azautomationvariable) [Set-AzAutomationWebhook](#set-azautomationwebhook) [Start-AzAutomationDscCompilationJob](#start-azautomationdsccompilationjob) [Start-AzAutomationDscNodeConfigurationDeployment](#start-azautomationdscnodeconfigurationdeployment) [Start-AzAutomationRunbook](#start-azautomationrunbook) [Start-AzAutomationSourceControlSyncJob](#start-azautomationsourcecontrolsyncjob) [Stop-AzAutomationDscNodeConfigurationDeployment](#stop-azautomationdscnodeconfigurationdeployment) [Stop-AzAutomationJob](#stop-azautomationjob) [Suspend-AzAutomationJob](#suspend-azautomationjob) [Unregister-AzAutomationDscNode](#unregister-azautomationdscnode) [Unregister-AzAutomationScheduledRunbook](#unregister-azautomationscheduledrunbook) [Update-AzAutomationSourceControl](#update-azautomationsourcecontrol)
**Batch** [Disable-AzBatchAutoScale](#disable-azbatchautoscale) [Disable-AzBatchComputeNodeScheduling](#disable-azbatchcomputenodescheduling) [Disable-AzBatchJob](#disable-azbatchjob) [Disable-AzBatchJobSchedule](#disable-azbatchjobschedule) [Enable-AzBatchAutoScale](#enable-azbatchautoscale) [Enable-AzBatchComputeNodeScheduling](#enable-azbatchcomputenodescheduling) [Enable-AzBatchJob](#enable-azbatchjob) [Enable-AzBatchJobSchedule](#enable-azbatchjobschedule) [Enable-AzBatchTask](#enable-azbatchtask) [Get-AzBatchAccount](#get-azbatchaccount) [Get-AzBatchAccountKey](#get-azbatchaccountkey) [Get-AzBatchApplication](#get-azbatchapplication) [Get-AzBatchApplicationPackage](#get-azbatchapplicationpackage) [Get-AzBatchCertificate](#get-azbatchcertificate) [Get-AzBatchComputeNode](#get-azbatchcomputenode) [Get-AzBatchJob](#get-azbatchjob) [Get-AzBatchJobPreparationAndReleaseTaskStatus](#get-azbatchjobpreparationandreleasetaskstatus) [Get-AzBatchJobSchedule](#get-azbatchjobschedule) [Get-AzBatchJobStatistic](#get-azbatchjobstatistic) [Get-AzBatchLocationQuota](#get-azbatchlocationquota) [Get-AzBatchNodeAgentSku](#get-azbatchnodeagentsku) [Get-AzBatchNodeFile](#get-azbatchnodefile) [Get-AzBatchNodeFileContent](#get-azbatchnodefilecontent) [Get-AzBatchPool](#get-azbatchpool) [Get-AzBatchPoolNodeCount](#get-azbatchpoolnodecount) [Get-AzBatchPoolStatistic](#get-azbatchpoolstatistic) [Get-AzBatchPoolUsageMetric](#get-azbatchpoolusagemetric) [Get-AzBatchRemoteDesktopProtocolFile](#get-azbatchremotedesktopprotocolfile) [Get-AzBatchRemoteLoginSetting](#get-azbatchremoteloginsetting) [Get-AzBatchSubtask](#get-azbatchsubtask) [Get-AzBatchTask](#get-azbatchtask) [Get-AzBatchTaskCount](#get-azbatchtaskcount) [New-AzBatchAccount](#new-azbatchaccount) [New-AzBatchAccountKey](#new-azbatchaccountkey) [New-AzBatchApplication](#new-azbatchapplication) [New-AzBatchApplicationPackage](#new-azbatchapplicationpackage) [New-AzBatchCertificate](#new-azbatchcertificate) [New-AzBatchComputeNodeUser](#new-azbatchcomputenodeuser) [New-AzBatchJob](#new-azbatchjob) [New-AzBatchJobSchedule](#new-azbatchjobschedule) [New-AzBatchPool](#new-azbatchpool) [New-AzBatchTask](#new-azbatchtask) [Remove-AzBatchAccount](#remove-azbatchaccount) [Remove-AzBatchApplication](#remove-azbatchapplication) [Remove-AzBatchApplicationPackage](#remove-azbatchapplicationpackage) [Remove-AzBatchCertificate](#remove-azbatchcertificate) [Remove-AzBatchComputeNode](#remove-azbatchcomputenode) [Remove-AzBatchComputeNodeUser](#remove-azbatchcomputenodeuser) [Remove-AzBatchJob](#remove-azbatchjob) [Remove-AzBatchJobSchedule](#remove-azbatchjobschedule) [Remove-AzBatchNodeFile](#remove-azbatchnodefile) [Remove-AzBatchPool](#remove-azbatchpool) [Remove-AzBatchTask](#remove-azbatchtask) [Reset-AzBatchComputeNode](#reset-azbatchcomputenode) [Restart-AzBatchComputeNode](#restart-azbatchcomputenode) [Set-AzBatchAccount](#set-azbatchaccount) [Set-AzBatchApplication](#set-azbatchapplication) [Set-AzBatchComputeNodeUser](#set-azbatchcomputenodeuser) [Set-AzBatchJob](#set-azbatchjob) [Set-AzBatchJobSchedule](#set-azbatchjobschedule) [Set-AzBatchPool](#set-azbatchpool) [Set-AzBatchPoolOSVersion](#set-azbatchpoolosversion) [Set-AzBatchTask](#set-azbatchtask) [Start-AzBatchComputeNodeServiceLogUpload](#start-azbatchcomputenodeservicelogupload) [Start-AzBatchPoolResize](#start-azbatchpoolresize) [Stop-AzBatchCertificateDeletion](#stop-azbatchcertificatedeletion) [Stop-AzBatchJob](#stop-azbatchjob) [Stop-AzBatchJobSchedule](#stop-azbatchjobschedule) [Stop-AzBatchPoolResize](#stop-azbatchpoolresize) [Stop-AzBatchTask](#stop-azbatchtask) [Test-AzBatchAutoScale](#test-azbatchautoscale)
**Billing** [Get-AzBillingInvoice](#get-azbillinginvoice) [Get-AzBillingPeriod](#get-azbillingperiod) [Get-AzConsumptionBudget](#get-azconsumptionbudget) [Get-AzConsumptionMarketplace](#get-azconsumptionmarketplace) [Get-AzConsumptionPriceSheet](#get-azconsumptionpricesheet) [Get-AzConsumptionReservationDetail](#get-azconsumptionreservationdetail) [Get-AzConsumptionReservationSummary](#get-azconsumptionreservationsummary) [Get-AzConsumptionUsageDetail](#get-azconsumptionusagedetail) [Get-AzEnrollmentAccount](#get-azenrollmentaccount) [Get-UsageAggregates](#get-usageaggregates) [New-AzConsumptionBudget](#new-azconsumptionbudget) [Remove-AzConsumptionBudget](#remove-azconsumptionbudget) [Set-AzConsumptionBudget](#set-azconsumptionbudget)
**Blueprint** [Export-AzBlueprintWithArtifact](#export-azblueprintwithartifact) [Get-AzBlueprint](#get-azblueprint) [Get-AzBlueprintArtifact](#get-azblueprintartifact) [Get-AzBlueprintAssignment](#get-azblueprintassignment) [Import-AzBlueprintWithArtifact](#import-azblueprintwithartifact) [New-AzBlueprint](#new-azblueprint) [New-AzBlueprintArtifact](#new-azblueprintartifact) [New-AzBlueprintAssignment](#new-azblueprintassignment) [Publish-AzBlueprint](#publish-azblueprint) [Remove-AzBlueprintAssignment](#remove-azblueprintassignment) [Set-AzBlueprint](#set-azblueprint) [Set-AzBlueprintArtifact](#set-azblueprintartifact) [Set-AzBlueprintAssignment](#set-azblueprintassignment)
**Cdn** [Confirm-AzCdnEndpointProbeURL](#confirm-azcdnendpointprobeurl) [Disable-AzCdnCustomDomain](#disable-azcdncustomdomain) [Disable-AzCdnCustomDomainHttps](#disable-azcdncustomdomainhttps) [Enable-AzCdnCustomDomain](#enable-azcdncustomdomain) [Enable-AzCdnCustomDomainHttps](#enable-azcdncustomdomainhttps) [Get-AzCdnCustomDomain](#get-azcdncustomdomain) [Get-AzCdnEdgeNode](#get-azcdnedgenode) [Get-AzCdnEndpoint](#get-azcdnendpoint) [Get-AzCdnEndpointNameAvailability](#get-azcdnendpointnameavailability) [Get-AzCdnEndpointResourceUsage](#get-azcdnendpointresourceusage) [Get-AzCdnOrigin](#get-azcdnorigin) [Get-AzCdnProfile](#get-azcdnprofile) [Get-AzCdnProfileResourceUsage](#get-azcdnprofileresourceusage) [Get-AzCdnProfileSsoUrl](#get-azcdnprofilessourl) [Get-AzCdnProfileSupportedOptimizationType](#get-azcdnprofilesupportedoptimizationtype) [Get-AzCdnSubscriptionResourceUsage](#get-azcdnsubscriptionresourceusage) [New-AzCdnCustomDomain](#new-azcdncustomdomain) [New-AzCdnDeliveryPolicy](#new-azcdndeliverypolicy) [New-AzCdnDeliveryRule](#new-azcdndeliveryrule) [New-AzCdnDeliveryRuleAction](#new-azcdndeliveryruleaction) [New-AzCdnDeliveryRuleCondition](#new-azcdndeliveryrulecondition) [New-AzCdnEndpoint](#new-azcdnendpoint) [New-AzCdnProfile](#new-azcdnprofile) [Publish-AzCdnEndpointContent](#publish-azcdnendpointcontent) [Remove-AzCdnCustomDomain](#remove-azcdncustomdomain) [Remove-AzCdnEndpoint](#remove-azcdnendpoint) [Remove-AzCdnProfile](#remove-azcdnprofile) [Set-AzCdnEndpoint](#set-azcdnendpoint) [Set-AzCdnOrigin](#set-azcdnorigin) [Set-AzCdnProfile](#set-azcdnprofile) [Start-AzCdnEndpoint](#start-azcdnendpoint) [Stop-AzCdnEndpoint](#stop-azcdnendpoint) [Test-AzCdnCustomDomain](#test-azcdncustomdomain) [Unpublish-AzCdnEndpointContent](#unpublish-azcdnendpointcontent)
**Cognitiveservices** [Add-AzCognitiveServicesAccountNetworkRule](#add-azcognitiveservicesaccountnetworkrule) [Get-AzCognitiveServicesAccount](#get-azcognitiveservicesaccount) [Get-AzCognitiveServicesAccountKey](#get-azcognitiveservicesaccountkey) [Get-AzCognitiveServicesAccountNetworkRuleSet](#get-azcognitiveservicesaccountnetworkruleset) [Get-AzCognitiveServicesAccountSku](#get-azcognitiveservicesaccountsku) [Get-AzCognitiveServicesAccountType](#get-azcognitiveservicesaccounttype) [Get-AzCognitiveServicesAccountUsage](#get-azcognitiveservicesaccountusage) [New-AzCognitiveServicesAccount](#new-azcognitiveservicesaccount) [New-AzCognitiveServicesAccountKey](#new-azcognitiveservicesaccountkey) [Remove-AzCognitiveServicesAccount](#remove-azcognitiveservicesaccount) [Remove-AzCognitiveServicesAccountNetworkRule](#remove-azcognitiveservicesaccountnetworkrule) [Set-AzCognitiveServicesAccount](#set-azcognitiveservicesaccount) [Update-AzCognitiveServicesAccountNetworkRuleSet](#update-azcognitiveservicesaccountnetworkruleset)
**Compute** [Add-AzContainerServiceAgentPoolProfile](#add-azcontainerserviceagentpoolprofile) [Add-AzImageDataDisk](#add-azimagedatadisk) [Add-AzVhd](#add-azvhd) [Add-AzVMAdditionalUnattendContent](#add-azvmadditionalunattendcontent) [**Add-AzVMDataDisk**](#add-azvmdatadisk) [**Add-AzVMNetworkInterface**](#add-azvmnetworkinterface) [Add-AzVMSecret](#add-azvmsecret) [Add-AzVmssAdditionalUnattendContent](#add-azvmssadditionalunattendcontent) [Add-AzVmssDataDisk](#add-azvmssdatadisk) [Add-AzVmssDiagnosticsExtension](#add-azvmssdiagnosticsextension) [**Add-AzVmssExtension**](#add-azvmssextension) [Add-AzVMSshPublicKey](#add-azvmsshpublickey) [**Add-AzVmssNetworkInterfaceConfiguration**](#add-azvmssnetworkinterfaceconfiguration) [Add-AzVmssSecret](#add-azvmsssecret) [Add-AzVmssSshPublicKey](#add-azvmsssshpublickey) [Add-AzVmssVMDataDisk](#add-azvmssvmdatadisk) [Add-AzVmssWinRMListener](#add-azvmsswinrmlistener) [ConvertTo-AzVMManagedDisk](#convertto-azvmmanageddisk) [Disable-AzVMDiskEncryption](#disable-azvmdiskencryption) [Disable-AzVmssDiskEncryption](#disable-azvmssdiskencryption) [Export-AzLogAnalyticRequestRateByInterval](#export-azloganalyticrequestratebyinterval) [Export-AzLogAnalyticThrottledRequest](#export-azloganalyticthrottledrequest) [Get-AzAvailabilitySet](#get-azavailabilityset) [Get-AzComputeResourceSku](#get-azcomputeresourcesku) [Get-AzContainerService](#get-azcontainerservice) [Get-AzDisk](#get-azdisk) [Get-AzGallery](#get-azgallery) [Get-AzGalleryImageDefinition](#get-azgalleryimagedefinition) [Get-AzGalleryImageVersion](#get-azgalleryimageversion) [**Get-AzImage**](#get-azimage) [Get-AzProximityPlacementGroup](#get-azproximityplacementgroup) [**Get-AzRemoteDesktopFile**](#get-azremotedesktopfile) [Get-AzSnapshot](#get-azsnapshot) [**Get-AzVM**](#get-azvm) [Get-AzVMAccessExtension](#get-azvmaccessextension) [Get-AzVMADDomainExtension](#get-azvmaddomainextension) [Get-AzVMAEMExtension](#get-azvmaemextension) [Get-AzVMBootDiagnosticsData](#get-azvmbootdiagnosticsdata) [Get-AzVMChefExtension](#get-azvmchefextension) [Get-AzVMCustomScriptExtension](#get-azvmcustomscriptextension) [Get-AzVMDiagnosticsExtension](#get-azvmdiagnosticsextension) [Get-AzVMDiskEncryptionStatus](#get-azvmdiskencryptionstatus) [Get-AzVMDscExtension](#get-azvmdscextension) [Get-AzVMDscExtensionStatus](#get-azvmdscextensionstatus) [Get-AzVMExtension](#get-azvmextension) [Get-AzVMExtensionImage](#get-azvmextensionimage) [Get-AzVMExtensionImageType](#get-azvmextensionimagetype) [Get-AzVMImage](#get-azvmimage) [Get-AzVMImageOffer](#get-azvmimageoffer) [Get-AzVMImagePublisher](#get-azvmimagepublisher) [Get-AzVMImageSku](#get-azvmimagesku) [Get-AzVMRunCommandDocument](#get-azvmruncommanddocument) [**Get-AzVMSize**](#get-azvmsize) [Get-AzVMSqlServerExtension](#get-azvmsqlserverextension) [Get-AzVmss](#get-azvmss) [Get-AzVmssDiskEncryption](#get-azvmssdiskencryption) [Get-AzVmssRollingUpgrade](#get-azvmssrollingupgrade) [Get-AzVmssSku](#get-azvmsssku) [Get-AzVmssVM](#get-azvmssvm) [Get-AzVmssVMDiskEncryption](#get-azvmssvmdiskencryption) [**Get-AzVMUsage**](#get-azvmusage) [Grant-AzDiskAccess](#grant-azdiskaccess) [Grant-AzSnapshotAccess](#grant-azsnapshotaccess) [Invoke-AzVMReimage](#invoke-azvmreimage) [Invoke-AzVMRunCommand](#invoke-azvmruncommand) [Invoke-AzVmssVMRunCommand](#invoke-azvmssvmruncommand) [**New-AzAvailabilitySet**](#new-azavailabilityset) [New-AzContainerService](#new-azcontainerservice) [New-AzContainerServiceConfig](#new-azcontainerserviceconfig) [New-AzDisk](#new-azdisk) [**New-AzDiskConfig**](#new-azdiskconfig) [New-AzDiskUpdateConfig](#new-azdiskupdateconfig) [New-AzGallery](#new-azgallery) [New-AzGalleryImageDefinition](#new-azgalleryimagedefinition) [New-AzGalleryImageVersion](#new-azgalleryimageversion) [**New-AzImage**](#new-azimage) [**New-AzImageConfig**](#new-azimageconfig) [New-AzProximityPlacementGroup](#new-azproximityplacementgroup) [New-AzSnapshot](#new-azsnapshot) [New-AzSnapshotConfig](#new-azsnapshotconfig) [New-AzSnapshotUpdateConfig](#new-azsnapshotupdateconfig) [New-AzVM](#new-azvm) [**New-AzVMConfig**](#new-azvmconfig) [New-AzVMDataDisk](#new-azvmdatadisk) [New-AzVMSqlServerAutoBackupConfig](#new-azvmsqlserverautobackupconfig) [New-AzVMSqlServerAutoPatchingConfig](#new-azvmsqlserverautopatchingconfig) [New-AzVMSqlServerKeyVaultCredentialConfig](#new-azvmsqlserverkeyvaultcredentialconfig) [**New-AzVmss**](#new-azvmss) [New-AzVmssConfig](#new-azvmssconfig) [**New-AzVmssIpConfig**](#new-azvmssipconfig) [New-AzVmssIpTagConfig](#new-azvmssiptagconfig) [New-AzVmssVaultCertificateConfig](#new-azvmssvaultcertificateconfig) [**Publish-AzVMDscConfiguration**](#publish-azvmdscconfiguration) [Remove-AzAvailabilitySet](#remove-azavailabilityset) [Remove-AzContainerService](#remove-azcontainerservice) [Remove-AzContainerServiceAgentPoolProfile](#remove-azcontainerserviceagentpoolprofile) [Remove-AzDisk](#remove-azdisk) [Remove-AzGallery](#remove-azgallery) [Remove-AzGalleryImageDefinition](#remove-azgalleryimagedefinition) [Remove-AzGalleryImageVersion](#remove-azgalleryimageversion) [Remove-AzImage](#remove-azimage) [Remove-AzImageDataDisk](#remove-azimagedatadisk) [Remove-AzProximityPlacementGroup](#remove-azproximityplacementgroup) [Remove-AzSnapshot](#remove-azsnapshot) [Remove-AzVM](#remove-azvm) [Remove-AzVMAccessExtension](#remove-azvmaccessextension) [Remove-AzVMAEMExtension](#remove-azvmaemextension) [Remove-AzVMBackup](#remove-azvmbackup) [Remove-AzVMChefExtension](#remove-azvmchefextension) [Remove-AzVMCustomScriptExtension](#remove-azvmcustomscriptextension) [Remove-AzVMDataDisk](#remove-azvmdatadisk) [Remove-AzVMDiagnosticsExtension](#remove-azvmdiagnosticsextension) [Remove-AzVMDiskEncryptionExtension](#remove-azvmdiskencryptionextension) [Remove-AzVMDscExtension](#remove-azvmdscextension) [Remove-AzVMExtension](#remove-azvmextension) [Remove-AzVMNetworkInterface](#remove-azvmnetworkinterface) [Remove-AzVMSecret](#remove-azvmsecret) [Remove-AzVMSqlServerExtension](#remove-azvmsqlserverextension) [Remove-AzVmss](#remove-azvmss) [Remove-AzVmssDataDisk](#remove-azvmssdatadisk) [Remove-AzVmssDiagnosticsExtension](#remove-azvmssdiagnosticsextension) [Remove-AzVmssExtension](#remove-azvmssextension) [Remove-AzVmssNetworkInterfaceConfiguration](#remove-azvmssnetworkinterfaceconfiguration) [Remove-AzVmssVMDataDisk](#remove-azvmssvmdatadisk) [Repair-AzVmssServiceFabricUpdateDomain](#repair-azvmssservicefabricupdatedomain) [**Restart-AzVM**](#restart-azvm) [Restart-AzVmss](#restart-azvmss) [Revoke-AzDiskAccess](#revoke-azdiskaccess) [Revoke-AzSnapshotAccess](#revoke-azsnapshotaccess) [Save-AzVhd](#save-azvhd) [Save-AzVMImage](#save-azvmimage) [Set-AzDiskDiskEncryptionKey](#set-azdiskdiskencryptionkey) [Set-AzDiskImageReference](#set-azdiskimagereference) [Set-AzDiskKeyEncryptionKey](#set-azdiskkeyencryptionkey) [Set-AzDiskUpdateDiskEncryptionKey](#set-azdiskupdatediskencryptionkey) [Set-AzDiskUpdateKeyEncryptionKey](#set-azdiskupdatekeyencryptionkey) [Set-AzImageOsDisk](#set-azimageosdisk) [Set-AzSnapshotDiskEncryptionKey](#set-azsnapshotdiskencryptionkey) [Set-AzSnapshotImageReference](#set-azsnapshotimagereference) [Set-AzSnapshotKeyEncryptionKey](#set-azsnapshotkeyencryptionkey) [Set-AzSnapshotUpdateDiskEncryptionKey](#set-azsnapshotupdatediskencryptionkey) [Set-AzSnapshotUpdateKeyEncryptionKey](#set-azsnapshotupdatekeyencryptionkey) [**Set-AzVM**](#set-azvm) [Set-AzVMAccessExtension](#set-azvmaccessextension) [Set-AzVMADDomainExtension](#set-azvmaddomainextension) [Set-AzVMAEMExtension](#set-azvmaemextension) [Set-AzVMBackupExtension](#set-azvmbackupextension) [Set-AzVMBginfoExtension](#set-azvmbginfoextension) [Set-AzVMBootDiagnostic](#set-azvmbootdiagnostic) [Set-AzVMChefExtension](#set-azvmchefextension) [**Set-AzVMCustomScriptExtension**](#set-azvmcustomscriptextension) [**Set-AzVMDataDisk**](#set-azvmdatadisk) [Set-AzVMDiagnosticsExtension](#set-azvmdiagnosticsextension) [Set-AzVMDiskEncryptionExtension](#set-azvmdiskencryptionextension) [**Set-AzVMDscExtension**](#set-azvmdscextension) [**Set-AzVMExtension**](#set-azvmextension) [**Set-AzVMOperatingSystem**](#set-azvmoperatingsystem) [**Set-AzVMOSDisk**](#set-azvmosdisk) [Set-AzVMPlan](#set-azvmplan) [**Set-AzVMSourceImage**](#set-azvmsourceimage) [Set-AzVMSqlServerExtension](#set-azvmsqlserverextension) [Set-AzVmss](#set-azvmss) [Set-AzVmssBootDiagnostic](#set-azvmssbootdiagnostic) [Set-AzVmssDiskEncryptionExtension](#set-azvmssdiskencryptionextension) [**Set-AzVmssOsProfile**](#set-azvmssosprofile) [Set-AzVmssRollingUpgradePolicy](#set-azvmssrollingupgradepolicy) [**Set-AzVmssStorageProfile**](#set-azvmssstorageprofile) [Set-AzVmssVM](#set-azvmssvm) [Start-AzVM](#start-azvm) [Start-AzVmss](#start-azvmss) [Start-AzVmssRollingOSUpgrade](#start-azvmssrollingosupgrade) [**Stop-AzVM**](#stop-azvm) [Stop-AzVmss](#stop-azvmss) [Stop-AzVmssRollingUpgrade](#stop-azvmssrollingupgrade) [Test-AzVMAEMExtension](#test-azvmaemextension) [Update-AzAvailabilitySet](#update-azavailabilityset) [Update-AzContainerService](#update-azcontainerservice) [Update-AzDisk](#update-azdisk) [Update-AzGallery](#update-azgallery) [Update-AzGalleryImageDefinition](#update-azgalleryimagedefinition) [Update-AzGalleryImageVersion](#update-azgalleryimageversion) [Update-AzImage](#update-azimage) [Update-AzSnapshot](#update-azsnapshot) [**Update-AzVM**](#update-azvm) [Update-AzVmss](#update-azvmss) [Update-AzVmssInstance](#update-azvmssinstance) [Update-AzVmssVM](#update-azvmssvm)
**Containerinstance** [Get-AzContainerGroup](#get-azcontainergroup) [Get-AzContainerInstanceLog](#get-azcontainerinstancelog) [New-AzContainerGroup](#new-azcontainergroup)
**Containerregistry** [Get-AzContainerRegistry](#get-azcontainerregistry) [Get-AzContainerRegistryCredential](#get-azcontainerregistrycredential) [Get-AzContainerRegistryReplication](#get-azcontainerregistryreplication) [Get-AzContainerRegistryWebhook](#get-azcontainerregistrywebhook) [Get-AzContainerRegistryWebhookEvent](#get-azcontainerregistrywebhookevent) [New-AzContainerRegistry](#new-azcontainerregistry) [New-AzContainerRegistryReplication](#new-azcontainerregistryreplication) [New-AzContainerRegistryWebhook](#new-azcontainerregistrywebhook) [Remove-AzContainerGroup](#remove-azcontainergroup) [Remove-AzContainerRegistry](#remove-azcontainerregistry) [Remove-AzContainerRegistryReplication](#remove-azcontainerregistryreplication) [Remove-AzContainerRegistryWebhook](#remove-azcontainerregistrywebhook) [Test-AzContainerRegistryNameAvailability](#test-azcontainerregistrynameavailability) [Test-AzContainerRegistryWebhook](#test-azcontainerregistrywebhook) [Update-AzContainerRegistry](#update-azcontainerregistry) [Update-AzContainerRegistryCredential](#update-azcontainerregistrycredential) [Update-AzContainerRegistryWebhook](#update-azcontainerregistrywebhook)
**Databox** [Get-AzDataBoxCredential](#get-azdataboxcredential) [Get-AzDataBoxJob](#get-azdataboxjob) [New-AzDataBoxJob](#new-azdataboxjob) [Remove-AzDataBoxJob](#remove-azdataboxjob) [Stop-AzDataBoxJob](#stop-azdataboxjob)
**Datafactory** [Get-AzDataFactory](#get-azdatafactory) [Get-AzDataFactoryActivityWindow](#get-azdatafactoryactivitywindow) [Get-AzDataFactoryDataset](#get-azdatafactorydataset) [Get-AzDataFactoryGateway](#get-azdatafactorygateway) [Get-AzDataFactoryGatewayAuthKey](#get-azdatafactorygatewayauthkey) [Get-AzDataFactoryHub](#get-azdatafactoryhub) [Get-AzDataFactoryLinkedService](#get-azdatafactorylinkedservice) [Get-AzDataFactoryPipeline](#get-azdatafactorypipeline) [Get-AzDataFactoryRun](#get-azdatafactoryrun) [Get-AzDataFactorySlice](#get-azdatafactoryslice) [Get-AzDataFactoryV2](#get-azdatafactoryv2) [Get-AzDataFactoryV2ActivityRun](#get-azdatafactoryv2activityrun) [Get-AzDataFactoryV2Dataset](#get-azdatafactoryv2dataset) [Get-AzDataFactoryV2IntegrationRuntime](#get-azdatafactoryv2integrationruntime) [Get-AzDataFactoryV2IntegrationRuntimeKey](#get-azdatafactoryv2integrationruntimekey) [Get-AzDataFactoryV2IntegrationRuntimeMetric](#get-azdatafactoryv2integrationruntimemetric) [Get-AzDataFactoryV2IntegrationRuntimeNode](#get-azdatafactoryv2integrationruntimenode) [Get-AzDataFactoryV2LinkedService](#get-azdatafactoryv2linkedservice) [Get-AzDataFactoryV2Pipeline](#get-azdatafactoryv2pipeline) [Get-AzDataFactoryV2PipelineRun](#get-azdatafactoryv2pipelinerun) [Get-AzDataFactoryV2Trigger](#get-azdatafactoryv2trigger) [Get-AzDataFactoryV2TriggerRun](#get-azdatafactoryv2triggerrun) [Invoke-AzDataFactoryV2IntegrationRuntimeUpgrade](#invoke-azdatafactoryv2integrationruntimeupgrade) [Invoke-AzDataFactoryV2Pipeline](#invoke-azdatafactoryv2pipeline) [New-AzDataFactory](#new-azdatafactory) [New-AzDataFactoryDataset](#new-azdatafactorydataset) [New-AzDataFactoryEncryptValue](#new-azdatafactoryencryptvalue) [New-AzDataFactoryGateway](#new-azdatafactorygateway) [New-AzDataFactoryGatewayAuthKey](#new-azdatafactorygatewayauthkey) [New-AzDataFactoryHub](#new-azdatafactoryhub) [New-AzDataFactoryLinkedService](#new-azdatafactorylinkedservice) [New-AzDataFactoryPipeline](#new-azdatafactorypipeline) [New-AzDataFactoryV2IntegrationRuntimeKey](#new-azdatafactoryv2integrationruntimekey) [New-AzDataFactoryV2LinkedServiceEncryptedCredential](#new-azdatafactoryv2linkedserviceencryptedcredential) [Remove-AzDataFactory](#remove-azdatafactory) [Remove-AzDataFactoryDataset](#remove-azdatafactorydataset) [Remove-AzDataFactoryGateway](#remove-azdatafactorygateway) [Remove-AzDataFactoryHub](#remove-azdatafactoryhub) [Remove-AzDataFactoryLinkedService](#remove-azdatafactorylinkedservice) [Remove-AzDataFactoryPipeline](#remove-azdatafactorypipeline) [Remove-AzDataFactoryV2](#remove-azdatafactoryv2) [Remove-AzDataFactoryV2Dataset](#remove-azdatafactoryv2dataset) [Remove-AzDataFactoryV2IntegrationRuntime](#remove-azdatafactoryv2integrationruntime) [Remove-AzDataFactoryV2IntegrationRuntimeNode](#remove-azdatafactoryv2integrationruntimenode) [Remove-AzDataFactoryV2LinkedService](#remove-azdatafactoryv2linkedservice) [Remove-AzDataFactoryV2Pipeline](#remove-azdatafactoryv2pipeline) [Remove-AzDataFactoryV2Trigger](#remove-azdatafactoryv2trigger) [Resume-AzDataFactoryPipeline](#resume-azdatafactorypipeline) [Save-AzDataFactoryLog](#save-azdatafactorylog) [Set-AzDataFactoryGateway](#set-azdatafactorygateway) [Set-AzDataFactoryPipelineActivePeriod](#set-azdatafactorypipelineactiveperiod) [Set-AzDataFactorySliceStatus](#set-azdatafactoryslicestatus) [Set-AzDataFactoryV2](#set-azdatafactoryv2) [Set-AzDataFactoryV2Dataset](#set-azdatafactoryv2dataset) [Set-AzDataFactoryV2IntegrationRuntime](#set-azdatafactoryv2integrationruntime) [Set-AzDataFactoryV2LinkedService](#set-azdatafactoryv2linkedservice) [Set-AzDataFactoryV2Pipeline](#set-azdatafactoryv2pipeline) [Set-AzDataFactoryV2Trigger](#set-azdatafactoryv2trigger) [Start-AzDataFactoryV2IntegrationRuntime](#start-azdatafactoryv2integrationruntime) [Start-AzDataFactoryV2Trigger](#start-azdatafactoryv2trigger) [Stop-AzDataFactoryV2IntegrationRuntime](#stop-azdatafactoryv2integrationruntime) [Stop-AzDataFactoryV2PipelineRun](#stop-azdatafactoryv2pipelinerun) [Stop-AzDataFactoryV2Trigger](#stop-azdatafactoryv2trigger) [Suspend-AzDataFactoryPipeline](#suspend-azdatafactorypipeline) [Sync-AzDataFactoryV2IntegrationRuntimeCredential](#sync-azdatafactoryv2integrationruntimecredential) [Update-AzDataFactoryV2](#update-azdatafactoryv2) [Update-AzDataFactoryV2IntegrationRuntime](#update-azdatafactoryv2integrationruntime) [Update-AzDataFactoryV2IntegrationRuntimeNode](#update-azdatafactoryv2integrationruntimenode)
**Datalakeanalytics** [Add-AzDataLakeAnalyticsDataSource](#add-azdatalakeanalyticsdatasource) [Add-AzDataLakeAnalyticsFirewallRule](#add-azdatalakeanalyticsfirewallrule) [Get-AzDataLakeAnalyticsAccount](#get-azdatalakeanalyticsaccount) [Get-AzDataLakeAnalyticsCatalogItem](#get-azdatalakeanalyticscatalogitem) [Get-AzDataLakeAnalyticsCatalogItemAclEntry](#get-azdatalakeanalyticscatalogitemaclentry) [Get-AzDataLakeAnalyticsComputePolicy](#get-azdatalakeanalyticscomputepolicy) [Get-AzDataLakeAnalyticsDataSource](#get-azdatalakeanalyticsdatasource) [Get-AzDataLakeAnalyticsFirewallRule](#get-azdatalakeanalyticsfirewallrule) [Get-AzDataLakeAnalyticsJob](#get-azdatalakeanalyticsjob) [Get-AzDataLakeAnalyticsJobPipeline](#get-azdatalakeanalyticsjobpipeline) [Get-AzDataLakeAnalyticsJobRecurrence](#get-azdatalakeanalyticsjobrecurrence) [New-AzDataLakeAnalyticsAccount](#new-azdatalakeanalyticsaccount) [New-AzDataLakeAnalyticsCatalogCredential](#new-azdatalakeanalyticscatalogcredential) [New-AzDataLakeAnalyticsComputePolicy](#new-azdatalakeanalyticscomputepolicy) [Remove-AzDataLakeAnalyticsAccount](#remove-azdatalakeanalyticsaccount) [Remove-AzDataLakeAnalyticsCatalogCredential](#remove-azdatalakeanalyticscatalogcredential) [Remove-AzDataLakeAnalyticsCatalogItemAclEntry](#remove-azdatalakeanalyticscatalogitemaclentry) [Remove-AzDataLakeAnalyticsComputePolicy](#remove-azdatalakeanalyticscomputepolicy) [Remove-AzDataLakeAnalyticsDataSource](#remove-azdatalakeanalyticsdatasource) [Remove-AzDataLakeAnalyticsFirewallRule](#remove-azdatalakeanalyticsfirewallrule) [Set-AzDataLakeAnalyticsAccount](#set-azdatalakeanalyticsaccount) [Set-AzDataLakeAnalyticsCatalogCredential](#set-azdatalakeanalyticscatalogcredential) [Set-AzDataLakeAnalyticsCatalogItemAclEntry](#set-azdatalakeanalyticscatalogitemaclentry) [Set-AzDataLakeAnalyticsDataSource](#set-azdatalakeanalyticsdatasource) [Set-AzDataLakeAnalyticsFirewallRule](#set-azdatalakeanalyticsfirewallrule) [Stop-AzDataLakeAnalyticsJob](#stop-azdatalakeanalyticsjob) [Submit-AzDataLakeAnalyticsJob](#submit-azdatalakeanalyticsjob) [Test-AzDataLakeAnalyticsAccount](#test-azdatalakeanalyticsaccount) [Test-AzDataLakeAnalyticsCatalogItem](#test-azdatalakeanalyticscatalogitem) [Update-AzDataLakeAnalyticsComputePolicy](#update-azdatalakeanalyticscomputepolicy) [Wait-AzDataLakeAnalyticsJob](#wait-azdatalakeanalyticsjob)
**Datalakestore** [Add-AzDataLakeStoreFirewallRule](#add-azdatalakestorefirewallrule) [Add-AzDataLakeStoreItemContent](#add-azdatalakestoreitemcontent) [Add-AzDataLakeStoreTrustedIdProvider](#add-azdatalakestoretrustedidprovider) [Add-AzDataLakeStoreVirtualNetworkRule](#add-azdatalakestorevirtualnetworkrule) [Enable-AzDataLakeStoreKeyVault](#enable-azdatalakestorekeyvault) [Export-AzDataLakeStoreChildItemProperty](#export-azdatalakestorechilditemproperty) [Export-AzDataLakeStoreItem](#export-azdatalakestoreitem) [Get-AzDataLakeStoreAccount](#get-azdatalakestoreaccount) [Get-AzDataLakeStoreChildItem](#get-azdatalakestorechilditem) [Get-AzDataLakeStoreChildItemSummary](#get-azdatalakestorechilditemsummary) [Get-AzDataLakeStoreFirewallRule](#get-azdatalakestorefirewallrule) [Get-AzDataLakeStoreItem](#get-azdatalakestoreitem) [Get-AzDataLakeStoreItemAclEntry](#get-azdatalakestoreitemaclentry) [Get-AzDataLakeStoreItemContent](#get-azdatalakestoreitemcontent) [Get-AzDataLakeStoreItemOwner](#get-azdatalakestoreitemowner) [Get-AzDataLakeStoreItemPermission](#get-azdatalakestoreitempermission) [Get-AzDataLakeStoreTrustedIdProvider](#get-azdatalakestoretrustedidprovider) [Get-AzDataLakeStoreVirtualNetworkRule](#get-azdatalakestorevirtualnetworkrule) [Import-AzDataLakeStoreItem](#import-azdatalakestoreitem) [Join-AzDataLakeStoreItem](#join-azdatalakestoreitem) [Move-AzDataLakeStoreItem](#move-azdatalakestoreitem) [New-AzDataLakeStoreAccount](#new-azdatalakestoreaccount) [New-AzDataLakeStoreItem](#new-azdatalakestoreitem) [Remove-AzDataLakeStoreAccount](#remove-azdatalakestoreaccount) [Remove-AzDataLakeStoreFirewallRule](#remove-azdatalakestorefirewallrule) [Remove-AzDataLakeStoreItem](#remove-azdatalakestoreitem) [Remove-AzDataLakeStoreItemAcl](#remove-azdatalakestoreitemacl) [Remove-AzDataLakeStoreItemAclEntry](#remove-azdatalakestoreitemaclentry) [Remove-AzDataLakeStoreTrustedIdProvider](#remove-azdatalakestoretrustedidprovider) [Remove-AzDataLakeStoreVirtualNetworkRule](#remove-azdatalakestorevirtualnetworkrule) [Set-AzDataLakeStoreAccount](#set-azdatalakestoreaccount) [Set-AzDataLakeStoreFirewallRule](#set-azdatalakestorefirewallrule) [Set-AzDataLakeStoreItemAcl](#set-azdatalakestoreitemacl) [Set-AzDataLakeStoreItemAclEntry](#set-azdatalakestoreitemaclentry) [Set-AzDataLakeStoreItemExpiry](#set-azdatalakestoreitemexpiry) [Set-AzDataLakeStoreItemOwner](#set-azdatalakestoreitemowner) [Set-AzDataLakeStoreItemPermission](#set-azdatalakestoreitempermission) [Set-AzDataLakeStoreTrustedIdProvider](#set-azdatalakestoretrustedidprovider) [Set-AzDataLakeStoreVirtualNetworkRule](#set-azdatalakestorevirtualnetworkrule) [Test-AzDataLakeStoreAccount](#test-azdatalakestoreaccount) [Test-AzDataLakeStoreItem](#test-azdatalakestoreitem)
**Datamigration** [Get-AzDataMigrationProject](#get-azdatamigrationproject) [Get-AzDataMigrationService](#get-azdatamigrationservice) [Get-AzDataMigrationTask](#get-azdatamigrationtask) [Invoke-AzDataMigrationCommand](#invoke-azdatamigrationcommand) [New-AzDataMigrationConnectionInfo](#new-azdatamigrationconnectioninfo) [New-AzDataMigrationDatabaseInfo](#new-azdatamigrationdatabaseinfo) [New-AzDataMigrationFileShare](#new-azdatamigrationfileshare) [New-AzDataMigrationProject](#new-azdatamigrationproject) [New-AzDataMigrationSelectedDBObject](#new-azdatamigrationselecteddbobject) [New-AzDataMigrationService](#new-azdatamigrationservice) [New-AzDataMigrationSyncSelectedDBObject](#new-azdatamigrationsyncselecteddbobject) [New-AzDataMigrationTask](#new-azdatamigrationtask) [Remove-AzDataMigrationProject](#remove-azdatamigrationproject) [Remove-AzDataMigrationService](#remove-azdatamigrationservice) [Remove-AzDataMigrationTask](#remove-azdatamigrationtask) [Start-AzDataMigrationService](#start-azdatamigrationservice) [Stop-AzDataMigrationService](#stop-azdatamigrationservice) [Stop-AzDataMigrationTask](#stop-azdatamigrationtask)
**Deploymentmanager** [Get-AzDeploymentManagerArtifactSource](#get-azdeploymentmanagerartifactsource) [Get-AzDeploymentManagerRollout](#get-azdeploymentmanagerrollout) [Get-AzDeploymentManagerService](#get-azdeploymentmanagerservice) [Get-AzDeploymentManagerServiceTopology](#get-azdeploymentmanagerservicetopology) [Get-AzDeploymentManagerServiceUnit](#get-azdeploymentmanagerserviceunit) [Get-AzDeploymentManagerStep](#get-azdeploymentmanagerstep) [New-AzDeploymentManagerArtifactSource](#new-azdeploymentmanagerartifactsource) [New-AzDeploymentManagerService](#new-azdeploymentmanagerservice) [New-AzDeploymentManagerServiceTopology](#new-azdeploymentmanagerservicetopology) [New-AzDeploymentManagerServiceUnit](#new-azdeploymentmanagerserviceunit) [New-AzDeploymentManagerStep](#new-azdeploymentmanagerstep) [Remove-AzDeploymentManagerArtifactSource](#remove-azdeploymentmanagerartifactsource) [Remove-AzDeploymentManagerRollout](#remove-azdeploymentmanagerrollout) [Remove-AzDeploymentManagerService](#remove-azdeploymentmanagerservice) [Remove-AzDeploymentManagerServiceTopology](#remove-azdeploymentmanagerservicetopology) [Remove-AzDeploymentManagerServiceUnit](#remove-azdeploymentmanagerserviceunit) [Remove-AzDeploymentManagerStep](#remove-azdeploymentmanagerstep) [Restart-AzDeploymentManagerRollout](#restart-azdeploymentmanagerrollout) [Set-AzDeploymentManagerArtifactSource](#set-azdeploymentmanagerartifactsource) [Set-AzDeploymentManagerService](#set-azdeploymentmanagerservice) [Set-AzDeploymentManagerServiceTopology](#set-azdeploymentmanagerservicetopology) [Set-AzDeploymentManagerServiceUnit](#set-azdeploymentmanagerserviceunit) [Set-AzDeploymentManagerStep](#set-azdeploymentmanagerstep) [Stop-AzDeploymentManagerRollout](#stop-azdeploymentmanagerrollout)
**Deviceprovisioningservices** [Add-AzIoTDeviceProvisioningServiceAccessPolicy](#add-aziotdeviceprovisioningserviceaccesspolicy) [Add-AzIoTDeviceProvisioningServiceCertificate](#add-aziotdeviceprovisioningservicecertificate) [Add-AzIoTDeviceProvisioningServiceLinkedHub](#add-aziotdeviceprovisioningservicelinkedhub) [Get-AzIoTDeviceProvisioningService](#get-aziotdeviceprovisioningservice) [Get-AzIoTDeviceProvisioningServiceAccessPolicy](#get-aziotdeviceprovisioningserviceaccesspolicy) [Get-AzIoTDeviceProvisioningServiceCertificate](#get-aziotdeviceprovisioningservicecertificate) [Get-AzIoTDeviceProvisioningServiceLinkedHub](#get-aziotdeviceprovisioningservicelinkedhub) [New-AzIoTDeviceProvisioningService](#new-aziotdeviceprovisioningservice) [New-AzIoTDeviceProvisioningServiceCertificateVerificationCode](#new-aziotdeviceprovisioningservicecertificateverificationcode) [Remove-AzIoTDeviceProvisioningService](#remove-aziotdeviceprovisioningservice) [Remove-AzIoTDeviceProvisioningServiceAccessPolicy](#remove-aziotdeviceprovisioningserviceaccesspolicy) [Remove-AzIoTDeviceProvisioningServiceCertificate](#remove-aziotdeviceprovisioningservicecertificate) [Remove-AzIoTDeviceProvisioningServiceLinkedHub](#remove-aziotdeviceprovisioningservicelinkedhub) [Set-AzIoTDeviceProvisioningServiceCertificate](#set-aziotdeviceprovisioningservicecertificate) [Update-AzIoTDeviceProvisioningService](#update-aziotdeviceprovisioningservice) [Update-AzIoTDeviceProvisioningServiceAccessPolicy](#update-aziotdeviceprovisioningserviceaccesspolicy) [Update-AzIoTDeviceProvisioningServiceLinkedHub](#update-aziotdeviceprovisioningservicelinkedhub)
**Devspaces** [Get-AzDevSpacesController](#get-azdevspacescontroller) [New-AzDevSpacesController](#new-azdevspacescontroller) [Remove-AzDevSpacesController](#remove-azdevspacescontroller) [Update-AzDevSpacesController](#update-azdevspacescontroller)
**Devtestlabs** [Get-AzDtlAllowedVMSizesPolicy](#get-azdtlallowedvmsizespolicy) [Get-AzDtlAutoShutdownPolicy](#get-azdtlautoshutdownpolicy) [Get-AzDtlAutoStartPolicy](#get-azdtlautostartpolicy) [Get-AzDtlVMsPerLabPolicy](#get-azdtlvmsperlabpolicy) [Get-AzDtlVMsPerUserPolicy](#get-azdtlvmsperuserpolicy) [Set-AzDtlAllowedVMSizesPolicy](#set-azdtlallowedvmsizespolicy) [Set-AzDtlAutoShutdownPolicy](#set-azdtlautoshutdownpolicy) [Set-AzDtlAutoStartPolicy](#set-azdtlautostartpolicy) [Set-AzDtlVMsPerLabPolicy](#set-azdtlvmsperlabpolicy) [Set-AzDtlVMsPerUserPolicy](#set-azdtlvmsperuserpolicy)
**Eventgrid** [Get-AzEventGridDomain](#get-azeventgriddomain) [Get-AzEventGridDomainKey](#get-azeventgriddomainkey) [Get-AzEventGridDomainTopic](#get-azeventgriddomaintopic) [Get-AzEventGridSubscription](#get-azeventgridsubscription) [Get-AzEventGridTopic](#get-azeventgridtopic) [Get-AzEventGridTopicKey](#get-azeventgridtopickey) [Get-AzEventGridTopicType](#get-azeventgridtopictype) [New-AzEventGridDomain](#new-azeventgriddomain) [New-AzEventGridDomainKey](#new-azeventgriddomainkey) [New-AzEventGridDomainTopic](#new-azeventgriddomaintopic) [New-AzEventGridSubscription](#new-azeventgridsubscription) [New-AzEventGridTopic](#new-azeventgridtopic) [New-AzEventGridTopicKey](#new-azeventgridtopickey) [Remove-AzEventGridDomain](#remove-azeventgriddomain) [Remove-AzEventGridDomainTopic](#remove-azeventgriddomaintopic) [Remove-AzEventGridSubscription](#remove-azeventgridsubscription) [Remove-AzEventGridTopic](#remove-azeventgridtopic) [Set-AzEventGridTopic](#set-azeventgridtopic) [Update-AzEventGridSubscription](#update-azeventgridsubscription)
**Eventhub** [Add-AzEventHubIPRule](#add-azeventhubiprule) [Add-AzEventHubVirtualNetworkRule](#add-azeventhubvirtualnetworkrule) [Get-AzEventHub](#get-azeventhub) [Get-AzEventHubAuthorizationRule](#get-azeventhubauthorizationrule) [Get-AzEventHubConsumerGroup](#get-azeventhubconsumergroup) [Get-AzEventHubGeoDRConfiguration](#get-azeventhubgeodrconfiguration) [Get-AzEventHubKey](#get-azeventhubkey) [Get-AzEventHubNamespace](#get-azeventhubnamespace) [Get-AzEventHubNetworkRuleSet](#get-azeventhubnetworkruleset) [New-AzEventHub](#new-azeventhub) [New-AzEventHubAuthorizationRule](#new-azeventhubauthorizationrule) [New-AzEventHubAuthorizationRuleSASToken](#new-azeventhubauthorizationrulesastoken) [New-AzEventHubConsumerGroup](#new-azeventhubconsumergroup) [New-AzEventHubGeoDRConfiguration](#new-azeventhubgeodrconfiguration) [New-AzEventHubKey](#new-azeventhubkey) [New-AzEventHubNamespace](#new-azeventhubnamespace) [Remove-AzEventHub](#remove-azeventhub) [Remove-AzEventHubAuthorizationRule](#remove-azeventhubauthorizationrule) [Remove-AzEventHubConsumerGroup](#remove-azeventhubconsumergroup) [Remove-AzEventHubGeoDRConfiguration](#remove-azeventhubgeodrconfiguration) [Remove-AzEventHubIPRule](#remove-azeventhubiprule) [Remove-AzEventHubNamespace](#remove-azeventhubnamespace) [Remove-AzEventHubNetworkRuleSet](#remove-azeventhubnetworkruleset) [Remove-AzEventHubVirtualNetworkRule](#remove-azeventhubvirtualnetworkrule) [Set-AzEventHub](#set-azeventhub) [Set-AzEventHubAuthorizationRule](#set-azeventhubauthorizationrule) [Set-AzEventHubConsumerGroup](#set-azeventhubconsumergroup) [Set-AzEventHubGeoDRConfigurationBreakPair](#set-azeventhubgeodrconfigurationbreakpair) [Set-AzEventHubGeoDRConfigurationFailOver](#set-azeventhubgeodrconfigurationfailover) [Set-AzEventHubNamespace](#set-azeventhubnamespace) [Set-AzEventHubNetworkRuleSet](#set-azeventhubnetworkruleset) [Test-AzEventHubName](#test-azeventhubname)
**Frontdoor** [Disable-AzFrontDoorCustomDomainHttps](#disable-azfrontdoorcustomdomainhttps) [Enable-AzFrontDoorCustomDomainHttps](#enable-azfrontdoorcustomdomainhttps) [Get-AzFrontDoor](#get-azfrontdoor) [Get-AzFrontDoorFrontendEndpoint](#get-azfrontdoorfrontendendpoint) [Get-AzFrontDoorWafPolicy](#get-azfrontdoorwafpolicy) [New-AzFrontDoor](#new-azfrontdoor) [New-AzFrontDoorBackendObject](#new-azfrontdoorbackendobject) [New-AzFrontDoorBackendPoolObject](#new-azfrontdoorbackendpoolobject) [New-AzFrontDoorFrontendEndpointObject](#new-azfrontdoorfrontendendpointobject) [New-AzFrontDoorHealthProbeSettingObject](#new-azfrontdoorhealthprobesettingobject) [New-AzFrontDoorLoadBalancingSettingObject](#new-azfrontdoorloadbalancingsettingobject) [New-AzFrontDoorRoutingRuleObject](#new-azfrontdoorroutingruleobject) [New-AzFrontDoorWafCustomRuleObject](#new-azfrontdoorwafcustomruleobject) [New-AzFrontDoorWafManagedRuleObject](#new-azfrontdoorwafmanagedruleobject) [New-AzFrontDoorWafManagedRuleOverrideObject](#new-azfrontdoorwafmanagedruleoverrideobject) [New-AzFrontDoorWafMatchConditionObject](#new-azfrontdoorwafmatchconditionobject) [New-AzFrontDoorWafPolicy](#new-azfrontdoorwafpolicy) [New-AzFrontDoorWafRuleGroupOverrideObject](#new-azfrontdoorwafrulegroupoverrideobject) [Remove-AzFrontDoor](#remove-azfrontdoor) [Remove-AzFrontDoorContent](#remove-azfrontdoorcontent) [Remove-AzFrontDoorWafPolicy](#remove-azfrontdoorwafpolicy) [Set-AzFrontDoor](#set-azfrontdoor) [Update-AzFrontDoorWafPolicy](#update-azfrontdoorwafpolicy)
**Guestconfiguration** [Get-AzVMGuestPolicyStatus](#get-azvmguestpolicystatus) [Get-AzVMGuestPolicyStatusHistory](#get-azvmguestpolicystatushistory)
**Hdinsight** [Add-AzHDInsightClusterIdentity](#add-azhdinsightclusteridentity) [Add-AzHDInsightComponentVersion](#add-azhdinsightcomponentversion) [Add-AzHDInsightConfigValue](#add-azhdinsightconfigvalue) [Add-AzHDInsightMetastore](#add-azhdinsightmetastore) [Add-AzHDInsightScriptAction](#add-azhdinsightscriptaction) [Add-AzHDInsightSecurityProfile](#add-azhdinsightsecurityprofile) [Add-AzHDInsightStorage](#add-azhdinsightstorage) [Disable-AzHDInsightOperationsManagementSuite](#disable-azhdinsightoperationsmanagementsuite) [Enable-AzHDInsightOperationsManagementSuite](#enable-azhdinsightoperationsmanagementsuite) [Get-AzHDInsightCluster](#get-azhdinsightcluster) [Get-AzHDInsightJob](#get-azhdinsightjob) [Get-AzHDInsightJobOutput](#get-azhdinsightjoboutput) [Get-AzHDInsightOperationsManagementSuite](#get-azhdinsightoperationsmanagementsuite) [Get-AzHDInsightPersistedScriptAction](#get-azhdinsightpersistedscriptaction) [Get-AzHDInsightProperty](#get-azhdinsightproperty) [Get-AzHDInsightScriptActionHistory](#get-azhdinsightscriptactionhistory) [Grant-AzHDInsightRdpServicesAccess](#grant-azhdinsightrdpservicesaccess) [Invoke-AzHDInsightHiveJob](#invoke-azhdinsighthivejob) [New-AzHDInsightCluster](#new-azhdinsightcluster) [New-AzHDInsightClusterConfig](#new-azhdinsightclusterconfig) [New-AzHDInsightHiveJobDefinition](#new-azhdinsighthivejobdefinition) [New-AzHDInsightMapReduceJobDefinition](#new-azhdinsightmapreducejobdefinition) [New-AzHDInsightPigJobDefinition](#new-azhdinsightpigjobdefinition) [New-AzHDInsightSqoopJobDefinition](#new-azhdinsightsqoopjobdefinition) [New-AzHDInsightStreamingMapReduceJobDefinition](#new-azhdinsightstreamingmapreducejobdefinition) [Remove-AzHDInsightCluster](#remove-azhdinsightcluster) [Remove-AzHDInsightPersistedScriptAction](#remove-azhdinsightpersistedscriptaction) [Revoke-AzHDInsightRdpServicesAccess](#revoke-azhdinsightrdpservicesaccess) [Set-AzHDInsightClusterSize](#set-azhdinsightclustersize) [Set-AzHDInsightDefaultStorage](#set-azhdinsightdefaultstorage) [Set-AzHDInsightGatewayCredential](#set-azhdinsightgatewaycredential) [Set-AzHDInsightPersistedScriptAction](#set-azhdinsightpersistedscriptaction) [Start-AzHDInsightJob](#start-azhdinsightjob) [Stop-AzHDInsightJob](#stop-azhdinsightjob) [Submit-AzHDInsightScriptAction](#submit-azhdinsightscriptaction) [Use-AzHDInsightCluster](#use-azhdinsightcluster) [Wait-AzHDInsightJob](#wait-azhdinsightjob)
**Iothub** [Add-AzIotHubCertificate](#add-aziothubcertificate) [Add-AzIotHubEventHubConsumerGroup](#add-aziothubeventhubconsumergroup) [Add-AzIotHubKey](#add-aziothubkey) [Add-AzIotHubRoute](#add-aziothubroute) [Add-AzIotHubRoutingEndpoint](#add-aziothubroutingendpoint) [Get-AzIotHub](#get-aziothub) [Get-AzIotHubCertificate](#get-aziothubcertificate) [Get-AzIotHubCertificateVerificationCode](#get-aziothubcertificateverificationcode) [Get-AzIotHubConnectionString](#get-aziothubconnectionstring) [Get-AzIotHubEventHubConsumerGroup](#get-aziothubeventhubconsumergroup) [Get-AzIotHubJob](#get-aziothubjob) [Get-AzIotHubKey](#get-aziothubkey) [Get-AzIotHubQuotaMetric](#get-aziothubquotametric) [Get-AzIotHubRegistryStatistic](#get-aziothubregistrystatistic) [Get-AzIotHubRoute](#get-aziothubroute) [Get-AzIotHubRoutingEndpoint](#get-aziothubroutingendpoint) [Get-AzIotHubValidSku](#get-aziothubvalidsku) [New-AzIotHub](#new-aziothub) [New-AzIotHubExportDevice](#new-aziothubexportdevice) [New-AzIotHubImportDevice](#new-aziothubimportdevice) [New-AzIotHubKey](#new-aziothubkey) [Remove-AzIotHub](#remove-aziothub) [Remove-AzIotHubCertificate](#remove-aziothubcertificate) [Remove-AzIotHubEventHubConsumerGroup](#remove-aziothubeventhubconsumergroup) [Remove-AzIotHubKey](#remove-aziothubkey) [Remove-AzIotHubRoute](#remove-aziothubroute) [Remove-AzIotHubRoutingEndpoint](#remove-aziothubroutingendpoint) [Set-AzIotHub](#set-aziothub) [Set-AzIotHubRoute](#set-aziothubroute) [Set-AzIotHubVerifiedCertificate](#set-aziothubverifiedcertificate) [Test-AzIotHubRoute](#test-aziothubroute) [Update-AzIotHub](#update-aziothub)
**Keyvault** [Add-AzKeyVaultCertificate](#add-azkeyvaultcertificate) [Add-AzKeyVaultCertificateContact](#add-azkeyvaultcertificatecontact) [**Add-AzKeyVaultKey**](#add-azkeyvaultkey) [Add-AzKeyVaultManagedStorageAccount](#add-azkeyvaultmanagedstorageaccount) [Add-AzKeyVaultNetworkRule](#add-azkeyvaultnetworkrule) [Backup-AzKeyVaultCertificate](#backup-azkeyvaultcertificate) [Backup-AzKeyVaultKey](#backup-azkeyvaultkey) [Backup-AzKeyVaultManagedStorageAccount](#backup-azkeyvaultmanagedstorageaccount) [Backup-AzKeyVaultSecret](#backup-azkeyvaultsecret) [Get-AzKeyVault](#get-azkeyvault) [Get-AzKeyVaultCertificate](#get-azkeyvaultcertificate) [Get-AzKeyVaultCertificateContact](#get-azkeyvaultcertificatecontact) [Get-AzKeyVaultCertificateIssuer](#get-azkeyvaultcertificateissuer) [Get-AzKeyVaultCertificateOperation](#get-azkeyvaultcertificateoperation) [Get-AzKeyVaultCertificatePolicy](#get-azkeyvaultcertificatepolicy) [Get-AzKeyVaultKey](#get-azkeyvaultkey) [Get-AzKeyVaultManagedStorageAccount](#get-azkeyvaultmanagedstorageaccount) [Get-AzKeyVaultManagedStorageSasDefinition](#get-azkeyvaultmanagedstoragesasdefinition) [Get-AzKeyVaultSecret](#get-azkeyvaultsecret) [Import-AzKeyVaultCertificate](#import-azkeyvaultcertificate) [**New-AzKeyVault**](#new-azkeyvault) [New-AzKeyVaultCertificateAdministratorDetail](#new-azkeyvaultcertificateadministratordetail) [New-AzKeyVaultCertificateOrganizationDetail](#new-azkeyvaultcertificateorganizationdetail) [New-AzKeyVaultCertificatePolicy](#new-azkeyvaultcertificatepolicy) [Remove-AzKeyVault](#remove-azkeyvault) [Remove-AzKeyVaultAccessPolicy](#remove-azkeyvaultaccesspolicy) [Remove-AzKeyVaultCertificate](#remove-azkeyvaultcertificate) [Remove-AzKeyVaultCertificateContact](#remove-azkeyvaultcertificatecontact) [Remove-AzKeyVaultCertificateIssuer](#remove-azkeyvaultcertificateissuer) [Remove-AzKeyVaultCertificateOperation](#remove-azkeyvaultcertificateoperation) [Remove-AzKeyVaultKey](#remove-azkeyvaultkey) [Remove-AzKeyVaultManagedStorageAccount](#remove-azkeyvaultmanagedstorageaccount) [Remove-AzKeyVaultManagedStorageSasDefinition](#remove-azkeyvaultmanagedstoragesasdefinition) [Remove-AzKeyVaultNetworkRule](#remove-azkeyvaultnetworkrule) [Remove-AzKeyVaultSecret](#remove-azkeyvaultsecret) [Restore-AzKeyVaultCertificate](#restore-azkeyvaultcertificate) [Restore-AzKeyVaultKey](#restore-azkeyvaultkey) [Restore-AzKeyVaultManagedStorageAccount](#restore-azkeyvaultmanagedstorageaccount) [Restore-AzKeyVaultSecret](#restore-azkeyvaultsecret) [Set-AzKeyVaultAccessPolicy](#set-azkeyvaultaccesspolicy) [Set-AzKeyVaultCertificateIssuer](#set-azkeyvaultcertificateissuer) [Set-AzKeyVaultCertificatePolicy](#set-azkeyvaultcertificatepolicy) [Set-AzKeyVaultManagedStorageSasDefinition](#set-azkeyvaultmanagedstoragesasdefinition) [**Set-AzKeyVaultSecret**](#set-azkeyvaultsecret) [Stop-AzKeyVaultCertificateOperation](#stop-azkeyvaultcertificateoperation) [Undo-AzKeyVaultCertificateRemoval](#undo-azkeyvaultcertificateremoval) [Undo-AzKeyVaultKeyRemoval](#undo-azkeyvaultkeyremoval) [Undo-AzKeyVaultManagedStorageAccountRemoval](#undo-azkeyvaultmanagedstorageaccountremoval) [Undo-AzKeyVaultManagedStorageSasDefinitionRemoval](#undo-azkeyvaultmanagedstoragesasdefinitionremoval) [Undo-AzKeyVaultRemoval](#undo-azkeyvaultremoval) [Undo-AzKeyVaultSecretRemoval](#undo-azkeyvaultsecretremoval) [Update-AzKeyVaultCertificate](#update-azkeyvaultcertificate) [Update-AzKeyVaultKey](#update-azkeyvaultkey) [Update-AzKeyVaultManagedStorageAccount](#update-azkeyvaultmanagedstorageaccount) [Update-AzKeyVaultManagedStorageAccountKey](#update-azkeyvaultmanagedstorageaccountkey) [Update-AzKeyVaultNetworkRuleSet](#update-azkeyvaultnetworkruleset) [Update-AzKeyVaultSecret](#update-azkeyvaultsecret)
**Kusto** [Get-AzKustoCluster](#get-azkustocluster) [Get-AzKustoDatabase](#get-azkustodatabase) [New-AzKustoCluster](#new-azkustocluster) [New-AzKustoDatabase](#new-azkustodatabase) [Remove-AzKustoCluster](#remove-azkustocluster) [Remove-AzKustoDatabase](#remove-azkustodatabase) [Resume-AzKustoCluster](#resume-azkustocluster) [Suspend-AzKustoCluster](#suspend-azkustocluster) [Test-AzKustoClusterName](#test-azkustoclustername) [Update-AzKustoCluster](#update-azkustocluster) [Update-AzKustoDatabase](#update-azkustodatabase)
**Logicapp** [Get-AzIntegrationAccount](#get-azintegrationaccount) [Get-AzIntegrationAccountAgreement](#get-azintegrationaccountagreement) [Get-AzIntegrationAccountAssembly](#get-azintegrationaccountassembly) [Get-AzIntegrationAccountBatchConfiguration](#get-azintegrationaccountbatchconfiguration) [Get-AzIntegrationAccountCallbackUrl](#get-azintegrationaccountcallbackurl) [Get-AzIntegrationAccountCertificate](#get-azintegrationaccountcertificate) [Get-AzIntegrationAccountGeneratedIcn](#get-azintegrationaccountgeneratedicn) [Get-AzIntegrationAccountMap](#get-azintegrationaccountmap) [Get-AzIntegrationAccountPartner](#get-azintegrationaccountpartner) [Get-AzIntegrationAccountReceivedIcn](#get-azintegrationaccountreceivedicn) [Get-AzIntegrationAccountSchema](#get-azintegrationaccountschema) [Get-AzLogicApp](#get-azlogicapp) [Get-AzLogicAppRunAction](#get-azlogicapprunaction) [Get-AzLogicAppRunHistory](#get-azlogicapprunhistory) [Get-AzLogicAppTrigger](#get-azlogicapptrigger) [Get-AzLogicAppTriggerCallbackUrl](#get-azlogicapptriggercallbackurl) [Get-AzLogicAppTriggerHistory](#get-azlogicapptriggerhistory) [Get-AzLogicAppUpgradedDefinition](#get-azlogicappupgradeddefinition) [New-AzIntegrationAccount](#new-azintegrationaccount) [New-AzIntegrationAccountAgreement](#new-azintegrationaccountagreement) [New-AzIntegrationAccountAssembly](#new-azintegrationaccountassembly) [New-AzIntegrationAccountBatchConfiguration](#new-azintegrationaccountbatchconfiguration) [New-AzIntegrationAccountCertificate](#new-azintegrationaccountcertificate) [New-AzIntegrationAccountMap](#new-azintegrationaccountmap) [New-AzIntegrationAccountPartner](#new-azintegrationaccountpartner) [New-AzIntegrationAccountSchema](#new-azintegrationaccountschema) [New-AzLogicApp](#new-azlogicapp) [Remove-AzIntegrationAccount](#remove-azintegrationaccount) [Remove-AzIntegrationAccountAgreement](#remove-azintegrationaccountagreement) [Remove-AzIntegrationAccountAssembly](#remove-azintegrationaccountassembly) [Remove-AzIntegrationAccountBatchConfiguration](#remove-azintegrationaccountbatchconfiguration) [Remove-AzIntegrationAccountCertificate](#remove-azintegrationaccountcertificate) [Remove-AzIntegrationAccountMap](#remove-azintegrationaccountmap) [Remove-AzIntegrationAccountPartner](#remove-azintegrationaccountpartner) [Remove-AzIntegrationAccountReceivedIcn](#remove-azintegrationaccountreceivedicn) [Remove-AzIntegrationAccountSchema](#remove-azintegrationaccountschema) [Remove-AzLogicApp](#remove-azlogicapp) [Set-AzIntegrationAccount](#set-azintegrationaccount) [Set-AzIntegrationAccountAgreement](#set-azintegrationaccountagreement) [Set-AzIntegrationAccountAssembly](#set-azintegrationaccountassembly) [Set-AzIntegrationAccountBatchConfiguration](#set-azintegrationaccountbatchconfiguration) [Set-AzIntegrationAccountCertificate](#set-azintegrationaccountcertificate) [Set-AzIntegrationAccountGeneratedIcn](#set-azintegrationaccountgeneratedicn) [Set-AzIntegrationAccountMap](#set-azintegrationaccountmap) [Set-AzIntegrationAccountPartner](#set-azintegrationaccountpartner) [Set-AzIntegrationAccountReceivedIcn](#set-azintegrationaccountreceivedicn) [Set-AzIntegrationAccountSchema](#set-azintegrationaccountschema) [Set-AzLogicApp](#set-azlogicapp) [Start-AzLogicApp](#start-azlogicapp) [Stop-AzLogicAppRun](#stop-azlogicapprun) [Test-AzLogicApp](#test-azlogicapp)
**Machinelearning** [Add-AzMlWebServiceRegionalProperty](#add-azmlwebserviceregionalproperty) [Export-AzMlWebService](#export-azmlwebservice) [Get-AzMlCommitmentAssociation](#get-azmlcommitmentassociation) [Get-AzMlCommitmentPlan](#get-azmlcommitmentplan) [Get-AzMlCommitmentPlanUsageHistory](#get-azmlcommitmentplanusagehistory) [Get-AzMlOpCluster](#get-azmlopcluster) [Get-AzMlOpClusterKey](#get-azmlopclusterkey) [Get-AzMlWebService](#get-azmlwebservice) [Get-AzMlWebServiceKey](#get-azmlwebservicekey) [Import-AzMlWebService](#import-azmlwebservice) [Move-AzMlCommitmentAssociation](#move-azmlcommitmentassociation) [New-AzMlCommitmentPlan](#new-azmlcommitmentplan) [New-AzMlOpCluster](#new-azmlopcluster) [New-AzMlWebService](#new-azmlwebservice) [Remove-AzMlCommitmentPlan](#remove-azmlcommitmentplan) [Remove-AzMlOpCluster](#remove-azmlopcluster) [Remove-AzMlWebService](#remove-azmlwebservice) [Set-AzMlOpCluster](#set-azmlopcluster) [Test-AzMlOpClusterSystemServicesUpdateAvailability](#test-azmlopclustersystemservicesupdateavailability) [Update-AzMlCommitmentPlan](#update-azmlcommitmentplan) [Update-AzMlOpClusterSystemService](#update-azmlopclustersystemservice) [Update-AzMlWebService](#update-azmlwebservice)
**Managedserviceidentity** [Get-AzUserAssignedIdentity](#get-azuserassignedidentity) [New-AzUserAssignedIdentity](#new-azuserassignedidentity) [Remove-AzUserAssignedIdentity](#remove-azuserassignedidentity)
**Managedservices** [Get-AzManagedServicesAssignment](#get-azmanagedservicesassignment) [Get-AzManagedServicesDefinition](#get-azmanagedservicesdefinition) [New-AzManagedServicesAssignment](#new-azmanagedservicesassignment) [New-AzManagedServicesDefinition](#new-azmanagedservicesdefinition) [Remove-AzManagedServicesAssignment](#remove-azmanagedservicesassignment) [Remove-AzManagedServicesDefinition](#remove-azmanagedservicesdefinition)
**Managementpartner** [Get-AzManagementPartner](#get-azmanagementpartner) [New-AzManagementPartner](#new-azmanagementpartner) [Remove-AzManagementPartner](#remove-azmanagementpartner) [Update-AzManagementPartner](#update-azmanagementpartner)
**Maps** [Get-AzMapsAccount](#get-azmapsaccount) [Get-AzMapsAccountKey](#get-azmapsaccountkey) [New-AzMapsAccount](#new-azmapsaccount) [New-AzMapsAccountKey](#new-azmapsaccountkey) [Remove-AzMapsAccount](#remove-azmapsaccount)
**Marketplaceordering** [Get-AzMarketplaceTerms](#get-azmarketplaceterms) [Set-AzMarketplaceTerms](#set-azmarketplaceterms)
**Media** [Get-AzMediaService](#get-azmediaservice) [Get-AzMediaServiceKey](#get-azmediaservicekey) [Get-AzMediaServiceNameAvailability](#get-azmediaservicenameavailability) [New-AzMediaService](#new-azmediaservice) [New-AzMediaServiceStorageConfig](#new-azmediaservicestorageconfig) [Remove-AzMediaService](#remove-azmediaservice) [Set-AzMediaService](#set-azmediaservice) [Set-AzMediaServiceKey](#set-azmediaservicekey) [Sync-AzMediaServiceStorageKey](#sync-azmediaservicestoragekey)
**Mixedreality** [Get-AzSpatialAnchorsAccount](#get-azspatialanchorsaccount) [Get-AzSpatialAnchorsAccountKey](#get-azspatialanchorsaccountkey) [New-AzSpatialAnchorsAccount](#new-azspatialanchorsaccount) [New-AzSpatialAnchorsAccountKey](#new-azspatialanchorsaccountkey) [Remove-AzSpatialAnchorsAccount](#remove-azspatialanchorsaccount)
**Netappfiles** [Get-AzNetAppFilesAccount](#get-aznetappfilesaccount) [Get-AzNetAppFilesPool](#get-aznetappfilespool) [Get-AzNetAppFilesSnapshot](#get-aznetappfilessnapshot) [Get-AzNetAppFilesVolume](#get-aznetappfilesvolume) [New-AzNetAppFilesAccount](#new-aznetappfilesaccount) [New-AzNetAppFilesPool](#new-aznetappfilespool) [New-AzNetAppFilesSnapshot](#new-aznetappfilessnapshot) [New-AzNetAppFilesVolume](#new-aznetappfilesvolume) [Remove-AzNetAppFilesAccount](#remove-aznetappfilesaccount) [Remove-AzNetAppFilesPool](#remove-aznetappfilespool) [Remove-AzNetAppFilesSnapshot](#remove-aznetappfilessnapshot) [Remove-AzNetAppFilesVolume](#remove-aznetappfilesvolume) [Set-AzNetAppFilesAccount](#set-aznetappfilesaccount) [Update-AzNetAppFilesAccount](#update-aznetappfilesaccount) [Update-AzNetAppFilesPool](#update-aznetappfilespool) [Update-AzNetAppFilesVolume](#update-aznetappfilesvolume)
**Network** [Add-AzApplicationGatewayAuthenticationCertificate](#add-azapplicationgatewayauthenticationcertificate) [Add-AzApplicationGatewayBackendAddressPool](#add-azapplicationgatewaybackendaddresspool) [Add-AzApplicationGatewayBackendHttpSetting](#add-azapplicationgatewaybackendhttpsetting) [Add-AzApplicationGatewayCustomError](#add-azapplicationgatewaycustomerror) [Add-AzApplicationGatewayFrontendIPConfig](#add-azapplicationgatewayfrontendipconfig) [Add-AzApplicationGatewayFrontendPort](#add-azapplicationgatewayfrontendport) [Add-AzApplicationGatewayHttpListener](#add-azapplicationgatewayhttplistener) [Add-AzApplicationGatewayHttpListenerCustomError](#add-azapplicationgatewayhttplistenercustomerror) [Add-AzApplicationGatewayIPConfiguration](#add-azapplicationgatewayipconfiguration) [Add-AzApplicationGatewayProbeConfig](#add-azapplicationgatewayprobeconfig) [Add-AzApplicationGatewayRedirectConfiguration](#add-azapplicationgatewayredirectconfiguration) [Add-AzApplicationGatewayRequestRoutingRule](#add-azapplicationgatewayrequestroutingrule) [Add-AzApplicationGatewayRewriteRuleSet](#add-azapplicationgatewayrewriteruleset) [Add-AzApplicationGatewaySslCertificate](#add-azapplicationgatewaysslcertificate) [Add-AzApplicationGatewayTrustedRootCertificate](#add-azapplicationgatewaytrustedrootcertificate) [Add-AzApplicationGatewayUrlPathMapConfig](#add-azapplicationgatewayurlpathmapconfig) [Add-AzDelegation](#add-azdelegation) [Add-AzExpressRouteCircuitAuthorization](#add-azexpressroutecircuitauthorization) [Add-AzExpressRouteCircuitConnectionConfig](#add-azexpressroutecircuitconnectionconfig) [Add-AzExpressRouteCircuitPeeringConfig](#add-azexpressroutecircuitpeeringconfig) [Add-AzExpressRouteCrossConnectionPeering](#add-azexpressroutecrossconnectionpeering) [Add-AzLoadBalancerBackendAddressPoolConfig](#add-azloadbalancerbackendaddresspoolconfig) [Add-AzLoadBalancerFrontendIpConfig](#add-azloadbalancerfrontendipconfig) [Add-AzLoadBalancerInboundNatPoolConfig](#add-azloadbalancerinboundnatpoolconfig) [Add-AzLoadBalancerInboundNatRuleConfig](#add-azloadbalancerinboundnatruleconfig) [Add-AzLoadBalancerOutboundRuleConfig](#add-azloadbalanceroutboundruleconfig) [**Add-AzLoadBalancerProbeConfig**](#add-azloadbalancerprobeconfig) [**Add-AzLoadBalancerRuleConfig**](#add-azloadbalancerruleconfig) [Add-AzNetworkInterfaceIpConfig](#add-aznetworkinterfaceipconfig) [Add-AzNetworkInterfaceTapConfig](#add-aznetworkinterfacetapconfig) [Add-AzNetworkSecurityRuleConfig](#add-aznetworksecurityruleconfig) [**Add-AzRouteConfig**](#add-azrouteconfig) [Add-AzRouteFilterRuleConfig](#add-azroutefilterruleconfig) [Add-AzServiceEndpointPolicyDefinition](#add-azserviceendpointpolicydefinition) [Add-AzVirtualNetworkGatewayIpConfig](#add-azvirtualnetworkgatewayipconfig) [**Add-AzVirtualNetworkPeering**](#add-azvirtualnetworkpeering) [Add-AzVirtualNetworkSubnetConfig](#add-azvirtualnetworksubnetconfig) [Add-AzVpnClientRevokedCertificate](#add-azvpnclientrevokedcertificate) [Add-AzVpnClientRootCertificate](#add-azvpnclientrootcertificate) [Approve-AzPrivateEndpointConnection](#approve-azprivateendpointconnection) [Deny-AzPrivateEndpointConnection](#deny-azprivateendpointconnection) [Get-AzApplicationGateway](#get-azapplicationgateway) [Get-AzApplicationGatewayAuthenticationCertificate](#get-azapplicationgatewayauthenticationcertificate) [Get-AzApplicationGatewayAutoscaleConfiguration](#get-azapplicationgatewayautoscaleconfiguration) [Get-AzApplicationGatewayAvailableServerVariableAndHeader](#get-azapplicationgatewayavailableservervariableandheader) [Get-AzApplicationGatewayAvailableSslOption](#get-azapplicationgatewayavailablessloption) [Get-AzApplicationGatewayAvailableWafRuleSet](#get-azapplicationgatewayavailablewafruleset) [Get-AzApplicationGatewayBackendAddressPool](#get-azapplicationgatewaybackendaddresspool) [Get-AzApplicationGatewayBackendHealth](#get-azapplicationgatewaybackendhealth) [Get-AzApplicationGatewayBackendHttpSetting](#get-azapplicationgatewaybackendhttpsetting) [Get-AzApplicationGatewayConnectionDraining](#get-azapplicationgatewayconnectiondraining) [Get-AzApplicationGatewayCustomError](#get-azapplicationgatewaycustomerror) [Get-AzApplicationGatewayFirewallPolicy](#get-azapplicationgatewayfirewallpolicy) [Get-AzApplicationGatewayFrontendIPConfig](#get-azapplicationgatewayfrontendipconfig) [Get-AzApplicationGatewayFrontendPort](#get-azapplicationgatewayfrontendport) [Get-AzApplicationGatewayHttpListener](#get-azapplicationgatewayhttplistener) [Get-AzApplicationGatewayHttpListenerCustomError](#get-azapplicationgatewayhttplistenercustomerror) [Get-AzApplicationGatewayIdentity](#get-azapplicationgatewayidentity) [Get-AzApplicationGatewayIPConfiguration](#get-azapplicationgatewayipconfiguration) [Get-AzApplicationGatewayProbeConfig](#get-azapplicationgatewayprobeconfig) [Get-AzApplicationGatewayRedirectConfiguration](#get-azapplicationgatewayredirectconfiguration) [Get-AzApplicationGatewayRequestRoutingRule](#get-azapplicationgatewayrequestroutingrule) [Get-AzApplicationGatewayRewriteRuleSet](#get-azapplicationgatewayrewriteruleset) [Get-AzApplicationGatewaySku](#get-azapplicationgatewaysku) [Get-AzApplicationGatewaySslCertificate](#get-azapplicationgatewaysslcertificate) [Get-AzApplicationGatewaySslPolicy](#get-azapplicationgatewaysslpolicy) [Get-AzApplicationGatewaySslPredefinedPolicy](#get-azapplicationgatewaysslpredefinedpolicy) [Get-AzApplicationGatewayTrustedRootCertificate](#get-azapplicationgatewaytrustedrootcertificate) [Get-AzApplicationGatewayUrlPathMapConfig](#get-azapplicationgatewayurlpathmapconfig) [Get-AzApplicationGatewayWebApplicationFirewallConfiguration](#get-azapplicationgatewaywebapplicationfirewallconfiguration) [Get-AzApplicationSecurityGroup](#get-azapplicationsecuritygroup) [Get-AzAutoApprovedPrivateLinkService](#get-azautoapprovedprivatelinkservice) [Get-AzAvailablePrivateEndpointType](#get-azavailableprivateendpointtype) [Get-AzAvailableServiceDelegation](#get-azavailableservicedelegation) [Get-AzBgpServiceCommunity](#get-azbgpservicecommunity) [Get-AzDdosProtectionPlan](#get-azddosprotectionplan) [Get-AzDelegation](#get-azdelegation) [**Get-AzEffectiveNetworkSecurityGroup**](#get-azeffectivenetworksecuritygroup) [**Get-AzEffectiveRouteTable**](#get-azeffectiveroutetable) [Get-AzExpressRouteCircuit](#get-azexpressroutecircuit) [Get-AzExpressRouteCircuitARPTable](#get-azexpressroutecircuitarptable) [Get-AzExpressRouteCircuitAuthorization](#get-azexpressroutecircuitauthorization) [Get-AzExpressRouteCircuitConnectionConfig](#get-azexpressroutecircuitconnectionconfig) [Get-AzExpressRouteCircuitPeeringConfig](#get-azexpressroutecircuitpeeringconfig) [Get-AzExpressRouteCircuitRouteTable](#get-azexpressroutecircuitroutetable) [Get-AzExpressRouteCircuitRouteTableSummary](#get-azexpressroutecircuitroutetablesummary) [Get-AzExpressRouteCircuitStat](#get-azexpressroutecircuitstat) [Get-AzExpressRouteConnection](#get-azexpressrouteconnection) [Get-AzExpressRouteCrossConnection](#get-azexpressroutecrossconnection) [Get-AzExpressRouteCrossConnectionArpTable](#get-azexpressroutecrossconnectionarptable) [Get-AzExpressRouteCrossConnectionPeering](#get-azexpressroutecrossconnectionpeering) [Get-AzExpressRouteCrossConnectionRouteTable](#get-azexpressroutecrossconnectionroutetable) [Get-AzExpressRouteCrossConnectionRouteTableSummary](#get-azexpressroutecrossconnectionroutetablesummary) [Get-AzExpressRouteGateway](#get-azexpressroutegateway) [Get-AzExpressRoutePort](#get-azexpressrouteport) [Get-AzExpressRoutePortLinkConfig](#get-azexpressrouteportlinkconfig) [Get-AzExpressRoutePortsLocation](#get-azexpressrouteportslocation) [Get-AzExpressRouteServiceProvider](#get-azexpressrouteserviceprovider) [Get-AzFirewall](#get-azfirewall) [Get-AzFirewallFqdnTag](#get-azfirewallfqdntag) [**Get-AzLoadBalancer**](#get-azloadbalancer) [**Get-AzLoadBalancerBackendAddressPoolConfig**](#get-azloadbalancerbackendaddresspoolconfig) [Get-AzLoadBalancerFrontendIpConfig](#get-azloadbalancerfrontendipconfig) [Get-AzLoadBalancerInboundNatPoolConfig](#get-azloadbalancerinboundnatpoolconfig) [Get-AzLoadBalancerInboundNatRuleConfig](#get-azloadbalancerinboundnatruleconfig) [Get-AzLoadBalancerOutboundRuleConfig](#get-azloadbalanceroutboundruleconfig) [Get-AzLoadBalancerProbeConfig](#get-azloadbalancerprobeconfig) [Get-AzLoadBalancerRuleConfig](#get-azloadbalancerruleconfig) [Get-AzLocalNetworkGateway](#get-azlocalnetworkgateway) [Get-AzNatGateway](#get-aznatgateway) [**Get-AzNetworkInterface**](#get-aznetworkinterface) [**Get-AzNetworkInterfaceIpConfig**](#get-aznetworkinterfaceipconfig) [Get-AzNetworkInterfaceTapConfig](#get-aznetworkinterfacetapconfig) [Get-AzNetworkProfile](#get-aznetworkprofile) [Get-AzNetworkSecurityGroup](#get-aznetworksecuritygroup) [Get-AzNetworkSecurityRuleConfig](#get-aznetworksecurityruleconfig) [Get-AzNetworkServiceTag](#get-aznetworkservicetag) [Get-AzNetworkUsage](#get-aznetworkusage) [**Get-AzNetworkWatcher**](#get-aznetworkwatcher) [Get-AzNetworkWatcherConnectionMonitor](#get-aznetworkwatcherconnectionmonitor) [Get-AzNetworkWatcherConnectionMonitorReport](#get-aznetworkwatcherconnectionmonitorreport) [Get-AzNetworkWatcherFlowLogStatus](#get-aznetworkwatcherflowlogstatus) [**Get-AzNetworkWatcherNextHop**](#get-aznetworkwatchernexthop) [**Get-AzNetworkWatcherPacketCapture**](#get-aznetworkwatcherpacketcapture) [Get-AzNetworkWatcherReachabilityProvidersList](#get-aznetworkwatcherreachabilityproviderslist) [Get-AzNetworkWatcherReachabilityReport](#get-aznetworkwatcherreachabilityreport) [Get-AzNetworkWatcherSecurityGroupView](#get-aznetworkwatchersecuritygroupview) [**Get-AzNetworkWatcherTopology**](#get-aznetworkwatchertopology) [Get-AzNetworkWatcherTroubleshootingResult](#get-aznetworkwatchertroubleshootingresult) [Get-AzPrivateEndpoint](#get-azprivateendpoint) [Get-AzPrivateEndpointConnection](#get-azprivateendpointconnection) [Get-AzPrivateLinkService](#get-azprivatelinkservice) [Get-AzPublicIpAddress](#get-azpublicipaddress) [Get-AzPublicIpPrefix](#get-azpublicipprefix) [Get-AzRouteConfig](#get-azrouteconfig) [Get-AzRouteFilter](#get-azroutefilter) [Get-AzRouteFilterRuleConfig](#get-azroutefilterruleconfig) [Get-AzRouteTable](#get-azroutetable) [Get-AzServiceEndpointPolicy](#get-azserviceendpointpolicy) [Get-AzServiceEndpointPolicyDefinition](#get-azserviceendpointpolicydefinition) [Get-AzVirtualHub](#get-azvirtualhub) [Get-AzVirtualHubVnetConnection](#get-azvirtualhubvnetconnection) [**Get-AzVirtualNetwork**](#get-azvirtualnetwork) [Get-AzVirtualNetworkAvailableEndpointService](#get-azvirtualnetworkavailableendpointservice) [**Get-AzVirtualNetworkGateway**](#get-azvirtualnetworkgateway) [Get-AzVirtualNetworkGatewayAdvertisedRoute](#get-azvirtualnetworkgatewayadvertisedroute) [Get-AzVirtualNetworkGatewayBGPPeerStatus](#get-azvirtualnetworkgatewaybgppeerstatus) [**Get-AzVirtualNetworkGatewayConnection**](#get-azvirtualnetworkgatewayconnection) [Get-AzVirtualNetworkGatewayConnectionSharedKey](#get-azvirtualnetworkgatewayconnectionsharedkey) [Get-AzVirtualNetworkGatewayConnectionVpnDeviceConfigScript](#get-azvirtualnetworkgatewayconnectionvpndeviceconfigscript) [Get-AzVirtualNetworkGatewayLearnedRoute](#get-azvirtualnetworkgatewaylearnedroute) [Get-AzVirtualNetworkGatewaySupportedVpnDevice](#get-azvirtualnetworkgatewaysupportedvpndevice) [Get-AzVirtualNetworkGatewayVpnClientConnectionHealth](#get-azvirtualnetworkgatewayvpnclientconnectionhealth) [**Get-AzVirtualNetworkPeering**](#get-azvirtualnetworkpeering) [**Get-AzVirtualNetworkSubnetConfig**](#get-azvirtualnetworksubnetconfig) [Get-AzVirtualNetworkTap](#get-azvirtualnetworktap) [Get-AzVirtualNetworkUsageList](#get-azvirtualnetworkusagelist) [Get-AzVirtualWan](#get-azvirtualwan) [Get-AzVirtualWanVpnConfiguration](#get-azvirtualwanvpnconfiguration) [Get-AzVpnClientConfiguration](#get-azvpnclientconfiguration) [Get-AzVpnClientIpsecParameter](#get-azvpnclientipsecparameter) [Get-AzVpnClientPackage](#get-azvpnclientpackage) [Get-AzVpnClientRevokedCertificate](#get-azvpnclientrevokedcertificate) [Get-AzVpnClientRootCertificate](#get-azvpnclientrootcertificate) [Get-AzVpnConnection](#get-azvpnconnection) [Get-AzVpnGateway](#get-azvpngateway) [Get-AzVpnSite](#get-azvpnsite) [Invoke-AzNetworkWatcherNetworkConfigurationDiagnostic](#invoke-aznetworkwatchernetworkconfigurationdiagnostic) [Move-AzExpressRouteCircuit](#move-azexpressroutecircuit) [New-AzApplicationGateway](#new-azapplicationgateway) [New-AzApplicationGatewayAuthenticationCertificate](#new-azapplicationgatewayauthenticationcertificate) [New-AzApplicationGatewayAutoscaleConfiguration](#new-azapplicationgatewayautoscaleconfiguration) [New-AzApplicationGatewayBackendAddressPool](#new-azapplicationgatewaybackendaddresspool) [New-AzApplicationGatewayBackendHttpSetting](#new-azapplicationgatewaybackendhttpsetting) [New-AzApplicationGatewayConnectionDraining](#new-azapplicationgatewayconnectiondraining) [New-AzApplicationGatewayCustomError](#new-azapplicationgatewaycustomerror) [New-AzApplicationGatewayFirewallCondition](#new-azapplicationgatewayfirewallcondition) [New-AzApplicationGatewayFirewallCustomRule](#new-azapplicationgatewayfirewallcustomrule) [New-AzApplicationGatewayFirewallDisabledRuleGroupConfig](#new-azapplicationgatewayfirewalldisabledrulegroupconfig) [New-AzApplicationGatewayFirewallExclusionConfig](#new-azapplicationgatewayfirewallexclusionconfig) [New-AzApplicationGatewayFirewallMatchVariable](#new-azapplicationgatewayfirewallmatchvariable) [New-AzApplicationGatewayFirewallPolicy](#new-azapplicationgatewayfirewallpolicy) [New-AzApplicationGatewayFrontendIPConfig](#new-azapplicationgatewayfrontendipconfig) [New-AzApplicationGatewayFrontendPort](#new-azapplicationgatewayfrontendport) [New-AzApplicationGatewayHttpListener](#new-azapplicationgatewayhttplistener) [New-AzApplicationGatewayIdentity](#new-azapplicationgatewayidentity) [New-AzApplicationGatewayIPConfiguration](#new-azapplicationgatewayipconfiguration) [New-AzApplicationGatewayPathRuleConfig](#new-azapplicationgatewaypathruleconfig) [New-AzApplicationGatewayProbeConfig](#new-azapplicationgatewayprobeconfig) [New-AzApplicationGatewayProbeHealthResponseMatch](#new-azapplicationgatewayprobehealthresponsematch) [New-AzApplicationGatewayRedirectConfiguration](#new-azapplicationgatewayredirectconfiguration) [New-AzApplicationGatewayRequestRoutingRule](#new-azapplicationgatewayrequestroutingrule) [New-AzApplicationGatewayRewriteRule](#new-azapplicationgatewayrewriterule) [New-AzApplicationGatewayRewriteRuleActionSet](#new-azapplicationgatewayrewriteruleactionset) [New-AzApplicationGatewayRewriteRuleCondition](#new-azapplicationgatewayrewriterulecondition) [New-AzApplicationGatewayRewriteRuleHeaderConfiguration](#new-azapplicationgatewayrewriteruleheaderconfiguration) [New-AzApplicationGatewayRewriteRuleSet](#new-azapplicationgatewayrewriteruleset) [New-AzApplicationGatewaySku](#new-azapplicationgatewaysku) [New-AzApplicationGatewaySslCertificate](#new-azapplicationgatewaysslcertificate) [New-AzApplicationGatewaySslPolicy](#new-azapplicationgatewaysslpolicy) [New-AzApplicationGatewayTrustedRootCertificate](#new-azapplicationgatewaytrustedrootcertificate) [New-AzApplicationGatewayUrlPathMapConfig](#new-azapplicationgatewayurlpathmapconfig) [New-AzApplicationGatewayWebApplicationFirewallConfiguration](#new-azapplicationgatewaywebapplicationfirewallconfiguration) [New-AzApplicationSecurityGroup](#new-azapplicationsecuritygroup) [New-AzContainerNicConfig](#new-azcontainernicconfig) [New-AzContainerNicConfigIpConfig](#new-azcontainernicconfigipconfig) [New-AzDdosProtectionPlan](#new-azddosprotectionplan) [New-AzDelegation](#new-azdelegation) [New-AzExpressRouteCircuit](#new-azexpressroutecircuit) [New-AzExpressRouteCircuitAuthorization](#new-azexpressroutecircuitauthorization) [New-AzExpressRouteCircuitPeeringConfig](#new-azexpressroutecircuitpeeringconfig) [New-AzExpressRouteConnection](#new-azexpressrouteconnection) [New-AzExpressRouteGateway](#new-azexpressroutegateway) [New-AzExpressRoutePort](#new-azexpressrouteport) [New-AzFirewall](#new-azfirewall) [New-AzFirewallApplicationRule](#new-azfirewallapplicationrule) [New-AzFirewallApplicationRuleCollection](#new-azfirewallapplicationrulecollection) [New-AzFirewallNatRule](#new-azfirewallnatrule) [New-AzFirewallNatRuleCollection](#new-azfirewallnatrulecollection) [New-AzFirewallNetworkRule](#new-azfirewallnetworkrule) [New-AzFirewallNetworkRuleCollection](#new-azfirewallnetworkrulecollection) [New-AzIpsecPolicy](#new-azipsecpolicy) [**New-AzLoadBalancer**](#new-azloadbalancer) [**New-AzLoadBalancerBackendAddressPoolConfig**](#new-azloadbalancerbackendaddresspoolconfig) [**New-AzLoadBalancerFrontendIpConfig**](#new-azloadbalancerfrontendipconfig) [New-AzLoadBalancerInboundNatPoolConfig](#new-azloadbalancerinboundnatpoolconfig) [New-AzLoadBalancerInboundNatRuleConfig](#new-azloadbalancerinboundnatruleconfig) [New-AzLoadBalancerOutboundRuleConfig](#new-azloadbalanceroutboundruleconfig) [**New-AzLoadBalancerProbeConfig**](#new-azloadbalancerprobeconfig) [**New-AzLoadBalancerRuleConfig**](#new-azloadbalancerruleconfig) [**New-AzLocalNetworkGateway**](#new-azlocalnetworkgateway) [New-AzNatGateway](#new-aznatgateway) [**New-AzNetworkInterface**](#new-aznetworkinterface) [New-AzNetworkInterfaceIpConfig](#new-aznetworkinterfaceipconfig) [New-AzNetworkProfile](#new-aznetworkprofile) [**New-AzNetworkSecurityGroup**](#new-aznetworksecuritygroup) [**New-AzNetworkSecurityRuleConfig**](#new-aznetworksecurityruleconfig) [New-AzNetworkWatcher](#new-aznetworkwatcher) [New-AzNetworkWatcherConnectionMonitor](#new-aznetworkwatcherconnectionmonitor) [New-AzNetworkWatcherNetworkConfigurationDiagnosticProfile](#new-aznetworkwatchernetworkconfigurationdiagnosticprofile) [**New-AzNetworkWatcherPacketCapture**](#new-aznetworkwatcherpacketcapture) [New-AzNetworkWatcherProtocolConfiguration](#new-aznetworkwatcherprotocolconfiguration) [**New-AzPacketCaptureFilterConfig**](#new-azpacketcapturefilterconfig) [New-AzPrivateEndpoint](#new-azprivateendpoint) [New-AzPrivateLinkService](#new-azprivatelinkservice) [New-AzPrivateLinkServiceConnection](#new-azprivatelinkserviceconnection) [New-AzPrivateLinkServiceIpConfig](#new-azprivatelinkserviceipconfig) [**New-AzPublicIpAddress**](#new-azpublicipaddress) [New-AzPublicIpPrefix](#new-azpublicipprefix) [New-AzPublicIpTag](#new-azpubliciptag) [New-AzRouteConfig](#new-azrouteconfig) [New-AzRouteFilter](#new-azroutefilter) [New-AzRouteFilterRuleConfig](#new-azroutefilterruleconfig) [**New-AzRouteTable**](#new-azroutetable) [New-AzServiceEndpointPolicy](#new-azserviceendpointpolicy) [New-AzServiceEndpointPolicyDefinition](#new-azserviceendpointpolicydefinition) [New-AzVirtualHub](#new-azvirtualhub) [New-AzVirtualHubRoute](#new-azvirtualhubroute) [New-AzVirtualHubRouteTable](#new-azvirtualhubroutetable) [New-AzVirtualHubVnetConnection](#new-azvirtualhubvnetconnection) [**New-AzVirtualNetwork**](#new-azvirtualnetwork) [**New-AzVirtualNetworkGateway**](#new-azvirtualnetworkgateway) [**New-AzVirtualNetworkGatewayConnection**](#new-azvirtualnetworkgatewayconnection) [**New-AzVirtualNetworkGatewayIpConfig**](#new-azvirtualnetworkgatewayipconfig) [**New-AzVirtualNetworkSubnetConfig**](#new-azvirtualnetworksubnetconfig) [New-AzVirtualNetworkTap](#new-azvirtualnetworktap) [New-AzVirtualWan](#new-azvirtualwan) [New-AzVpnClientConfiguration](#new-azvpnclientconfiguration) [New-AzVpnClientIpsecParameter](#new-azvpnclientipsecparameter) [New-AzVpnClientIpsecPolicy](#new-azvpnclientipsecpolicy) [New-AzVpnClientRevokedCertificate](#new-azvpnclientrevokedcertificate) [New-AzVpnClientRootCertificate](#new-azvpnclientrootcertificate) [New-AzVpnConnection](#new-azvpnconnection) [New-AzVpnGateway](#new-azvpngateway) [New-AzVpnSite](#new-azvpnsite) [Remove-AzApplicationGateway](#remove-azapplicationgateway) [Remove-AzApplicationGatewayAuthenticationCertificate](#remove-azapplicationgatewayauthenticationcertificate) [Remove-AzApplicationGatewayAutoscaleConfiguration](#remove-azapplicationgatewayautoscaleconfiguration) [Remove-AzApplicationGatewayBackendAddressPool](#remove-azapplicationgatewaybackendaddresspool) [Remove-AzApplicationGatewayBackendHttpSetting](#remove-azapplicationgatewaybackendhttpsetting) [Remove-AzApplicationGatewayConnectionDraining](#remove-azapplicationgatewayconnectiondraining) [Remove-AzApplicationGatewayCustomError](#remove-azapplicationgatewaycustomerror) [Remove-AzApplicationGatewayFirewallPolicy](#remove-azapplicationgatewayfirewallpolicy) [Remove-AzApplicationGatewayFrontendIPConfig](#remove-azapplicationgatewayfrontendipconfig) [Remove-AzApplicationGatewayFrontendPort](#remove-azapplicationgatewayfrontendport) [Remove-AzApplicationGatewayHttpListener](#remove-azapplicationgatewayhttplistener) [Remove-AzApplicationGatewayHttpListenerCustomError](#remove-azapplicationgatewayhttplistenercustomerror) [Remove-AzApplicationGatewayIdentity](#remove-azapplicationgatewayidentity) [Remove-AzApplicationGatewayIPConfiguration](#remove-azapplicationgatewayipconfiguration) [Remove-AzApplicationGatewayProbeConfig](#remove-azapplicationgatewayprobeconfig) [Remove-AzApplicationGatewayRedirectConfiguration](#remove-azapplicationgatewayredirectconfiguration) [Remove-AzApplicationGatewayRequestRoutingRule](#remove-azapplicationgatewayrequestroutingrule) [Remove-AzApplicationGatewayRewriteRuleSet](#remove-azapplicationgatewayrewriteruleset) [Remove-AzApplicationGatewaySslCertificate](#remove-azapplicationgatewaysslcertificate) [Remove-AzApplicationGatewaySslPolicy](#remove-azapplicationgatewaysslpolicy) [Remove-AzApplicationGatewayTrustedRootCertificate](#remove-azapplicationgatewaytrustedrootcertificate) [Remove-AzApplicationGatewayUrlPathMapConfig](#remove-azapplicationgatewayurlpathmapconfig) [Remove-AzApplicationSecurityGroup](#remove-azapplicationsecuritygroup) [Remove-AzDdosProtectionPlan](#remove-azddosprotectionplan) [Remove-AzDelegation](#remove-azdelegation) [Remove-AzExpressRouteCircuit](#remove-azexpressroutecircuit) [Remove-AzExpressRouteCircuitAuthorization](#remove-azexpressroutecircuitauthorization) [Remove-AzExpressRouteCircuitConnectionConfig](#remove-azexpressroutecircuitconnectionconfig) [Remove-AzExpressRouteCircuitPeeringConfig](#remove-azexpressroutecircuitpeeringconfig) [Remove-AzExpressRouteConnection](#remove-azexpressrouteconnection) [Remove-AzExpressRouteCrossConnectionPeering](#remove-azexpressroutecrossconnectionpeering) [Remove-AzExpressRouteGateway](#remove-azexpressroutegateway) [Remove-AzExpressRoutePort](#remove-azexpressrouteport) [Remove-AzFirewall](#remove-azfirewall) [Remove-AzLoadBalancer](#remove-azloadbalancer) [Remove-AzLoadBalancerBackendAddressPoolConfig](#remove-azloadbalancerbackendaddresspoolconfig) [Remove-AzLoadBalancerFrontendIpConfig](#remove-azloadbalancerfrontendipconfig) [Remove-AzLoadBalancerInboundNatPoolConfig](#remove-azloadbalancerinboundnatpoolconfig) [Remove-AzLoadBalancerInboundNatRuleConfig](#remove-azloadbalancerinboundnatruleconfig) [Remove-AzLoadBalancerOutboundRuleConfig](#remove-azloadbalanceroutboundruleconfig) [Remove-AzLoadBalancerProbeConfig](#remove-azloadbalancerprobeconfig) [Remove-AzLoadBalancerRuleConfig](#remove-azloadbalancerruleconfig) [Remove-AzLocalNetworkGateway](#remove-azlocalnetworkgateway) [Remove-AzNatGateway](#remove-aznatgateway) [Remove-AzNetworkInterface](#remove-aznetworkinterface) [Remove-AzNetworkInterfaceIpConfig](#remove-aznetworkinterfaceipconfig) [Remove-AzNetworkInterfaceTapConfig](#remove-aznetworkinterfacetapconfig) [Remove-AzNetworkProfile](#remove-aznetworkprofile) [Remove-AzNetworkSecurityGroup](#remove-aznetworksecuritygroup) [Remove-AzNetworkSecurityRuleConfig](#remove-aznetworksecurityruleconfig) [Remove-AzNetworkWatcher](#remove-aznetworkwatcher) [Remove-AzNetworkWatcherConnectionMonitor](#remove-aznetworkwatcherconnectionmonitor) [Remove-AzNetworkWatcherPacketCapture](#remove-aznetworkwatcherpacketcapture) [Remove-AzPrivateEndpoint](#remove-azprivateendpoint) [Remove-AzPrivateEndpointConnection](#remove-azprivateendpointconnection) [Remove-AzPrivateLinkService](#remove-azprivatelinkservice) [Remove-AzPublicIpAddress](#remove-azpublicipaddress) [Remove-AzPublicIpPrefix](#remove-azpublicipprefix) [Remove-AzRouteConfig](#remove-azrouteconfig) [Remove-AzRouteFilter](#remove-azroutefilter) [Remove-AzRouteFilterRuleConfig](#remove-azroutefilterruleconfig) [Remove-AzRouteTable](#remove-azroutetable) [Remove-AzServiceEndpointPolicy](#remove-azserviceendpointpolicy) [Remove-AzServiceEndpointPolicyDefinition](#remove-azserviceendpointpolicydefinition) [Remove-AzVirtualHub](#remove-azvirtualhub) [Remove-AzVirtualHubVnetConnection](#remove-azvirtualhubvnetconnection) [Remove-AzVirtualNetwork](#remove-azvirtualnetwork) [Remove-AzVirtualNetworkGateway](#remove-azvirtualnetworkgateway) [Remove-AzVirtualNetworkGatewayConnection](#remove-azvirtualnetworkgatewayconnection) [Remove-AzVirtualNetworkGatewayDefaultSite](#remove-azvirtualnetworkgatewaydefaultsite) [Remove-AzVirtualNetworkGatewayIpConfig](#remove-azvirtualnetworkgatewayipconfig) [Remove-AzVirtualNetworkPeering](#remove-azvirtualnetworkpeering) [Remove-AzVirtualNetworkSubnetConfig](#remove-azvirtualnetworksubnetconfig) [Remove-AzVirtualNetworkTap](#remove-azvirtualnetworktap) [Remove-AzVirtualWan](#remove-azvirtualwan) [Remove-AzVpnClientIpsecParameter](#remove-azvpnclientipsecparameter) [Remove-AzVpnClientRevokedCertificate](#remove-azvpnclientrevokedcertificate) [Remove-AzVpnClientRootCertificate](#remove-azvpnclientrootcertificate) [Remove-AzVpnConnection](#remove-azvpnconnection) [Remove-AzVpnGateway](#remove-azvpngateway) [Remove-AzVpnSite](#remove-azvpnsite) [Reset-AzVirtualNetworkGateway](#reset-azvirtualnetworkgateway) [Reset-AzVirtualNetworkGatewayConnectionSharedKey](#reset-azvirtualnetworkgatewayconnectionsharedkey) [Resize-AzVirtualNetworkGateway](#resize-azvirtualnetworkgateway) [Set-AzApplicationGateway](#set-azapplicationgateway) [Set-AzApplicationGatewayAuthenticationCertificate](#set-azapplicationgatewayauthenticationcertificate) [Set-AzApplicationGatewayAutoscaleConfiguration](#set-azapplicationgatewayautoscaleconfiguration) [Set-AzApplicationGatewayBackendAddressPool](#set-azapplicationgatewaybackendaddresspool) [Set-AzApplicationGatewayBackendHttpSetting](#set-azapplicationgatewaybackendhttpsetting) [Set-AzApplicationGatewayConnectionDraining](#set-azapplicationgatewayconnectiondraining) [Set-AzApplicationGatewayCustomError](#set-azapplicationgatewaycustomerror) [Set-AzApplicationGatewayFirewallPolicy](#set-azapplicationgatewayfirewallpolicy) [Set-AzApplicationGatewayFrontendIPConfig](#set-azapplicationgatewayfrontendipconfig) [Set-AzApplicationGatewayFrontendPort](#set-azapplicationgatewayfrontendport) [Set-AzApplicationGatewayHttpListener](#set-azapplicationgatewayhttplistener) [Set-AzApplicationGatewayHttpListenerCustomError](#set-azapplicationgatewayhttplistenercustomerror) [Set-AzApplicationGatewayIdentity](#set-azapplicationgatewayidentity) [Set-AzApplicationGatewayIPConfiguration](#set-azapplicationgatewayipconfiguration) [Set-AzApplicationGatewayProbeConfig](#set-azapplicationgatewayprobeconfig) [Set-AzApplicationGatewayRedirectConfiguration](#set-azapplicationgatewayredirectconfiguration) [Set-AzApplicationGatewayRequestRoutingRule](#set-azapplicationgatewayrequestroutingrule) [Set-AzApplicationGatewayRewriteRuleSet](#set-azapplicationgatewayrewriteruleset) [Set-AzApplicationGatewaySku](#set-azapplicationgatewaysku) [Set-AzApplicationGatewaySslCertificate](#set-azapplicationgatewaysslcertificate) [Set-AzApplicationGatewaySslPolicy](#set-azapplicationgatewaysslpolicy) [Set-AzApplicationGatewayTrustedRootCertificate](#set-azapplicationgatewaytrustedrootcertificate) [Set-AzApplicationGatewayUrlPathMapConfig](#set-azapplicationgatewayurlpathmapconfig) [Set-AzApplicationGatewayWebApplicationFirewallConfiguration](#set-azapplicationgatewaywebapplicationfirewallconfiguration) [Set-AzExpressRouteCircuit](#set-azexpressroutecircuit) [Set-AzExpressRouteCircuitPeeringConfig](#set-azexpressroutecircuitpeeringconfig) [Set-AzExpressRouteConnection](#set-azexpressrouteconnection) [Set-AzExpressRouteCrossConnection](#set-azexpressroutecrossconnection) [Set-AzExpressRouteGateway](#set-azexpressroutegateway) [Set-AzExpressRoutePort](#set-azexpressrouteport) [Set-AzFirewall](#set-azfirewall) [**Set-AzLoadBalancer**](#set-azloadbalancer) [Set-AzLoadBalancerFrontendIpConfig](#set-azloadbalancerfrontendipconfig) [Set-AzLoadBalancerInboundNatPoolConfig](#set-azloadbalancerinboundnatpoolconfig) [Set-AzLoadBalancerInboundNatRuleConfig](#set-azloadbalancerinboundnatruleconfig) [Set-AzLoadBalancerOutboundRuleConfig](#set-azloadbalanceroutboundruleconfig) [Set-AzLoadBalancerProbeConfig](#set-azloadbalancerprobeconfig) [Set-AzLoadBalancerRuleConfig](#set-azloadbalancerruleconfig) [Set-AzLocalNetworkGateway](#set-azlocalnetworkgateway) [Set-AzNatGateway](#set-aznatgateway) [**Set-AzNetworkInterface**](#set-aznetworkinterface) [**Set-AzNetworkInterfaceIpConfig**](#set-aznetworkinterfaceipconfig) [Set-AzNetworkInterfaceTapConfig](#set-aznetworkinterfacetapconfig) [Set-AzNetworkProfile](#set-aznetworkprofile) [Set-AzNetworkSecurityGroup](#set-aznetworksecuritygroup) [Set-AzNetworkSecurityRuleConfig](#set-aznetworksecurityruleconfig) [Set-AzNetworkWatcherConfigFlowLog](#set-aznetworkwatcherconfigflowlog) [Set-AzNetworkWatcherConnectionMonitor](#set-aznetworkwatcherconnectionmonitor) [Set-AzPrivateEndpoint](#set-azprivateendpoint) [Set-AzPrivateEndpointConnection](#set-azprivateendpointconnection) [Set-AzPrivateLinkService](#set-azprivatelinkservice) [Set-AzPublicIpAddress](#set-azpublicipaddress) [Set-AzPublicIpPrefix](#set-azpublicipprefix) [Set-AzRouteConfig](#set-azrouteconfig) [Set-AzRouteFilter](#set-azroutefilter) [Set-AzRouteFilterRuleConfig](#set-azroutefilterruleconfig) [**Set-AzRouteTable**](#set-azroutetable) [Set-AzServiceEndpointPolicy](#set-azserviceendpointpolicy) [Set-AzServiceEndpointPolicyDefinition](#set-azserviceendpointpolicydefinition) [**Set-AzVirtualNetwork**](#set-azvirtualnetwork) [Set-AzVirtualNetworkGateway](#set-azvirtualnetworkgateway) [Set-AzVirtualNetworkGatewayConnection](#set-azvirtualnetworkgatewayconnection) [Set-AzVirtualNetworkGatewayConnectionSharedKey](#set-azvirtualnetworkgatewayconnectionsharedkey) [Set-AzVirtualNetworkGatewayDefaultSite](#set-azvirtualnetworkgatewaydefaultsite) [Set-AzVirtualNetworkPeering](#set-azvirtualnetworkpeering) [**Set-AzVirtualNetworkSubnetConfig**](#set-azvirtualnetworksubnetconfig) [Set-AzVirtualNetworkTap](#set-azvirtualnetworktap) [Set-AzVpnClientIpsecParameter](#set-azvpnclientipsecparameter) [Start-AzApplicationGateway](#start-azapplicationgateway) [Start-AzNetworkWatcherConnectionMonitor](#start-aznetworkwatcherconnectionmonitor) [**Start-AzNetworkWatcherResourceTroubleshooting**](#start-aznetworkwatcherresourcetroubleshooting) [Stop-AzApplicationGateway](#stop-azapplicationgateway) [Stop-AzNetworkWatcherConnectionMonitor](#stop-aznetworkwatcherconnectionmonitor) [**Stop-AzNetworkWatcherPacketCapture**](#stop-aznetworkwatcherpacketcapture) [Test-AzDnsAvailability](#test-azdnsavailability) [**Test-AzNetworkWatcherConnectivity**](#test-aznetworkwatcherconnectivity) [**Test-AzNetworkWatcherIPFlow**](#test-aznetworkwatcheripflow) [Test-AzPrivateIPAddressAvailability](#test-azprivateipaddressavailability) [Test-AzPrivateLinkServiceVisibility](#test-azprivatelinkservicevisibility) [Update-AzVirtualHub](#update-azvirtualhub) [Update-AzVirtualWan](#update-azvirtualwan) [Update-AzVpnConnection](#update-azvpnconnection) [Update-AzVpnGateway](#update-azvpngateway) [Update-AzVpnSite](#update-azvpnsite)
**Notificationhubs** [Get-AzNotificationHub](#get-aznotificationhub) [Get-AzNotificationHubAuthorizationRule](#get-aznotificationhubauthorizationrule) [Get-AzNotificationHubListKey](#get-aznotificationhublistkey) [Get-AzNotificationHubPNSCredential](#get-aznotificationhubpnscredential) [Get-AzNotificationHubsNamespace](#get-aznotificationhubsnamespace) [Get-AzNotificationHubsNamespaceAuthorizationRule](#get-aznotificationhubsnamespaceauthorizationrule) [Get-AzNotificationHubsNamespaceListKey](#get-aznotificationhubsnamespacelistkey) [New-AzNotificationHub](#new-aznotificationhub) [New-AzNotificationHubAuthorizationRule](#new-aznotificationhubauthorizationrule) [New-AzNotificationHubKey](#new-aznotificationhubkey) [New-AzNotificationHubsNamespace](#new-aznotificationhubsnamespace) [New-AzNotificationHubsNamespaceAuthorizationRule](#new-aznotificationhubsnamespaceauthorizationrule) [New-AzNotificationHubsNamespaceKey](#new-aznotificationhubsnamespacekey) [Remove-AzNotificationHub](#remove-aznotificationhub) [Remove-AzNotificationHubAuthorizationRule](#remove-aznotificationhubauthorizationrule) [Remove-AzNotificationHubsNamespace](#remove-aznotificationhubsnamespace) [Remove-AzNotificationHubsNamespaceAuthorizationRule](#remove-aznotificationhubsnamespaceauthorizationrule) [Set-AzNotificationHub](#set-aznotificationhub) [Set-AzNotificationHubAuthorizationRule](#set-aznotificationhubauthorizationrule) [Set-AzNotificationHubsNamespace](#set-aznotificationhubsnamespace) [Set-AzNotificationHubsNamespaceAuthorizationRule](#set-aznotificationhubsnamespaceauthorizationrule)
**Operationalinsights** [Disable-AzOperationalInsightsIISLogCollection](#disable-azoperationalinsightsiislogcollection) [Disable-AzOperationalInsightsLinuxCustomLogCollection](#disable-azoperationalinsightslinuxcustomlogcollection) [Disable-AzOperationalInsightsLinuxPerformanceCollection](#disable-azoperationalinsightslinuxperformancecollection) [Disable-AzOperationalInsightsLinuxSyslogCollection](#disable-azoperationalinsightslinuxsyslogcollection) [Enable-AzOperationalInsightsIISLogCollection](#enable-azoperationalinsightsiislogcollection) [Enable-AzOperationalInsightsLinuxCustomLogCollection](#enable-azoperationalinsightslinuxcustomlogcollection) [Enable-AzOperationalInsightsLinuxPerformanceCollection](#enable-azoperationalinsightslinuxperformancecollection) [Enable-AzOperationalInsightsLinuxSyslogCollection](#enable-azoperationalinsightslinuxsyslogcollection) [Get-AzOperationalInsightsDataSource](#get-azoperationalinsightsdatasource) [Get-AzOperationalInsightsIntelligencePack](#get-azoperationalinsightsintelligencepack) [Get-AzOperationalInsightsLinkTarget](#get-azoperationalinsightslinktarget) [Get-AzOperationalInsightsSavedSearch](#get-azoperationalinsightssavedsearch) [Get-AzOperationalInsightsSavedSearchResult](#get-azoperationalinsightssavedsearchresult) [Get-AzOperationalInsightsSchema](#get-azoperationalinsightsschema) [Get-AzOperationalInsightsSearchResult](#get-azoperationalinsightssearchresult) [Get-AzOperationalInsightsStorageInsight](#get-azoperationalinsightsstorageinsight) [**Get-AzOperationalInsightsWorkspace**](#get-azoperationalinsightsworkspace) [Get-AzOperationalInsightsWorkspaceManagementGroup](#get-azoperationalinsightsworkspacemanagementgroup) [Get-AzOperationalInsightsWorkspaceSharedKey](#get-azoperationalinsightsworkspacesharedkey) [Get-AzOperationalInsightsWorkspaceUsage](#get-azoperationalinsightsworkspaceusage) [Invoke-AzOperationalInsightsQuery](#invoke-azoperationalinsightsquery) [New-AzOperationalInsightsApplicationInsightsDataSource](#new-azoperationalinsightsapplicationinsightsdatasource) [New-AzOperationalInsightsAzureActivityLogDataSource](#new-azoperationalinsightsazureactivitylogdatasource) [New-AzOperationalInsightsComputerGroup](#new-azoperationalinsightscomputergroup) [New-AzOperationalInsightsCustomLogDataSource](#new-azoperationalinsightscustomlogdatasource) [New-AzOperationalInsightsLinuxPerformanceObjectDataSource](#new-azoperationalinsightslinuxperformanceobjectdatasource) [New-AzOperationalInsightsLinuxSyslogDataSource](#new-azoperationalinsightslinuxsyslogdatasource) [New-AzOperationalInsightsSavedSearch](#new-azoperationalinsightssavedsearch) [New-AzOperationalInsightsStorageInsight](#new-azoperationalinsightsstorageinsight) [New-AzOperationalInsightsWindowsEventDataSource](#new-azoperationalinsightswindowseventdatasource) [New-AzOperationalInsightsWindowsPerformanceCounterDataSource](#new-azoperationalinsightswindowsperformancecounterdatasource) [New-AzOperationalInsightsWorkspace](#new-azoperationalinsightsworkspace) [Remove-AzOperationalInsightsDataSource](#remove-azoperationalinsightsdatasource) [Remove-AzOperationalInsightsSavedSearch](#remove-azoperationalinsightssavedsearch) [Remove-AzOperationalInsightsStorageInsight](#remove-azoperationalinsightsstorageinsight) [Remove-AzOperationalInsightsWorkspace](#remove-azoperationalinsightsworkspace) [Set-AzOperationalInsightsDataSource](#set-azoperationalinsightsdatasource) [Set-AzOperationalInsightsIntelligencePack](#set-azoperationalinsightsintelligencepack) [Set-AzOperationalInsightsSavedSearch](#set-azoperationalinsightssavedsearch) [Set-AzOperationalInsightsStorageInsight](#set-azoperationalinsightsstorageinsight) [Set-AzOperationalInsightsWorkspace](#set-azoperationalinsightsworkspace)
**Peering** [Get-AzLegacyPeering](#get-azlegacypeering) [Get-AzPeerAsn](#get-azpeerasn) [Get-AzPeering](#get-azpeering) [Get-AzPeeringLocation](#get-azpeeringlocation) [New-AzPeerAsn](#new-azpeerasn) [New-AzPeering](#new-azpeering) [New-AzPeeringDirectConnectionObject](#new-azpeeringdirectconnectionobject) [New-AzPeeringExchangeConnectionObject](#new-azpeeringexchangeconnectionobject) [Remove-AzPeerAsn](#remove-azpeerasn) [Set-AzPeerAsn](#set-azpeerasn) [Set-AzPeeringDirectConnectionObject](#set-azpeeringdirectconnectionobject) [Set-AzPeeringExchangeConnectionObject](#set-azpeeringexchangeconnectionobject) [Update-AzPeering](#update-azpeering)
**Policyinsights** [Get-AzPolicyEvent](#get-azpolicyevent) [Get-AzPolicyRemediation](#get-azpolicyremediation) [Get-AzPolicyState](#get-azpolicystate) [Get-AzPolicyStateSummary](#get-azpolicystatesummary) [Remove-AzPolicyRemediation](#remove-azpolicyremediation) [Start-AzPolicyRemediation](#start-azpolicyremediation) [Stop-AzPolicyRemediation](#stop-azpolicyremediation)
**Powerbiembedded** [Get-AzPowerBIEmbeddedCapacity](#get-azpowerbiembeddedcapacity) [Get-AzPowerBIWorkspace](#get-azpowerbiworkspace) [Get-AzPowerBIWorkspaceCollection](#get-azpowerbiworkspacecollection) [Get-AzPowerBIWorkspaceCollectionAccessKey](#get-azpowerbiworkspacecollectionaccesskey) [New-AzPowerBIEmbeddedCapacity](#new-azpowerbiembeddedcapacity) [New-AzPowerBIWorkspaceCollection](#new-azpowerbiworkspacecollection) [Remove-AzPowerBIEmbeddedCapacity](#remove-azpowerbiembeddedcapacity) [Remove-AzPowerBIWorkspaceCollection](#remove-azpowerbiworkspacecollection) [Reset-AzPowerBIWorkspaceCollectionAccessKey](#reset-azpowerbiworkspacecollectionaccesskey) [Resume-AzPowerBIEmbeddedCapacity](#resume-azpowerbiembeddedcapacity) [Suspend-AzPowerBIEmbeddedCapacity](#suspend-azpowerbiembeddedcapacity) [Test-AzPowerBIEmbeddedCapacity](#test-azpowerbiembeddedcapacity) [Update-AzPowerBIEmbeddedCapacity](#update-azpowerbiembeddedcapacity)
**Privatedns** [Add-AzPrivateDnsRecordConfig](#add-azprivatednsrecordconfig) [Get-AzPrivateDnsRecordSet](#get-azprivatednsrecordset) [Get-AzPrivateDnsVirtualNetworkLink](#get-azprivatednsvirtualnetworklink) [Get-AzPrivateDnsZone](#get-azprivatednszone) [New-AzPrivateDnsRecordConfig](#new-azprivatednsrecordconfig) [New-AzPrivateDnsRecordSet](#new-azprivatednsrecordset) [New-AzPrivateDnsVirtualNetworkLink](#new-azprivatednsvirtualnetworklink) [New-AzPrivateDnsZone](#new-azprivatednszone) [Remove-AzPrivateDnsRecordConfig](#remove-azprivatednsrecordconfig) [Remove-AzPrivateDnsRecordSet](#remove-azprivatednsrecordset) [Remove-AzPrivateDnsVirtualNetworkLink](#remove-azprivatednsvirtualnetworklink) [Remove-AzPrivateDnsZone](#remove-azprivatednszone) [Set-AzPrivateDnsRecordSet](#set-azprivatednsrecordset) [Set-AzPrivateDnsVirtualNetworkLink](#set-azprivatednsvirtualnetworklink) [Set-AzPrivateDnsZone](#set-azprivatednszone)
**Recoveryservices** [Backup-AzRecoveryServicesBackupItem](#backup-azrecoveryservicesbackupitem) [Disable-AzRecoveryServicesBackupAutoProtection](#disable-azrecoveryservicesbackupautoprotection) [Disable-AzRecoveryServicesBackupProtection](#disable-azrecoveryservicesbackupprotection) [Disable-AzRecoveryServicesBackupRPMountScript](#disable-azrecoveryservicesbackuprpmountscript) [Edit-AzRecoveryServicesAsrRecoveryPlan](#edit-azrecoveryservicesasrrecoveryplan) [Enable-AzRecoveryServicesBackupAutoProtection](#enable-azrecoveryservicesbackupautoprotection) [Enable-AzRecoveryServicesBackupProtection](#enable-azrecoveryservicesbackupprotection) [Get-AzRecoveryServicesAsrAlertSetting](#get-azrecoveryservicesasralertsetting) [Get-AzRecoveryServicesAsrEvent](#get-azrecoveryservicesasrevent) [Get-AzRecoveryServicesAsrFabric](#get-azrecoveryservicesasrfabric) [Get-AzRecoveryServicesAsrJob](#get-azrecoveryservicesasrjob) [Get-AzRecoveryServicesAsrNetwork](#get-azrecoveryservicesasrnetwork) [Get-AzRecoveryServicesAsrNetworkMapping](#get-azrecoveryservicesasrnetworkmapping) [Get-AzRecoveryServicesAsrPolicy](#get-azrecoveryservicesasrpolicy) [Get-AzRecoveryServicesAsrProtectableItem](#get-azrecoveryservicesasrprotectableitem) [Get-AzRecoveryServicesAsrProtectionContainer](#get-azrecoveryservicesasrprotectioncontainer) [Get-AzRecoveryServicesAsrProtectionContainerMapping](#get-azrecoveryservicesasrprotectioncontainermapping) [Get-AzRecoveryServicesAsrRecoveryPlan](#get-azrecoveryservicesasrrecoveryplan) [Get-AzRecoveryServicesAsrRecoveryPoint](#get-azrecoveryservicesasrrecoverypoint) [Get-AzRecoveryServicesAsrReplicationProtectedItem](#get-azrecoveryservicesasrreplicationprotecteditem) [Get-AzRecoveryServicesAsrServicesProvider](#get-azrecoveryservicesasrservicesprovider) [Get-AzRecoveryServicesAsrStorageClassification](#get-azrecoveryservicesasrstorageclassification) [Get-AzRecoveryServicesAsrStorageClassificationMapping](#get-azrecoveryservicesasrstorageclassificationmapping) [Get-AzRecoveryServicesAsrVaultContext](#get-azrecoveryservicesasrvaultcontext) [Get-AzRecoveryServicesAsrvCenter](#get-azrecoveryservicesasrvcenter) [Get-AzRecoveryServicesBackupContainer](#get-azrecoveryservicesbackupcontainer) [Get-AzRecoveryServicesBackupItem](#get-azrecoveryservicesbackupitem) [Get-AzRecoveryServicesBackupJob](#get-azrecoveryservicesbackupjob) [Get-AzRecoveryServicesBackupJobDetail](#get-azrecoveryservicesbackupjobdetail) [Get-AzRecoveryServicesBackupManagementServer](#get-azrecoveryservicesbackupmanagementserver) [Get-AzRecoveryServicesBackupProperty](#get-azrecoveryservicesbackupproperty) [Get-AzRecoveryServicesBackupProtectableItem](#get-azrecoveryservicesbackupprotectableitem) [Get-AzRecoveryServicesBackupProtectionPolicy](#get-azrecoveryservicesbackupprotectionpolicy) [Get-AzRecoveryServicesBackupRecoveryLogChain](#get-azrecoveryservicesbackuprecoverylogchain) [Get-AzRecoveryServicesBackupRecoveryPoint](#get-azrecoveryservicesbackuprecoverypoint) [Get-AzRecoveryServicesBackupRetentionPolicyObject](#get-azrecoveryservicesbackupretentionpolicyobject) [Get-AzRecoveryServicesBackupRPMountScript](#get-azrecoveryservicesbackuprpmountscript) [Get-AzRecoveryServicesBackupSchedulePolicyObject](#get-azrecoveryservicesbackupschedulepolicyobject) [Get-AzRecoveryServicesBackupStatus](#get-azrecoveryservicesbackupstatus) [Get-AzRecoveryServicesBackupWorkloadRecoveryConfig](#get-azrecoveryservicesbackupworkloadrecoveryconfig) [Get-AzRecoveryServicesVault](#get-azrecoveryservicesvault) [Get-AzRecoveryServicesVaultSettingsFile](#get-azrecoveryservicesvaultsettingsfile) [Import-AzRecoveryServicesAsrVaultSettingsFile](#import-azrecoveryservicesasrvaultsettingsfile) [Initialize-AzRecoveryServicesBackupProtectableItem](#initialize-azrecoveryservicesbackupprotectableitem) [New-AzRecoveryServicesAsrAzureToAzureDiskReplicationConfig](#new-azrecoveryservicesasrazuretoazurediskreplicationconfig) [New-AzRecoveryServicesAsrFabric](#new-azrecoveryservicesasrfabric) [New-AzRecoveryServicesAsrNetworkMapping](#new-azrecoveryservicesasrnetworkmapping) [New-AzRecoveryServicesAsrPolicy](#new-azrecoveryservicesasrpolicy) [New-AzRecoveryServicesAsrProtectableItem](#new-azrecoveryservicesasrprotectableitem) [New-AzRecoveryServicesAsrProtectionContainer](#new-azrecoveryservicesasrprotectioncontainer) [New-AzRecoveryServicesAsrProtectionContainerMapping](#new-azrecoveryservicesasrprotectioncontainermapping) [New-AzRecoveryServicesAsrRecoveryPlan](#new-azrecoveryservicesasrrecoveryplan) [New-AzRecoveryServicesAsrReplicationProtectedItem](#new-azrecoveryservicesasrreplicationprotecteditem) [New-AzRecoveryServicesAsrStorageClassificationMapping](#new-azrecoveryservicesasrstorageclassificationmapping) [New-AzRecoveryServicesAsrvCenter](#new-azrecoveryservicesasrvcenter) [New-AzRecoveryServicesBackupProtectionPolicy](#new-azrecoveryservicesbackupprotectionpolicy) [New-AzRecoveryServicesVault](#new-azrecoveryservicesvault) [Register-AzRecoveryServicesBackupContainer](#register-azrecoveryservicesbackupcontainer) [Remove-AzRecoveryServicesAsrFabric](#remove-azrecoveryservicesasrfabric) [Remove-AzRecoveryServicesAsrNetworkMapping](#remove-azrecoveryservicesasrnetworkmapping) [Remove-AzRecoveryServicesAsrPolicy](#remove-azrecoveryservicesasrpolicy) [Remove-AzRecoveryServicesAsrProtectionContainer](#remove-azrecoveryservicesasrprotectioncontainer) [Remove-AzRecoveryServicesAsrProtectionContainerMapping](#remove-azrecoveryservicesasrprotectioncontainermapping) [Remove-AzRecoveryServicesAsrRecoveryPlan](#remove-azrecoveryservicesasrrecoveryplan) [Remove-AzRecoveryServicesAsrReplicationProtectedItem](#remove-azrecoveryservicesasrreplicationprotecteditem) [Remove-AzRecoveryServicesAsrServicesProvider](#remove-azrecoveryservicesasrservicesprovider) [Remove-AzRecoveryServicesAsrStorageClassificationMapping](#remove-azrecoveryservicesasrstorageclassificationmapping) [Remove-AzRecoveryServicesAsrvCenter](#remove-azrecoveryservicesasrvcenter) [Remove-AzRecoveryServicesBackupProtectionPolicy](#remove-azrecoveryservicesbackupprotectionpolicy) [Remove-AzRecoveryServicesVault](#remove-azrecoveryservicesvault) [Restart-AzRecoveryServicesAsrJob](#restart-azrecoveryservicesasrjob) [Restore-AzRecoveryServicesBackupItem](#restore-azrecoveryservicesbackupitem) [Resume-AzRecoveryServicesAsrJob](#resume-azrecoveryservicesasrjob) [Set-AzRecoveryServicesAsrAlertSetting](#set-azrecoveryservicesasralertsetting) [Set-AzRecoveryServicesAsrReplicationProtectedItem](#set-azrecoveryservicesasrreplicationprotecteditem) [Set-AzRecoveryServicesAsrVaultContext](#set-azrecoveryservicesasrvaultcontext) [Set-AzRecoveryServicesBackupProperty](#set-azrecoveryservicesbackupproperty) [Set-AzRecoveryServicesBackupProtectionPolicy](#set-azrecoveryservicesbackupprotectionpolicy) [Set-AzRecoveryServicesVaultContext](#set-azrecoveryservicesvaultcontext) [Start-AzRecoveryServicesAsrApplyRecoveryPoint](#start-azrecoveryservicesasrapplyrecoverypoint) [Start-AzRecoveryServicesAsrCommitFailoverJob](#start-azrecoveryservicesasrcommitfailoverjob) [Start-AzRecoveryServicesAsrPlannedFailoverJob](#start-azrecoveryservicesasrplannedfailoverjob) [Start-AzRecoveryServicesAsrResynchronizeReplicationJob](#start-azrecoveryservicesasrresynchronizereplicationjob) [Start-AzRecoveryServicesAsrSwitchProcessServerJob](#start-azrecoveryservicesasrswitchprocessserverjob) [Start-AzRecoveryServicesAsrTestFailoverCleanupJob](#start-azrecoveryservicesasrtestfailovercleanupjob) [Start-AzRecoveryServicesAsrTestFailoverJob](#start-azrecoveryservicesasrtestfailoverjob) [Start-AzRecoveryServicesAsrUnplannedFailoverJob](#start-azrecoveryservicesasrunplannedfailoverjob) [Stop-AzRecoveryServicesAsrJob](#stop-azrecoveryservicesasrjob) [Stop-AzRecoveryServicesBackupJob](#stop-azrecoveryservicesbackupjob) [Unregister-AzRecoveryServicesBackupContainer](#unregister-azrecoveryservicesbackupcontainer) [Unregister-AzRecoveryServicesBackupManagementServer](#unregister-azrecoveryservicesbackupmanagementserver) [Update-AzRecoveryServicesAsrMobilityService](#update-azrecoveryservicesasrmobilityservice) [Update-AzRecoveryServicesAsrNetworkMapping](#update-azrecoveryservicesasrnetworkmapping) [Update-AzRecoveryServicesAsrPolicy](#update-azrecoveryservicesasrpolicy) [Update-AzRecoveryServicesAsrProtectionDirection](#update-azrecoveryservicesasrprotectiondirection) [Update-AzRecoveryServicesAsrRecoveryPlan](#update-azrecoveryservicesasrrecoveryplan) [Update-AzRecoveryServicesAsrServicesProvider](#update-azrecoveryservicesasrservicesprovider) [Update-AzRecoveryServicesAsrvCenter](#update-azrecoveryservicesasrvcenter) [Wait-AzRecoveryServicesBackupJob](#wait-azrecoveryservicesbackupjob)
**Rediscache** [Export-AzRedisCache](#export-azrediscache) [Get-AzRedisCache](#get-azrediscache) [Get-AzRedisCacheFirewallRule](#get-azrediscachefirewallrule) [Get-AzRedisCacheKey](#get-azrediscachekey) [Get-AzRedisCacheLink](#get-azrediscachelink) [Get-AzRedisCachePatchSchedule](#get-azrediscachepatchschedule) [Import-AzRedisCache](#import-azrediscache) [New-AzRedisCache](#new-azrediscache) [New-AzRedisCacheFirewallRule](#new-azrediscachefirewallrule) [New-AzRedisCacheKey](#new-azrediscachekey) [New-AzRedisCacheLink](#new-azrediscachelink) [New-AzRedisCachePatchSchedule](#new-azrediscachepatchschedule) [New-AzRedisCacheScheduleEntry](#new-azrediscachescheduleentry) [Remove-AzRedisCache](#remove-azrediscache) [Remove-AzRedisCacheDiagnostic](#remove-azrediscachediagnostic) [Remove-AzRedisCacheFirewallRule](#remove-azrediscachefirewallrule) [Remove-AzRedisCacheLink](#remove-azrediscachelink) [Remove-AzRedisCachePatchSchedule](#remove-azrediscachepatchschedule) [Reset-AzRedisCache](#reset-azrediscache) [Set-AzRedisCache](#set-azrediscache) [Set-AzRedisCacheDiagnostic](#set-azrediscachediagnostic)
**Relay** [Get-AzRelayAuthorizationRule](#get-azrelayauthorizationrule) [Get-AzRelayHybridConnection](#get-azrelayhybridconnection) [Get-AzRelayKey](#get-azrelaykey) [Get-AzRelayNamespace](#get-azrelaynamespace) [Get-AzRelayOperation](#get-azrelayoperation) [Get-AzWcfRelay](#get-azwcfrelay) [New-AzRelayAuthorizationRule](#new-azrelayauthorizationrule) [New-AzRelayHybridConnection](#new-azrelayhybridconnection) [New-AzRelayKey](#new-azrelaykey) [New-AzRelayNamespace](#new-azrelaynamespace) [New-AzWcfRelay](#new-azwcfrelay) [Remove-AzRelayAuthorizationRule](#remove-azrelayauthorizationrule) [Remove-AzRelayHybridConnection](#remove-azrelayhybridconnection) [Remove-AzRelayNamespace](#remove-azrelaynamespace) [Remove-AzWcfRelay](#remove-azwcfrelay) [Set-AzRelayAuthorizationRule](#set-azrelayauthorizationrule) [Set-AzRelayHybridConnection](#set-azrelayhybridconnection) [Set-AzRelayNamespace](#set-azrelaynamespace) [Set-AzWcfRelay](#set-azwcfrelay) [Test-AzRelayName](#test-azrelayname)
**Reservations** [Get-AzReservation](#get-azreservation) [Get-AzReservationCatalog](#get-azreservationcatalog) [Get-AzReservationHistory](#get-azreservationhistory) [Get-AzReservationOrder](#get-azreservationorder) [Get-AzReservationOrderId](#get-azreservationorderid) [Merge-AzReservation](#merge-azreservation) [Split-AzReservation](#split-azreservation) [Update-AzReservation](#update-azreservation)
**Resourcegraph** [Search-AzGraph](#search-azgraph)
**Resources** [Add-AzADGroupMember](#add-azadgroupmember) [**Export-AzResourceGroup**](#export-azresourcegroup) [Get-AzADAppCredential](#get-azadappcredential) [Get-AzADApplication](#get-azadapplication) [**Get-AzADGroup**](#get-azadgroup) [Get-AzADGroupMember](#get-azadgroupmember) [Get-AzADServicePrincipal](#get-azadserviceprincipal) [Get-AzADSpCredential](#get-azadspcredential) [Get-AzADUser](#get-azaduser) [Get-AzDenyAssignment](#get-azdenyassignment) [Get-AzDeployment](#get-azdeployment) [Get-AzDeploymentOperation](#get-azdeploymentoperation) [Get-AzLocation](#get-azlocation) [Get-AzManagedApplication](#get-azmanagedapplication) [Get-AzManagedApplicationDefinition](#get-azmanagedapplicationdefinition) [Get-AzManagementGroup](#get-azmanagementgroup) [Get-AzPolicyAlias](#get-azpolicyalias) [Get-AzPolicyAssignment](#get-azpolicyassignment) [Get-AzPolicyDefinition](#get-azpolicydefinition) [Get-AzPolicySetDefinition](#get-azpolicysetdefinition) [Get-AzProviderFeature](#get-azproviderfeature) [**Get-AzProviderOperation**](#get-azprovideroperation) [**Get-AzResource**](#get-azresource) [**Get-AzResourceGroup**](#get-azresourcegroup) [Get-AzResourceGroupDeployment](#get-azresourcegroupdeployment) [Get-AzResourceGroupDeploymentOperation](#get-azresourcegroupdeploymentoperation) [Get-AzResourceLock](#get-azresourcelock) [Get-AzResourceProvider](#get-azresourceprovider) [Get-AzRoleAssignment](#get-azroleassignment) [**Get-AzRoleDefinition**](#get-azroledefinition) [Get-AzTag](#get-aztag) [Invoke-AzResourceAction](#invoke-azresourceaction) [**Move-AzResource**](#move-azresource) [New-AzADAppCredential](#new-azadappcredential) [New-AzADApplication](#new-azadapplication) [New-AzADGroup](#new-azadgroup) [New-AzADServicePrincipal](#new-azadserviceprincipal) [New-AzADSpCredential](#new-azadspcredential) [New-AzADUser](#new-azaduser) [New-AzDeployment](#new-azdeployment) [New-AzManagedApplication](#new-azmanagedapplication) [New-AzManagedApplicationDefinition](#new-azmanagedapplicationdefinition) [New-AzManagementGroup](#new-azmanagementgroup) [New-AzManagementGroupSubscription](#new-azmanagementgroupsubscription) [New-AzPolicyAssignment](#new-azpolicyassignment) [New-AzPolicyDefinition](#new-azpolicydefinition) [New-AzPolicySetDefinition](#new-azpolicysetdefinition) [New-AzResource](#new-azresource) [**New-AzResourceGroup**](#new-azresourcegroup) [**New-AzResourceGroupDeployment**](#new-azresourcegroupdeployment) [New-AzResourceLock](#new-azresourcelock) [**New-AzRoleAssignment**](#new-azroleassignment) [New-AzRoleDefinition](#new-azroledefinition) [New-AzTag](#new-aztag) [Register-AzProviderFeature](#register-azproviderfeature) [**Register-AzResourceProvider**](#register-azresourceprovider) [Remove-AzADAppCredential](#remove-azadappcredential) [Remove-AzADApplication](#remove-azadapplication) [Remove-AzADGroup](#remove-azadgroup) [Remove-AzADGroupMember](#remove-azadgroupmember) [Remove-AzADServicePrincipal](#remove-azadserviceprincipal) [Remove-AzADSpCredential](#remove-azadspcredential) [Remove-AzADUser](#remove-azaduser) [Remove-AzDeployment](#remove-azdeployment) [Remove-AzManagedApplication](#remove-azmanagedapplication) [Remove-AzManagedApplicationDefinition](#remove-azmanagedapplicationdefinition) [Remove-AzManagementGroup](#remove-azmanagementgroup) [Remove-AzManagementGroupSubscription](#remove-azmanagementgroupsubscription) [Remove-AzPolicyAssignment](#remove-azpolicyassignment) [Remove-AzPolicyDefinition](#remove-azpolicydefinition) [Remove-AzPolicySetDefinition](#remove-azpolicysetdefinition) [Remove-AzResource](#remove-azresource) [**Remove-AzResourceGroup**](#remove-azresourcegroup) [Remove-AzResourceGroupDeployment](#remove-azresourcegroupdeployment) [Remove-AzResourceLock](#remove-azresourcelock) [**Remove-AzRoleAssignment**](#remove-azroleassignment) [Remove-AzRoleDefinition](#remove-azroledefinition) [Remove-AzTag](#remove-aztag) [Save-AzDeploymentTemplate](#save-azdeploymenttemplate) [**Save-AzResourceGroupDeploymentTemplate**](#save-azresourcegroupdeploymenttemplate) [Set-AzManagedApplication](#set-azmanagedapplication) [Set-AzManagedApplicationDefinition](#set-azmanagedapplicationdefinition) [Set-AzPolicyAssignment](#set-azpolicyassignment) [Set-AzPolicyDefinition](#set-azpolicydefinition) [Set-AzPolicySetDefinition](#set-azpolicysetdefinition) [Set-AzResource](#set-azresource) [**Set-AzResourceGroup**](#set-azresourcegroup) [Set-AzResourceLock](#set-azresourcelock) [Set-AzRoleDefinition](#set-azroledefinition) [Stop-AzDeployment](#stop-azdeployment) [Stop-AzResourceGroupDeployment](#stop-azresourcegroupdeployment) [Test-AzDeployment](#test-azdeployment) [Test-AzResourceGroupDeployment](#test-azresourcegroupdeployment) [Unregister-AzResourceProvider](#unregister-azresourceprovider) [Update-AzADApplication](#update-azadapplication) [Update-AzADServicePrincipal](#update-azadserviceprincipal) [Update-AzADUser](#update-azaduser) [Update-AzManagementGroup](#update-azmanagementgroup)
**Search** [Get-AzSearchAdminKeyPair](#get-azsearchadminkeypair) [Get-AzSearchQueryKey](#get-azsearchquerykey) [Get-AzSearchService](#get-azsearchservice) [New-AzSearchAdminKey](#new-azsearchadminkey) [New-AzSearchQueryKey](#new-azsearchquerykey) [New-AzSearchService](#new-azsearchservice) [Remove-AzSearchQueryKey](#remove-azsearchquerykey) [Remove-AzSearchService](#remove-azsearchservice) [Set-AzSearchService](#set-azsearchservice)
**Security** [Disable-AzSecurityAdvancedThreatProtection](#disable-azsecurityadvancedthreatprotection) [Enable-AzSecurityAdvancedThreatProtection](#enable-azsecurityadvancedthreatprotection) [Get-AzDiscoveredSecuritySolution](#get-azdiscoveredsecuritysolution) [Get-AzExternalSecuritySolution](#get-azexternalsecuritysolution) [Get-AzJitNetworkAccessPolicy](#get-azjitnetworkaccesspolicy) [Get-AzSecurityAdvancedThreatProtection](#get-azsecurityadvancedthreatprotection) [Get-AzSecurityAlert](#get-azsecurityalert) [Get-AzSecurityAutoProvisioningSetting](#get-azsecurityautoprovisioningsetting) [Get-AzSecurityCompliance](#get-azsecuritycompliance) [Get-AzSecurityContact](#get-azsecuritycontact) [Get-AzSecurityLocation](#get-azsecuritylocation) [Get-AzSecurityPricing](#get-azsecuritypricing) [Get-AzSecurityTask](#get-azsecuritytask) [Get-AzSecurityWorkspaceSetting](#get-azsecurityworkspacesetting) [Remove-AzJitNetworkAccessPolicy](#remove-azjitnetworkaccesspolicy) [Remove-AzSecurityContact](#remove-azsecuritycontact) [Remove-AzSecurityWorkspaceSetting](#remove-azsecurityworkspacesetting) [Set-AzJitNetworkAccessPolicy](#set-azjitnetworkaccesspolicy) [Set-AzSecurityAlert](#set-azsecurityalert) [Set-AzSecurityAutoProvisioningSetting](#set-azsecurityautoprovisioningsetting) [Set-AzSecurityContact](#set-azsecuritycontact) [Set-AzSecurityPricing](#set-azsecuritypricing) [Set-AzSecurityWorkspaceSetting](#set-azsecurityworkspacesetting) [Start-AzJitNetworkAccessPolicy](#start-azjitnetworkaccesspolicy)
**Servicebus** [Complete-AzServiceBusMigration](#complete-azservicebusmigration) [Get-AzServiceBusAuthorizationRule](#get-azservicebusauthorizationrule) [Get-AzServiceBusGeoDRConfiguration](#get-azservicebusgeodrconfiguration) [Get-AzServiceBusKey](#get-azservicebuskey) [Get-AzServiceBusMigration](#get-azservicebusmigration) [Get-AzServiceBusNamespace](#get-azservicebusnamespace) [Get-AzServiceBusOperation](#get-azservicebusoperation) [Get-AzServiceBusQueue](#get-azservicebusqueue) [**Get-AzServiceBusRule**](#get-azservicebusrule) [Get-AzServiceBusSubscription](#get-azservicebussubscription) [Get-AzServiceBusTopic](#get-azservicebustopic) [New-AzServiceBusAuthorizationRule](#new-azservicebusauthorizationrule) [New-AzServiceBusAuthorizationRuleSASToken](#new-azservicebusauthorizationrulesastoken) [New-AzServiceBusGeoDRConfiguration](#new-azservicebusgeodrconfiguration) [New-AzServiceBusKey](#new-azservicebuskey) [New-AzServiceBusNamespace](#new-azservicebusnamespace) [New-AzServiceBusQueue](#new-azservicebusqueue) [New-AzServiceBusRule](#new-azservicebusrule) [New-AzServiceBusSubscription](#new-azservicebussubscription) [New-AzServiceBusTopic](#new-azservicebustopic) [Remove-AzServiceBusAuthorizationRule](#remove-azservicebusauthorizationrule) [Remove-AzServiceBusGeoDRConfiguration](#remove-azservicebusgeodrconfiguration) [Remove-AzServiceBusMigration](#remove-azservicebusmigration) [Remove-AzServiceBusNamespace](#remove-azservicebusnamespace) [Remove-AzServiceBusQueue](#remove-azservicebusqueue) [Remove-AzServiceBusRule](#remove-azservicebusrule) [Remove-AzServiceBusSubscription](#remove-azservicebussubscription) [Remove-AzServiceBusTopic](#remove-azservicebustopic) [Set-AzServiceBusAuthorizationRule](#set-azservicebusauthorizationrule) [Set-AzServiceBusGeoDRConfigurationBreakPair](#set-azservicebusgeodrconfigurationbreakpair) [Set-AzServiceBusGeoDRConfigurationFailOver](#set-azservicebusgeodrconfigurationfailover) [Set-AzServiceBusNamespace](#set-azservicebusnamespace) [Set-AzServiceBusQueue](#set-azservicebusqueue) [Set-AzServiceBusRule](#set-azservicebusrule) [Set-AzServiceBusSubscription](#set-azservicebussubscription) [Set-AzServiceBusTopic](#set-azservicebustopic) [Start-AzServiceBusMigration](#start-azservicebusmigration) [Stop-AzServiceBusMigration](#stop-azservicebusmigration) [Test-AzServiceBusName](#test-azservicebusname)
**Servicefabric** [Add-AzServiceFabricApplicationCertificate](#add-azservicefabricapplicationcertificate) [Add-AzServiceFabricClientCertificate](#add-azservicefabricclientcertificate) [Add-AzServiceFabricClusterCertificate](#add-azservicefabricclustercertificate) [Add-AzServiceFabricNode](#add-azservicefabricnode) [Add-AzServiceFabricNodeType](#add-azservicefabricnodetype) [Get-AzServiceFabricCluster](#get-azservicefabriccluster) [New-AzServiceFabricCluster](#new-azservicefabriccluster) [Remove-AzServiceFabricClientCertificate](#remove-azservicefabricclientcertificate) [Remove-AzServiceFabricClusterCertificate](#remove-azservicefabricclustercertificate) [Remove-AzServiceFabricNode](#remove-azservicefabricnode) [Remove-AzServiceFabricNodeType](#remove-azservicefabricnodetype) [Remove-AzServiceFabricSetting](#remove-azservicefabricsetting) [Set-AzServiceFabricSetting](#set-azservicefabricsetting) [Set-AzServiceFabricUpgradeType](#set-azservicefabricupgradetype) [Update-AzServiceFabricDurability](#update-azservicefabricdurability) [Update-AzServiceFabricReliability](#update-azservicefabricreliability)
**Signalr** [Get-AzSignalR](#get-azsignalr) [Get-AzSignalRKey](#get-azsignalrkey) [New-AzSignalR](#new-azsignalr) [New-AzSignalRKey](#new-azsignalrkey) [Remove-AzSignalR](#remove-azsignalr)
**Sql** [Add-AzSqlDatabaseToFailoverGroup](#add-azsqldatabasetofailovergroup) [Add-AzSqlInstanceKeyVaultKey](#add-azsqlinstancekeyvaultkey) [Add-AzSqlManagedInstanceTransparentDataEncryptionCertificate](#add-azsqlmanagedinstancetransparentdataencryptioncertificate) [Add-AzSqlServerKeyVaultKey](#add-azsqlserverkeyvaultkey) [Add-AzSqlServerTransparentDataEncryptionCertificate](#add-azsqlservertransparentdataencryptioncertificate) [Clear-AzSqlDatabaseAdvancedThreatProtectionSettings](#clear-azsqldatabaseadvancedthreatprotectionsettings) [Clear-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline](#clear-azsqldatabasevulnerabilityassessmentrulebaseline) [Clear-AzSqlDatabaseVulnerabilityAssessmentSetting](#clear-azsqldatabasevulnerabilityassessmentsetting) [Clear-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline](#clear-azsqlinstancedatabasevulnerabilityassessmentrulebaseline) [Clear-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting](#clear-azsqlinstancedatabasevulnerabilityassessmentsetting) [Clear-AzSqlInstanceVulnerabilityAssessmentSetting](#clear-azsqlinstancevulnerabilityassessmentsetting) [Clear-AzSqlServerAdvancedThreatProtectionSettings](#clear-azsqlserveradvancedthreatprotectionsettings) [Clear-AzSqlServerVulnerabilityAssessmentSetting](#clear-azsqlservervulnerabilityassessmentsetting) [Convert-AzSqlDatabaseVulnerabilityAssessmentScan](#convert-azsqldatabasevulnerabilityassessmentscan) [Convert-AzSqlInstanceDatabaseVulnerabilityAssessmentScan](#convert-azsqlinstancedatabasevulnerabilityassessmentscan) [Disable-AzSqlInstanceAdvancedDataSecurity](#disable-azsqlinstanceadvanceddatasecurity) [Disable-AzSqlServerAdvancedDataSecurity](#disable-azsqlserveradvanceddatasecurity) [Disable-AzSqlServerAdvancedThreatProtection](#disable-azsqlserveradvancedthreatprotection) [Enable-AzSqlInstanceAdvancedDataSecurity](#enable-azsqlinstanceadvanceddatasecurity) [Enable-AzSqlServerAdvancedDataSecurity](#enable-azsqlserveradvanceddatasecurity) [Enable-AzSqlServerAdvancedThreatProtection](#enable-azsqlserveradvancedthreatprotection) [Get-AzSqlCapability](#get-azsqlcapability) [Get-AzSqlDatabase](#get-azsqldatabase) [Get-AzSqlDatabaseActivity](#get-azsqldatabaseactivity) [Get-AzSqlDatabaseAdvancedThreatProtectionSettings](#get-azsqldatabaseadvancedthreatprotectionsettings) [Get-AzSqlDatabaseAdvisor](#get-azsqldatabaseadvisor) [Get-AzSqlDatabaseAudit](#get-azsqldatabaseaudit) [Get-AzSqlDatabaseAuditing](#get-azsqldatabaseauditing) [Get-AzSqlDatabaseBackupLongTermRetentionPolicy](#get-azsqldatabasebackuplongtermretentionpolicy) [Get-AzSqlDatabaseBackupShortTermRetentionPolicy](#get-azsqldatabasebackupshorttermretentionpolicy) [Get-AzSqlDatabaseDataMaskingPolicy](#get-azsqldatabasedatamaskingpolicy) [Get-AzSqlDatabaseDataMaskingRule](#get-azsqldatabasedatamaskingrule) [Get-AzSqlDatabaseExpanded](#get-azsqldatabaseexpanded) [Get-AzSqlDatabaseFailoverGroup](#get-azsqldatabasefailovergroup) [Get-AzSqlDatabaseGeoBackup](#get-azsqldatabasegeobackup) [Get-AzSqlDatabaseGeoBackupPolicy](#get-azsqldatabasegeobackuppolicy) [Get-AzSqlDatabaseImportExportStatus](#get-azsqldatabaseimportexportstatus) [Get-AzSqlDatabaseIndexRecommendation](#get-azsqldatabaseindexrecommendation) [Get-AzSqlDatabaseInstanceFailoverGroup](#get-azsqldatabaseinstancefailovergroup) [Get-AzSqlDatabaseLongTermRetentionBackup](#get-azsqldatabaselongtermretentionbackup) [Get-AzSqlDatabaseRecommendedAction](#get-azsqldatabaserecommendedaction) [Get-AzSqlDatabaseReplicationLink](#get-azsqldatabasereplicationlink) [Get-AzSqlDatabaseRestorePoint](#get-azsqldatabaserestorepoint) [Get-AzSqlDatabaseSecureConnectionPolicy](#get-azsqldatabasesecureconnectionpolicy) [Get-AzSqlDatabaseSensitivityClassification](#get-azsqldatabasesensitivityclassification) [Get-AzSqlDatabaseSensitivityRecommendation](#get-azsqldatabasesensitivityrecommendation) [Get-AzSqlDatabaseTransparentDataEncryption](#get-azsqldatabasetransparentdataencryption) [Get-AzSqlDatabaseTransparentDataEncryptionActivity](#get-azsqldatabasetransparentdataencryptionactivity) [Get-AzSqlDatabaseUpgradeHint](#get-azsqldatabaseupgradehint) [Get-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline](#get-azsqldatabasevulnerabilityassessmentrulebaseline) [Get-AzSqlDatabaseVulnerabilityAssessmentScanRecord](#get-azsqldatabasevulnerabilityassessmentscanrecord) [Get-AzSqlDatabaseVulnerabilityAssessmentSetting](#get-azsqldatabasevulnerabilityassessmentsetting) [Get-AzSqlDeletedDatabaseBackup](#get-azsqldeleteddatabasebackup) [Get-AzSqlDeletedInstanceDatabaseBackup](#get-azsqldeletedinstancedatabasebackup) [Get-AzSqlElasticPool](#get-azsqlelasticpool) [Get-AzSqlElasticPoolActivity](#get-azsqlelasticpoolactivity) [Get-AzSqlElasticPoolAdvisor](#get-azsqlelasticpooladvisor) [Get-AzSqlElasticPoolDatabase](#get-azsqlelasticpooldatabase) [Get-AzSqlElasticPoolRecommendation](#get-azsqlelasticpoolrecommendation) [Get-AzSqlElasticPoolRecommendedAction](#get-azsqlelasticpoolrecommendedaction) [Get-AzSqlInstance](#get-azsqlinstance) [Get-AzSqlInstanceAdvancedDataSecurityPolicy](#get-azsqlinstanceadvanceddatasecuritypolicy) [Get-AzSqlInstanceDatabase](#get-azsqlinstancedatabase) [Get-AzSqlInstanceDatabaseBackupShortTermRetentionPolicy](#get-azsqlinstancedatabasebackupshorttermretentionpolicy) [Get-AzSqlInstanceDatabaseGeoBackup](#get-azsqlinstancedatabasegeobackup) [Get-AzSqlInstanceDatabaseSensitivityClassification](#get-azsqlinstancedatabasesensitivityclassification) [Get-AzSqlInstanceDatabaseSensitivityRecommendation](#get-azsqlinstancedatabasesensitivityrecommendation) [Get-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline](#get-azsqlinstancedatabasevulnerabilityassessmentrulebaseline) [Get-AzSqlInstanceDatabaseVulnerabilityAssessmentScanRecord](#get-azsqlinstancedatabasevulnerabilityassessmentscanrecord) [Get-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting](#get-azsqlinstancedatabasevulnerabilityassessmentsetting) [Get-AzSqlInstanceKeyVaultKey](#get-azsqlinstancekeyvaultkey) [Get-AzSqlInstanceTransparentDataEncryptionProtector](#get-azsqlinstancetransparentdataencryptionprotector) [Get-AzSqlInstanceVulnerabilityAssessmentSetting](#get-azsqlinstancevulnerabilityassessmentsetting) [Get-AzSqlServer](#get-azsqlserver) [Get-AzSqlServerActiveDirectoryAdministrator](#get-azsqlserveractivedirectoryadministrator) [Get-AzSqlServerAdvancedDataSecurityPolicy](#get-azsqlserveradvanceddatasecuritypolicy) [Get-AzSqlServerAdvancedThreatProtectionPolicy](#get-azsqlserveradvancedthreatprotectionpolicy) [Get-AzSqlServerAdvancedThreatProtectionSettings](#get-azsqlserveradvancedthreatprotectionsettings) [Get-AzSqlServerAdvisor](#get-azsqlserveradvisor) [Get-AzSqlServerAudit](#get-azsqlserveraudit) [Get-AzSqlServerAuditing](#get-azsqlserverauditing) [Get-AzSqlServerCommunicationLink](#get-azsqlservercommunicationlink) [Get-AzSqlServerDisasterRecoveryConfiguration](#get-azsqlserverdisasterrecoveryconfiguration) [Get-AzSqlServerDisasterRecoveryConfigurationActivity](#get-azsqlserverdisasterrecoveryconfigurationactivity) [Get-AzSqlServerDnsAlias](#get-azsqlserverdnsalias) [Get-AzSqlServerFirewallRule](#get-azsqlserverfirewallrule) [Get-AzSqlServerKeyVaultKey](#get-azsqlserverkeyvaultkey) [Get-AzSqlServerRecommendedAction](#get-azsqlserverrecommendedaction) [Get-AzSqlServerServiceObjective](#get-azsqlserverserviceobjective) [Get-AzSqlServerTransparentDataEncryptionProtector](#get-azsqlservertransparentdataencryptionprotector) [Get-AzSqlServerUpgradeHint](#get-azsqlserverupgradehint) [Get-AzSqlServerVirtualNetworkRule](#get-azsqlservervirtualnetworkrule) [Get-AzSqlServerVulnerabilityAssessmentSetting](#get-azsqlservervulnerabilityassessmentsetting) [Get-AzSqlSyncAgent](#get-azsqlsyncagent) [Get-AzSqlSyncAgentLinkedDatabase](#get-azsqlsyncagentlinkeddatabase) [Get-AzSqlSyncGroup](#get-azsqlsyncgroup) [Get-AzSqlSyncGroupLog](#get-azsqlsyncgrouplog) [Get-AzSqlSyncMember](#get-azsqlsyncmember) [Get-AzSqlSyncSchema](#get-azsqlsyncschema) [Get-AzSqlVirtualCluster](#get-azsqlvirtualcluster) [New-AzSqlDatabase](#new-azsqldatabase) [New-AzSqlDatabaseCopy](#new-azsqldatabasecopy) [New-AzSqlDatabaseDataMaskingRule](#new-azsqldatabasedatamaskingrule) [New-AzSqlDatabaseExport](#new-azsqldatabaseexport) [New-AzSqlDatabaseFailoverGroup](#new-azsqldatabasefailovergroup) [New-AzSqlDatabaseImport](#new-azsqldatabaseimport) [New-AzSqlDatabaseInstanceFailoverGroup](#new-azsqldatabaseinstancefailovergroup) [New-AzSqlDatabaseRestorePoint](#new-azsqldatabaserestorepoint) [New-AzSqlDatabaseSecondary](#new-azsqldatabasesecondary) [New-AzSqlElasticPool](#new-azsqlelasticpool) [New-AzSqlInstance](#new-azsqlinstance) [New-AzSqlInstanceDatabase](#new-azsqlinstancedatabase) [New-AzSqlServer](#new-azsqlserver) [New-AzSqlServerCommunicationLink](#new-azsqlservercommunicationlink) [New-AzSqlServerDisasterRecoveryConfiguration](#new-azsqlserverdisasterrecoveryconfiguration) [New-AzSqlServerDnsAlias](#new-azsqlserverdnsalias) [New-AzSqlServerFirewallRule](#new-azsqlserverfirewallrule) [New-AzSqlServerVirtualNetworkRule](#new-azsqlservervirtualnetworkrule) [New-AzSqlSyncAgent](#new-azsqlsyncagent) [New-AzSqlSyncAgentKey](#new-azsqlsyncagentkey) [New-AzSqlSyncGroup](#new-azsqlsyncgroup) [New-AzSqlSyncMember](#new-azsqlsyncmember) [Remove-AzSqlDatabase](#remove-azsqldatabase) [Remove-AzSqlDatabaseAudit](#remove-azsqldatabaseaudit) [Remove-AzSqlDatabaseDataMaskingRule](#remove-azsqldatabasedatamaskingrule) [Remove-AzSqlDatabaseFailoverGroup](#remove-azsqldatabasefailovergroup) [Remove-AzSqlDatabaseFromFailoverGroup](#remove-azsqldatabasefromfailovergroup) [Remove-AzSqlDatabaseInstanceFailoverGroup](#remove-azsqldatabaseinstancefailovergroup) [Remove-AzSqlDatabaseLongTermRetentionBackup](#remove-azsqldatabaselongtermretentionbackup) [Remove-AzSqlDatabaseRestorePoint](#remove-azsqldatabaserestorepoint) [Remove-AzSqlDatabaseSecondary](#remove-azsqldatabasesecondary) [Remove-AzSqlDatabaseSensitivityClassification](#remove-azsqldatabasesensitivityclassification) [Remove-AzSqlElasticPool](#remove-azsqlelasticpool) [Remove-AzSqlInstance](#remove-azsqlinstance) [Remove-AzSqlInstanceDatabase](#remove-azsqlinstancedatabase) [Remove-AzSqlInstanceDatabaseSensitivityClassification](#remove-azsqlinstancedatabasesensitivityclassification) [Remove-AzSqlInstanceKeyVaultKey](#remove-azsqlinstancekeyvaultkey) [Remove-AzSqlServer](#remove-azsqlserver) [Remove-AzSqlServerActiveDirectoryAdministrator](#remove-azsqlserveractivedirectoryadministrator) [Remove-AzSqlServerAudit](#remove-azsqlserveraudit) [Remove-AzSqlServerCommunicationLink](#remove-azsqlservercommunicationlink) [Remove-AzSqlServerDisasterRecoveryConfiguration](#remove-azsqlserverdisasterrecoveryconfiguration) [Remove-AzSqlServerDnsAlias](#remove-azsqlserverdnsalias) [Remove-AzSqlServerFirewallRule](#remove-azsqlserverfirewallrule) [Remove-AzSqlServerKeyVaultKey](#remove-azsqlserverkeyvaultkey) [Remove-AzSqlServerVirtualNetworkRule](#remove-azsqlservervirtualnetworkrule) [Remove-AzSqlSyncAgent](#remove-azsqlsyncagent) [Remove-AzSqlSyncGroup](#remove-azsqlsyncgroup) [Remove-AzSqlSyncMember](#remove-azsqlsyncmember) [Remove-AzSqlVirtualCluster](#remove-azsqlvirtualcluster) [Restore-AzSqlDatabase](#restore-azsqldatabase) [Restore-AzSqlInstanceDatabase](#restore-azsqlinstancedatabase) [Resume-AzSqlDatabase](#resume-azsqldatabase) [Set-AzSqlDatabase](#set-azsqldatabase) [Set-AzSqlDatabaseAdvisorAutoExecuteStatus](#set-azsqldatabaseadvisorautoexecutestatus) [Set-AzSqlDatabaseAudit](#set-azsqldatabaseaudit) [Set-AzSqlDatabaseAuditing](#set-azsqldatabaseauditing) [Set-AzSqlDatabaseBackupLongTermRetentionPolicy](#set-azsqldatabasebackuplongtermretentionpolicy) [Set-AzSqlDatabaseBackupShortTermRetentionPolicy](#set-azsqldatabasebackupshorttermretentionpolicy) [Set-AzSqlDatabaseDataMaskingPolicy](#set-azsqldatabasedatamaskingpolicy) [Set-AzSqlDatabaseDataMaskingRule](#set-azsqldatabasedatamaskingrule) [Set-AzSqlDatabaseFailoverGroup](#set-azsqldatabasefailovergroup) [Set-AzSqlDatabaseGeoBackupPolicy](#set-azsqldatabasegeobackuppolicy) [Set-AzSqlDatabaseInstanceFailoverGroup](#set-azsqldatabaseinstancefailovergroup) [Set-AzSqlDatabaseRecommendedActionState](#set-azsqldatabaserecommendedactionstate) [Set-AzSqlDatabaseSecondary](#set-azsqldatabasesecondary) [Set-AzSqlDatabaseSensitivityClassification](#set-azsqldatabasesensitivityclassification) [Set-AzSqlDatabaseTransparentDataEncryption](#set-azsqldatabasetransparentdataencryption) [Set-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline](#set-azsqldatabasevulnerabilityassessmentrulebaseline) [Set-AzSqlElasticPool](#set-azsqlelasticpool) [Set-AzSqlElasticPoolAdvisorAutoExecuteStatus](#set-azsqlelasticpooladvisorautoexecutestatus) [Set-AzSqlElasticPoolRecommendedActionState](#set-azsqlelasticpoolrecommendedactionstate) [Set-AzSqlInstance](#set-azsqlinstance) [Set-AzSqlInstanceDatabaseBackupShortTermRetentionPolicy](#set-azsqlinstancedatabasebackupshorttermretentionpolicy) [Set-AzSqlInstanceDatabaseSensitivityClassification](#set-azsqlinstancedatabasesensitivityclassification) [Set-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline](#set-azsqlinstancedatabasevulnerabilityassessmentrulebaseline) [Set-AzSqlInstanceTransparentDataEncryptionProtector](#set-azsqlinstancetransparentdataencryptionprotector) [Set-AzSqlServer](#set-azsqlserver) [Set-AzSqlServerActiveDirectoryAdministrator](#set-azsqlserveractivedirectoryadministrator) [Set-AzSqlServerAdvisorAutoExecuteStatus](#set-azsqlserveradvisorautoexecutestatus) [Set-AzSqlServerAudit](#set-azsqlserveraudit) [Set-AzSqlServerAuditing](#set-azsqlserverauditing) [Set-AzSqlServerDisasterRecoveryConfiguration](#set-azsqlserverdisasterrecoveryconfiguration) [Set-AzSqlServerDnsAlias](#set-azsqlserverdnsalias) [Set-AzSqlServerFirewallRule](#set-azsqlserverfirewallrule) [Set-AzSqlServerRecommendedActionState](#set-azsqlserverrecommendedactionstate) [Set-AzSqlServerTransparentDataEncryptionProtector](#set-azsqlservertransparentdataencryptionprotector) [Set-AzSqlServerVirtualNetworkRule](#set-azsqlservervirtualnetworkrule) [Start-AzSqlDatabaseExecuteIndexRecommendation](#start-azsqldatabaseexecuteindexrecommendation) [Start-AzSqlDatabaseVulnerabilityAssessmentScan](#start-azsqldatabasevulnerabilityassessmentscan) [Start-AzSqlInstanceDatabaseVulnerabilityAssessmentScan](#start-azsqlinstancedatabasevulnerabilityassessmentscan) [Start-AzSqlSyncGroupSync](#start-azsqlsyncgroupsync) [Stop-AzSqlDatabaseActivity](#stop-azsqldatabaseactivity) [Stop-AzSqlDatabaseExecuteIndexRecommendation](#stop-azsqldatabaseexecuteindexrecommendation) [Stop-AzSqlElasticPoolActivity](#stop-azsqlelasticpoolactivity) [Stop-AzSqlSyncGroupSync](#stop-azsqlsyncgroupsync) [Suspend-AzSqlDatabase](#suspend-azsqldatabase) [Switch-AzSqlDatabaseFailoverGroup](#switch-azsqldatabasefailovergroup) [Switch-AzSqlDatabaseInstanceFailoverGroup](#switch-azsqldatabaseinstancefailovergroup) [Update-AzSqlDatabaseAdvancedThreatProtectionSettings](#update-azsqldatabaseadvancedthreatprotectionsettings) [Update-AzSqlDatabaseVulnerabilityAssessmentSetting](#update-azsqldatabasevulnerabilityassessmentsetting) [Update-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting](#update-azsqlinstancedatabasevulnerabilityassessmentsetting) [Update-AzSqlInstanceVulnerabilityAssessmentSetting](#update-azsqlinstancevulnerabilityassessmentsetting) [Update-AzSqlServerAdvancedThreatProtectionSettings](#update-azsqlserveradvancedthreatprotectionsettings) [Update-AzSqlServerVulnerabilityAssessmentSetting](#update-azsqlservervulnerabilityassessmentsetting) [Update-AzSqlSyncGroup](#update-azsqlsyncgroup) [Update-AzSqlSyncMember](#update-azsqlsyncmember) [Update-AzSqlSyncSchema](#update-azsqlsyncschema)
**Storage** [Add-AzRmStorageContainerLegalHold](#add-azrmstoragecontainerlegalhold) [Add-AzStorageAccountManagementPolicyAction](#add-azstorageaccountmanagementpolicyaction) [Add-AzStorageAccountNetworkRule](#add-azstorageaccountnetworkrule) [Close-AzStorageFileHandle](#close-azstoragefilehandle) [Disable-AzStorageBlobDeleteRetentionPolicy](#disable-azstorageblobdeleteretentionpolicy) [Disable-AzStorageDeleteRetentionPolicy](#disable-azstoragedeleteretentionpolicy) [Disable-AzStorageStaticWebsite](#disable-azstoragestaticwebsite) [Enable-AzStorageBlobDeleteRetentionPolicy](#enable-azstorageblobdeleteretentionpolicy) [Enable-AzStorageDeleteRetentionPolicy](#enable-azstoragedeleteretentionpolicy) [Enable-AzStorageStaticWebsite](#enable-azstoragestaticwebsite) [Get-AzRmStorageContainer](#get-azrmstoragecontainer) [Get-AzRmStorageContainerImmutabilityPolicy](#get-azrmstoragecontainerimmutabilitypolicy) [**Get-AzStorageAccount**](#get-azstorageaccount) [**Get-AzStorageAccountKey**](#get-azstorageaccountkey) [Get-AzStorageAccountManagementPolicy](#get-azstorageaccountmanagementpolicy) [Get-AzStorageAccountNameAvailability](#get-azstorageaccountnameavailability) [Get-AzStorageAccountNetworkRuleSet](#get-azstorageaccountnetworkruleset) [Get-AzStorageBlob](#get-azstorageblob) [Get-AzStorageBlobContent](#get-azstorageblobcontent) [**Get-AzStorageBlobCopyState**](#get-azstorageblobcopystate) [Get-AzStorageBlobServiceProperty](#get-azstorageblobserviceproperty) [Get-AzStorageContainer](#get-azstoragecontainer) [Get-AzStorageContainerStoredAccessPolicy](#get-azstoragecontainerstoredaccesspolicy) [Get-AzStorageCORSRule](#get-azstoragecorsrule) [Get-AzStorageFile](#get-azstoragefile) [Get-AzStorageFileContent](#get-azstoragefilecontent) [Get-AzStorageFileCopyState](#get-azstoragefilecopystate) [Get-AzStorageFileHandle](#get-azstoragefilehandle) [Get-AzStorageQueue](#get-azstoragequeue) [Get-AzStorageQueueStoredAccessPolicy](#get-azstoragequeuestoredaccesspolicy) [Get-AzStorageServiceLoggingProperty](#get-azstorageserviceloggingproperty) [Get-AzStorageServiceMetricsProperty](#get-azstorageservicemetricsproperty) [Get-AzStorageServiceProperty](#get-azstorageserviceproperty) [Get-AzStorageShare](#get-azstorageshare) [Get-AzStorageShareStoredAccessPolicy](#get-azstoragesharestoredaccesspolicy) [Get-AzStorageTable](#get-azstoragetable) [Get-AzStorageTableStoredAccessPolicy](#get-azstoragetablestoredaccesspolicy) [**Get-AzStorageUsage**](#get-azstorageusage) [Lock-AzRmStorageContainerImmutabilityPolicy](#lock-azrmstoragecontainerimmutabilitypolicy) [New-AzRmStorageContainer](#new-azrmstoragecontainer) [**New-AzStorageAccount**](#new-azstorageaccount) [New-AzStorageAccountKey](#new-azstorageaccountkey) [New-AzStorageAccountManagementPolicyFilter](#new-azstorageaccountmanagementpolicyfilter) [New-AzStorageAccountManagementPolicyRule](#new-azstorageaccountmanagementpolicyrule) [New-AzStorageAccountSASToken](#new-azstorageaccountsastoken) [**New-AzStorageBlobSASToken**](#new-azstorageblobsastoken) [**New-AzStorageContainer**](#new-azstoragecontainer) [New-AzStorageContainerSASToken](#new-azstoragecontainersastoken) [New-AzStorageContainerStoredAccessPolicy](#new-azstoragecontainerstoredaccesspolicy) [**New-AzStorageContext**](#new-azstoragecontext) [New-AzStorageDirectory](#new-azstoragedirectory) [New-AzStorageFileSASToken](#new-azstoragefilesastoken) [New-AzStorageQueue](#new-azstoragequeue) [New-AzStorageQueueSASToken](#new-azstoragequeuesastoken) [New-AzStorageQueueStoredAccessPolicy](#new-azstoragequeuestoredaccesspolicy) [**New-AzStorageShare**](#new-azstorageshare) [New-AzStorageShareSASToken](#new-azstoragesharesastoken) [New-AzStorageShareStoredAccessPolicy](#new-azstoragesharestoredaccesspolicy) [New-AzStorageTable](#new-azstoragetable) [New-AzStorageTableSASToken](#new-azstoragetablesastoken) [New-AzStorageTableStoredAccessPolicy](#new-azstoragetablestoredaccesspolicy) [Remove-AzRmStorageContainer](#remove-azrmstoragecontainer) [Remove-AzRmStorageContainerImmutabilityPolicy](#remove-azrmstoragecontainerimmutabilitypolicy) [Remove-AzRmStorageContainerLegalHold](#remove-azrmstoragecontainerlegalhold) [Remove-AzStorageAccount](#remove-azstorageaccount) [Remove-AzStorageAccountManagementPolicy](#remove-azstorageaccountmanagementpolicy) [Remove-AzStorageAccountNetworkRule](#remove-azstorageaccountnetworkrule) [Remove-AzStorageBlob](#remove-azstorageblob) [Remove-AzStorageContainer](#remove-azstoragecontainer) [Remove-AzStorageContainerStoredAccessPolicy](#remove-azstoragecontainerstoredaccesspolicy) [Remove-AzStorageCORSRule](#remove-azstoragecorsrule) [Remove-AzStorageDirectory](#remove-azstoragedirectory) [Remove-AzStorageFile](#remove-azstoragefile) [Remove-AzStorageQueue](#remove-azstoragequeue) [Remove-AzStorageQueueStoredAccessPolicy](#remove-azstoragequeuestoredaccesspolicy) [Remove-AzStorageShare](#remove-azstorageshare) [Remove-AzStorageShareStoredAccessPolicy](#remove-azstoragesharestoredaccesspolicy) [Remove-AzStorageTable](#remove-azstoragetable) [Remove-AzStorageTableStoredAccessPolicy](#remove-azstoragetablestoredaccesspolicy) [**Set-AzCurrentStorageAccount**](#set-azcurrentstorageaccount) [Set-AzRmStorageContainerImmutabilityPolicy](#set-azrmstoragecontainerimmutabilitypolicy) [**Set-AzStorageAccount**](#set-azstorageaccount) [Set-AzStorageAccountManagementPolicy](#set-azstorageaccountmanagementpolicy) [**Set-AzStorageBlobContent**](#set-azstorageblobcontent) [Set-AzStorageContainerAcl](#set-azstoragecontaineracl) [Set-AzStorageContainerStoredAccessPolicy](#set-azstoragecontainerstoredaccesspolicy) [Set-AzStorageCORSRule](#set-azstoragecorsrule) [Set-AzStorageFileContent](#set-azstoragefilecontent) [Set-AzStorageQueueStoredAccessPolicy](#set-azstoragequeuestoredaccesspolicy) [Set-AzStorageServiceLoggingProperty](#set-azstorageserviceloggingproperty) [Set-AzStorageServiceMetricsProperty](#set-azstorageservicemetricsproperty) [Set-AzStorageShareQuota](#set-azstoragesharequota) [Set-AzStorageShareStoredAccessPolicy](#set-azstoragesharestoredaccesspolicy) [Set-AzStorageTableStoredAccessPolicy](#set-azstoragetablestoredaccesspolicy) [**Start-AzStorageBlobCopy**](#start-azstorageblobcopy) [Start-AzStorageBlobIncrementalCopy](#start-azstorageblobincrementalcopy) [Start-AzStorageFileCopy](#start-azstoragefilecopy) [Stop-AzStorageBlobCopy](#stop-azstorageblobcopy) [Stop-AzStorageFileCopy](#stop-azstoragefilecopy) [Update-AzRmStorageContainer](#update-azrmstoragecontainer) [Update-AzStorageAccountNetworkRuleSet](#update-azstorageaccountnetworkruleset) [Update-AzStorageBlobServiceProperty](#update-azstorageblobserviceproperty) [Update-AzStorageServiceProperty](#update-azstorageserviceproperty)
**Storagesync** [Get-AzStorageSyncCloudEndpoint](#get-azstoragesynccloudendpoint) [Get-AzStorageSyncGroup](#get-azstoragesyncgroup) [Get-AzStorageSyncServer](#get-azstoragesyncserver) [Get-AzStorageSyncServerEndpoint](#get-azstoragesyncserverendpoint) [Get-AzStorageSyncService](#get-azstoragesyncservice) [Invoke-AzStorageSyncChangeDetection](#invoke-azstoragesyncchangedetection) [Invoke-AzStorageSyncCompatibilityCheck](#invoke-azstoragesynccompatibilitycheck) [Invoke-AzStorageSyncFileRecall](#invoke-azstoragesyncfilerecall) [New-AzStorageSyncCloudEndpoint](#new-azstoragesynccloudendpoint) [New-AzStorageSyncGroup](#new-azstoragesyncgroup) [New-AzStorageSyncServerEndpoint](#new-azstoragesyncserverendpoint) [New-AzStorageSyncService](#new-azstoragesyncservice) [Register-AzStorageSyncServer](#register-azstoragesyncserver) [Remove-AzStorageSyncCloudEndpoint](#remove-azstoragesynccloudendpoint) [Remove-AzStorageSyncGroup](#remove-azstoragesyncgroup) [Remove-AzStorageSyncServerEndpoint](#remove-azstoragesyncserverendpoint) [Remove-AzStorageSyncService](#remove-azstoragesyncservice) [Reset-AzStorageSyncServerCertificate](#reset-azstoragesyncservercertificate) [Set-AzStorageSyncServerEndpoint](#set-azstoragesyncserverendpoint) [Unregister-AzStorageSyncServer](#unregister-azstoragesyncserver)
**Streamanalytics** [Get-AzStreamAnalyticsDefaultFunctionDefinition](#get-azstreamanalyticsdefaultfunctiondefinition) [Get-AzStreamAnalyticsFunction](#get-azstreamanalyticsfunction) [Get-AzStreamAnalyticsInput](#get-azstreamanalyticsinput) [Get-AzStreamAnalyticsJob](#get-azstreamanalyticsjob) [Get-AzStreamAnalyticsOutput](#get-azstreamanalyticsoutput) [Get-AzStreamAnalyticsQuota](#get-azstreamanalyticsquota) [Get-AzStreamAnalyticsTransformation](#get-azstreamanalyticstransformation) [New-AzStreamAnalyticsFunction](#new-azstreamanalyticsfunction) [New-AzStreamAnalyticsInput](#new-azstreamanalyticsinput) [New-AzStreamAnalyticsJob](#new-azstreamanalyticsjob) [New-AzStreamAnalyticsOutput](#new-azstreamanalyticsoutput) [New-AzStreamAnalyticsTransformation](#new-azstreamanalyticstransformation) [Remove-AzStreamAnalyticsFunction](#remove-azstreamanalyticsfunction) [Remove-AzStreamAnalyticsInput](#remove-azstreamanalyticsinput) [Remove-AzStreamAnalyticsJob](#remove-azstreamanalyticsjob) [Remove-AzStreamAnalyticsOutput](#remove-azstreamanalyticsoutput) [Start-AzStreamAnalyticsJob](#start-azstreamanalyticsjob) [Stop-AzStreamAnalyticsJob](#stop-azstreamanalyticsjob) [Test-AzStreamAnalyticsFunction](#test-azstreamanalyticsfunction) [Test-AzStreamAnalyticsInput](#test-azstreamanalyticsinput) [Test-AzStreamAnalyticsOutput](#test-azstreamanalyticsoutput)
**Subscription** [New-AzSubscription](#new-azsubscription)
**Trafficmanager** [Add-AzTrafficManagerCustomHeaderToEndpoint](#add-aztrafficmanagercustomheadertoendpoint) [Add-AzTrafficManagerCustomHeaderToProfile](#add-aztrafficmanagercustomheadertoprofile) [Add-AzTrafficManagerEndpointConfig](#add-aztrafficmanagerendpointconfig) [Add-AzTrafficManagerExpectedStatusCodeRange](#add-aztrafficmanagerexpectedstatuscoderange) [Add-AzTrafficManagerIpAddressRange](#add-aztrafficmanageripaddressrange) [Disable-AzTrafficManagerEndpoint](#disable-aztrafficmanagerendpoint) [Disable-AzTrafficManagerProfile](#disable-aztrafficmanagerprofile) [Enable-AzTrafficManagerEndpoint](#enable-aztrafficmanagerendpoint) [Enable-AzTrafficManagerProfile](#enable-aztrafficmanagerprofile) [Get-AzTrafficManagerEndpoint](#get-aztrafficmanagerendpoint) [Get-AzTrafficManagerProfile](#get-aztrafficmanagerprofile) [New-AzTrafficManagerEndpoint](#new-aztrafficmanagerendpoint) [New-AzTrafficManagerProfile](#new-aztrafficmanagerprofile) [Remove-AzTrafficManagerCustomHeaderFromEndpoint](#remove-aztrafficmanagercustomheaderfromendpoint) [Remove-AzTrafficManagerCustomHeaderFromProfile](#remove-aztrafficmanagercustomheaderfromprofile) [Remove-AzTrafficManagerEndpoint](#remove-aztrafficmanagerendpoint) [Remove-AzTrafficManagerEndpointConfig](#remove-aztrafficmanagerendpointconfig) [Remove-AzTrafficManagerExpectedStatusCodeRange](#remove-aztrafficmanagerexpectedstatuscoderange) [Remove-AzTrafficManagerIpAddressRange](#remove-aztrafficmanageripaddressrange) [Remove-AzTrafficManagerProfile](#remove-aztrafficmanagerprofile) [Set-AzTrafficManagerEndpoint](#set-aztrafficmanagerendpoint) [Set-AzTrafficManagerProfile](#set-aztrafficmanagerprofile)
**Websites** [Edit-AzWebAppBackupConfiguration](#edit-azwebappbackupconfiguration) [Enter-AzWebAppContainerPSSession](#enter-azwebappcontainerpssession) [Get-AzAppServicePlan](#get-azappserviceplan) [Get-AzAppServicePlanMetric](#get-azappserviceplanmetric) [Get-AzDeletedWebApp](#get-azdeletedwebapp) [Get-AzWebApp](#get-azwebapp) [Get-AzWebAppBackup](#get-azwebappbackup) [Get-AzWebAppBackupConfiguration](#get-azwebappbackupconfiguration) [Get-AzWebAppBackupList](#get-azwebappbackuplist) [Get-AzWebAppCertificate](#get-azwebappcertificate) [Get-AzWebAppContainerContinuousDeploymentUrl](#get-azwebappcontainercontinuousdeploymenturl) [Get-AzWebAppMetric](#get-azwebappmetric) [Get-AzWebAppPublishingProfile](#get-azwebapppublishingprofile) [Get-AzWebAppSlot](#get-azwebappslot) [Get-AzWebAppSlotConfigName](#get-azwebappslotconfigname) [Get-AzWebAppSlotMetric](#get-azwebappslotmetric) [Get-AzWebAppSlotPublishingProfile](#get-azwebappslotpublishingprofile) [Get-AzWebAppSnapshot](#get-azwebappsnapshot) [Get-AzWebAppSSLBinding](#get-azwebappsslbinding) [New-AzAppServicePlan](#new-azappserviceplan) [New-AzWebApp](#new-azwebapp) [New-AzWebAppAzureStoragePath](#new-azwebappazurestoragepath) [New-AzWebAppBackup](#new-azwebappbackup) [New-AzWebAppContainerPSSession](#new-azwebappcontainerpssession) [New-AzWebAppDatabaseBackupSetting](#new-azwebappdatabasebackupsetting) [New-AzWebAppSlot](#new-azwebappslot) [New-AzWebAppSSLBinding](#new-azwebappsslbinding) [Publish-AzWebApp](#publish-azwebapp) [Remove-AzAppServicePlan](#remove-azappserviceplan) [Remove-AzWebApp](#remove-azwebapp) [Remove-AzWebAppBackup](#remove-azwebappbackup) [Remove-AzWebAppSlot](#remove-azwebappslot) [Remove-AzWebAppSSLBinding](#remove-azwebappsslbinding) [Reset-AzWebAppPublishingProfile](#reset-azwebapppublishingprofile) [Reset-AzWebAppSlotPublishingProfile](#reset-azwebappslotpublishingprofile) [Restart-AzWebApp](#restart-azwebapp) [Restart-AzWebAppSlot](#restart-azwebappslot) [Restore-AzDeletedWebApp](#restore-azdeletedwebapp) [Restore-AzWebAppBackup](#restore-azwebappbackup) [Restore-AzWebAppSnapshot](#restore-azwebappsnapshot) [Set-AzAppServicePlan](#set-azappserviceplan) [Set-AzWebApp](#set-azwebapp) [Set-AzWebAppSlot](#set-azwebappslot) [Set-AzWebAppSlotConfigName](#set-azwebappslotconfigname) [Start-AzWebApp](#start-azwebapp) [Start-AzWebAppSlot](#start-azwebappslot) [Stop-AzWebApp](#stop-azwebapp) [Stop-AzWebAppSlot](#stop-azwebappslot) [Switch-AzWebAppSlot](#switch-azwebappslot)

#### Add-AzADGroupMember
Adds a user to an existing AD group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Add-AzADGroupMember) )
#### Add-AzAnalysisServicesAccount
Adds an authenticated account to use for Azure Analysis Services server cmdlet requests.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Add-AzAnalysisServicesAccount) )
#### Add-AzApiManagementApiToProduct
Adds an API to a product.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Add-AzApiManagementApiToProduct) )
#### Add-AzApiManagementProductToGroup
Adds a product to a group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Add-AzApiManagementProductToGroup) )
#### Add-AzApiManagementRegion
Adds new deployment regions to a PsApiManagement instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Add-AzApiManagementRegion) )
#### Add-AzApiManagementUserToGroup
Adds a user to a group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Add-AzApiManagementUserToGroup) )
#### Add-AzApplicationGatewayAuthenticationCertificate
Adds an authentication certificate to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayAuthenticationCertificate) )
#### Add-AzApplicationGatewayBackendAddressPool
Adds a back-end address pool to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayBackendAddressPool) )
#### Add-AzApplicationGatewayBackendHttpSetting
Adds back-end HTTP settings to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayBackendHttpSetting) )
#### Add-AzApplicationGatewayCustomError
Adds a custom error to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayCustomError) )
#### Add-AzApplicationGatewayFrontendIPConfig
Adds a front-end IP configuration to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayFrontendIPConfig) )
#### Add-AzApplicationGatewayFrontendPort
Adds a front-end port to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayFrontendPort) )
#### Add-AzApplicationGatewayHttpListener
Adds an HTTP listener to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayHttpListener) )
#### Add-AzApplicationGatewayHttpListenerCustomError
Adds a custom error to a http listener of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayHttpListenerCustomError) )
#### Add-AzApplicationGatewayIPConfiguration
Adds an IP configuration to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayIPConfiguration) )
#### Add-AzApplicationGatewayProbeConfig
Adds a health probe to an Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayProbeConfig) )
#### Add-AzApplicationGatewayRedirectConfiguration
Adds a redirect configuration to an Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayRedirectConfiguration) )
#### Add-AzApplicationGatewayRequestRoutingRule
Adds a request routing rule to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayRequestRoutingRule) )
#### Add-AzApplicationGatewayRewriteRuleSet
Adds a rewrite rule set to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayRewriteRuleSet) )
#### Add-AzApplicationGatewaySslCertificate
Adds an SSL certificate to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewaySslCertificate) )
#### Add-AzApplicationGatewayTrustedRootCertificate
Adds a trusted root certificate to an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayTrustedRootCertificate) )
#### Add-AzApplicationGatewayUrlPathMapConfig
Adds an array of URL path mappings to a backend server pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzApplicationGatewayUrlPathMapConfig) )
#### Add-AzCognitiveServicesAccountNetworkRule
Add IpRules or VirtualNetworkRules to the NetworkRule property of a Cognitive Services account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Add-AzCognitiveServicesAccountNetworkRule) )
#### Add-AzContainerServiceAgentPoolProfile
Adds a container service agent pool profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzContainerServiceAgentPoolProfile) )
#### Add-AzDataLakeAnalyticsDataSource
Adds a data source to a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Add-AzDataLakeAnalyticsDataSource) )
#### Add-AzDataLakeAnalyticsFirewallRule
Adds a firewall rule to a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Add-AzDataLakeAnalyticsFirewallRule) )
#### Add-AzDataLakeStoreFirewallRule
Adds a firewall rule to the specified Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Add-AzDataLakeStoreFirewallRule) )
#### Add-AzDataLakeStoreItemContent
Adds content to an item in a Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Add-AzDataLakeStoreItemContent) )
#### Add-AzDataLakeStoreTrustedIdProvider
Adds a trusted identity provider to the specified Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Add-AzDataLakeStoreTrustedIdProvider) )
#### Add-AzDataLakeStoreVirtualNetworkRule
Adds a virtual network rule to the specified Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Add-AzDataLakeStoreVirtualNetworkRule) )
#### Add-AzDelegation
Adds a delegation to a subnet.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzDelegation) )
#### Add-AzEnvironment
Adds endpoints and metadata for an instance of Azure Resource Manager.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Add-AzEnvironment) )
#### Add-AzEventHubIPRule
Add a single IPrule to the NetworkRuleSet of the given Namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Add-AzEventHubIPRule) )
#### Add-AzEventHubVirtualNetworkRule
Add a single VirtualNetworkRule to NetworkRuleSet for the given Namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Add-AzEventHubVirtualNetworkRule) )
#### Add-AzExpressRouteCircuitAuthorization
Adds an ExpressRoute circuit authorization.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzExpressRouteCircuitAuthorization) )
#### Add-AzExpressRouteCircuitConnectionConfig
Adds a circuit connection configuration to Private Peering of an Express Route Circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzExpressRouteCircuitConnectionConfig) )
#### Add-AzExpressRouteCircuitPeeringConfig
Adds a peering configuration to an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzExpressRouteCircuitPeeringConfig) )
#### Add-AzExpressRouteCrossConnectionPeering
Adds a peering configuration to an ExpressRoute cross connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzExpressRouteCrossConnectionPeering) )
#### Add-AzHDInsightClusterIdentity
Adds a cluster identity to a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightClusterIdentity) )
#### Add-AzHDInsightComponentVersion
Adds a version for a service running in a cluster to a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightComponentVersion) )
#### Add-AzHDInsightConfigValue
Adds a Hadoop configuration value customization and/or a Hive shared library customization to a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightConfigValue) )
#### Add-AzHDInsightMetastore
Adds a SQL Database to serve as a Hive or Oozie metastore to a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightMetastore) )
#### Add-AzHDInsightScriptAction
Adds a script action to a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightScriptAction) )
#### Add-AzHDInsightSecurityProfile
Adds a security profileto a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightSecurityProfile) )
#### Add-AzHDInsightStorage
Adds an Azure Storage key to a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Add-AzHDInsightStorage) )
#### Add-AzImageDataDisk
Adds a data disk to an image obejct.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzImageDataDisk) )
#### Add-AzIoTDeviceProvisioningServiceAccessPolicy
Add a new shared access policy in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Add-AzIoTDeviceProvisioningServiceAccessPolicy) )
#### Add-AzIoTDeviceProvisioningServiceCertificate
Create/update an Azure IoT Hub Device Provisioning Service certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Add-AzIoTDeviceProvisioningServiceCertificate) )
#### Add-AzIoTDeviceProvisioningServiceLinkedHub
Linked IoT hub to an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Add-AzIoTDeviceProvisioningServiceLinkedHub) )
#### Add-AzIotHubCertificate
Create/update an Azure IoT Hub certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Add-AzIotHubCertificate) )
#### Add-AzIotHubEventHubConsumerGroup
Creates an eventhub consumer group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Add-AzIotHubEventHubConsumerGroup) )
#### Add-AzIotHubKey
Creates an IotHub Key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Add-AzIotHubKey) )
#### Add-AzIotHubRoute
Create a route in IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Add-AzIotHubRoute) )
#### Add-AzIotHubRoutingEndpoint
Add an endpoint to your IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Add-AzIotHubRoutingEndpoint) )
#### Add-AzKeyVaultCertificate
Adds a certificate to a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Add-AzKeyVaultCertificate) )
#### Add-AzKeyVaultCertificateContact
Adds a contact for certificate notifications.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Add-AzKeyVaultCertificateContact) )
#### Add-AzKeyVaultKey
Creates a key in a key vault or imports a key into a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Add-AzKeyVaultKey) [2.1c.02](#21c02) [2.1c.03](#21c03))
#### Add-AzKeyVaultManagedStorageAccount
Adds an existing Azure Storage Account to the specified key vault for its keys to be managed by the Key Vault service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Add-AzKeyVaultManagedStorageAccount) )
#### Add-AzKeyVaultNetworkRule
Adds a rule meant to restrict access to a key vault based on the client's internet address.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Add-AzKeyVaultNetworkRule) )
#### Add-AzLoadBalancerBackendAddressPoolConfig
Adds a backend address pool configuration to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerBackendAddressPoolConfig) )
#### Add-AzLoadBalancerFrontendIpConfig
Adds a front-end IP configuration to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerFrontendIpConfig) )
#### Add-AzLoadBalancerInboundNatPoolConfig
Adds an inbound NAT pool to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerInboundNatPoolConfig) )
#### Add-AzLoadBalancerInboundNatRuleConfig
Adds an inbound NAT rule configuration to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerInboundNatRuleConfig) )
#### Add-AzLoadBalancerOutboundRuleConfig
Adds an outbound rule configuration to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerOutboundRuleConfig) )
#### Add-AzLoadBalancerProbeConfig
Adds a probe configuration to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerProbeConfig) [3.1h.02](#31h02))
#### Add-AzLoadBalancerRuleConfig
Adds a rule configuration to a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzLoadBalancerRuleConfig) [3.1h.02](#31h02))
#### Add-AzMlWebServiceRegionalProperty
Creates regional web service properties.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Add-AzMlWebServiceRegionalProperty) )
#### Add-AzNetworkInterfaceIpConfig
Adds a network interface IP configuration to a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzNetworkInterfaceIpConfig) )
#### Add-AzNetworkInterfaceTapConfig
Creates a TapConfiguration resource associated to a NetworkInterface. This will reference to an existing VirtualNetworkTap resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzNetworkInterfaceTapConfig) )
#### Add-AzNetworkSecurityRuleConfig
Adds a network security rule configuration to a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzNetworkSecurityRuleConfig) )
#### Add-AzPrivateDnsRecordConfig
Adds a Private DNS record to a local record set object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Add-AzPrivateDnsRecordConfig) )
#### Add-AzRmStorageContainerLegalHold
Adds legal hold tags to a Storage blob container(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Add-AzRmStorageContainerLegalHold) )
#### Add-AzRouteConfig
Adds a route to a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzRouteConfig) [4.1d.02](#41d02))
#### Add-AzRouteFilterRuleConfig
Adds a route filter rule to a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzRouteFilterRuleConfig) )
#### Add-AzServiceEndpointPolicyDefinition
Adds a service endpoint policy definition to a specified policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzServiceEndpointPolicyDefinition) )
#### Add-AzServiceFabricApplicationCertificate
Add a new certificate to the Virtual Machine Scale Set(s) that make up the cluster. The certificate is intended to be used as an application certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Add-AzServiceFabricApplicationCertificate) )
#### Add-AzServiceFabricClientCertificate
Add common name or thumbprint to the cluster for client authentication purposes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Add-AzServiceFabricClientCertificate) )
#### Add-AzServiceFabricClusterCertificate
Add a secondary cluster certificate to the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Add-AzServiceFabricClusterCertificate) )
#### Add-AzServiceFabricNode
Add nodes to the specific node type in the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Add-AzServiceFabricNode) )
#### Add-AzServiceFabricNodeType
Add a new node type to the existing cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Add-AzServiceFabricNodeType) )
#### Add-AzSqlDatabaseToFailoverGroup
Adds one or more databases to an Azure SQL Database Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Add-AzSqlDatabaseToFailoverGroup) )
#### Add-AzSqlInstanceKeyVaultKey
Adds a key vault key to the provided Managed Instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Add-AzSqlInstanceKeyVaultKey) )
#### Add-AzSqlManagedInstanceTransparentDataEncryptionCertificate
Adds a Transparent Data Encryption Certificate for the given managed instance(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Add-AzSqlManagedInstanceTransparentDataEncryptionCertificate) )
#### Add-AzSqlServerKeyVaultKey
Adds a Key Vault key to a SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Add-AzSqlServerKeyVaultKey) )
#### Add-AzSqlServerTransparentDataEncryptionCertificate
Adds a Transparent Data Encryption Certificate for the given SQL Server instance(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Add-AzSqlServerTransparentDataEncryptionCertificate) )
#### Add-AzStorageAccountManagementPolicyAction
Adds an action to the input ManagementPolicy Action Group object, or creates a ManagementPolicy Action Group object with the action. The object can be used in New-AzStorageAccountManagementPolicyRule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Add-AzStorageAccountManagementPolicyAction) )
#### Add-AzStorageAccountNetworkRule
Add IpRules or VirtualNetworkRules to the NetworkRule property of a Storage account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Add-AzStorageAccountNetworkRule) )
#### Add-AzTrafficManagerCustomHeaderToEndpoint
Adds custom header information to a local Traffic Manager endpoint object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Add-AzTrafficManagerCustomHeaderToEndpoint) )
#### Add-AzTrafficManagerCustomHeaderToProfile
Adds custom header information to a local Traffic Manager profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Add-AzTrafficManagerCustomHeaderToProfile) )
#### Add-AzTrafficManagerEndpointConfig
Adds an endpoint to a local Traffic Manager profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Add-AzTrafficManagerEndpointConfig) )
#### Add-AzTrafficManagerExpectedStatusCodeRange
Adds an expected status code range to a local Traffic Manager profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Add-AzTrafficManagerExpectedStatusCodeRange) )
#### Add-AzTrafficManagerIpAddressRange
Adds an address range or subnet to a local Traffic Manager endpoint object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Add-AzTrafficManagerIpAddressRange) )
#### Add-AzVhd
Uploads a virtual hard disk from an on-premises virtual machine to a blob in a cloud storage account in Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVhd) )
#### Add-AzVirtualNetworkGatewayIpConfig
Adds an IP configuration to a virtual network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzVirtualNetworkGatewayIpConfig) )
#### Add-AzVirtualNetworkPeering
Creates a peering between two virtual networks.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzVirtualNetworkPeering) [4.2a.02](#42a02))
#### Add-AzVirtualNetworkSubnetConfig
Adds a subnet configuration to a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzVirtualNetworkSubnetConfig) )
#### Add-AzVMAdditionalUnattendContent
Adds information to the unattended Windows Setup answer file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVMAdditionalUnattendContent) )
#### Add-AzVMDataDisk
Adds a data disk to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVMDataDisk) [3.3a.02](#33a02))
#### Add-AzVMNetworkInterface
Adds a network interface to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVMNetworkInterface) [3.1a.02](#31a02) [3.3b.02](#33b02))
#### Add-AzVMSecret
Adds a secret to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVMSecret) )
#### Add-AzVmssAdditionalUnattendContent
Adds information to the unattended Windows Setup answer file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssAdditionalUnattendContent) )
#### Add-AzVmssDataDisk
Adds a data disk to the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssDataDisk) )
#### Add-AzVmssDiagnosticsExtension
Adds a diagnostics extension to the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssDiagnosticsExtension) )
#### Add-AzVmssExtension
Adds an extension to the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssExtension) [3.1h.02](#31h02))
#### Add-AzVMSshPublicKey
Adds the public keys for SSH for a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVMSshPublicKey) )
#### Add-AzVmssNetworkInterfaceConfiguration
Adds a network interface configuration to the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssNetworkInterfaceConfiguration) [3.1h.02](#31h02))
#### Add-AzVmssSecret
Adds a secret to a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssSecret) )
#### Add-AzVmssSshPublicKey
Adds SSH public keys to the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssSshPublicKey) )
#### Add-AzVmssVMDataDisk
Adds a data disk to a Vmss VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssVMDataDisk) )
#### Add-AzVmssWinRMListener
Adds a WinRM listener to the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Add-AzVmssWinRMListener) )
#### Add-AzVpnClientRevokedCertificate
Adds a VPN client-revocation certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzVpnClientRevokedCertificate) )
#### Add-AzVpnClientRootCertificate
Adds a VPN client root certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Add-AzVpnClientRootCertificate) )
#### Approve-AzPrivateEndpointConnection
Approves a private endpoint connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Approve-AzPrivateEndpointConnection) )
#### Backup-AzApiManagement
Backs up an API Management service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Backup-AzApiManagement) )
#### Backup-AzKeyVaultCertificate
Backs up a certificate in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Backup-AzKeyVaultCertificate) )
#### Backup-AzKeyVaultKey
Backs up a key in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Backup-AzKeyVaultKey) )
#### Backup-AzKeyVaultManagedStorageAccount
Backs up a KeyVault-managed storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Backup-AzKeyVaultManagedStorageAccount) )
#### Backup-AzKeyVaultSecret
Backs up a secret in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Backup-AzKeyVaultSecret) )
#### Backup-AzRecoveryServicesBackupItem
Starts a backup for a Backup item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Backup-AzRecoveryServicesBackupItem) )
#### Clear-AzContext
Remove all Azure credentials, account, and subscription information.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Clear-AzContext) )
#### Clear-AzDefault
Clears the defaults set by the user in the current context.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Clear-AzDefault) )
#### Clear-AzSqlDatabaseAdvancedThreatProtectionSettings
Removes the advanced threat protection settings from a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlDatabaseAdvancedThreatProtectionSettings) )
#### Clear-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline
Clears the vulnerability assessment rule baseline.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline) )
#### Clear-AzSqlDatabaseVulnerabilityAssessmentSetting
Clears the vulnerability assessment settings of a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlDatabaseVulnerabilityAssessmentSetting) )
#### Clear-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline
Clears the vulnerability assessment rule baseline.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline) )
#### Clear-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting
Clears the vulnerability assessment settings of a managed database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting) )
#### Clear-AzSqlInstanceVulnerabilityAssessmentSetting
Clears the vulnerability assessment settings of a managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlInstanceVulnerabilityAssessmentSetting) )
#### Clear-AzSqlServerAdvancedThreatProtectionSettings
Removes the advanced threat protection settings from a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlServerAdvancedThreatProtectionSettings) )
#### Clear-AzSqlServerVulnerabilityAssessmentSetting
Clears the vulnerability assessment settings of a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Clear-AzSqlServerVulnerabilityAssessmentSetting) )
#### Close-AzStorageFileHandle
Closes file handles of a file share, a file directory or a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Close-AzStorageFileHandle) )
#### Complete-AzServiceBusMigration
Cmdlets set the Migration from Standard to premium namespace as complete and connection strings of standard namespace now point to Premium namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Complete-AzServiceBusMigration) )
#### Confirm-AzCdnEndpointProbeURL
Validates a probe URL.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Confirm-AzCdnEndpointProbeURL) )
#### Connect-AzAccount
Connect to Azure with an authenticated account for use with Azure Resource Manager cmdlet requests.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Connect-AzAccount) [3.1a.02](#31a02))
#### Convert-AzSqlDatabaseVulnerabilityAssessmentScan
Converts a vulnerability assessment scan results to Excel format.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Convert-AzSqlDatabaseVulnerabilityAssessmentScan) )
#### Convert-AzSqlInstanceDatabaseVulnerabilityAssessmentScan
Converts a vulnerability assessment scan results to Excel format.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Convert-AzSqlInstanceDatabaseVulnerabilityAssessmentScan) )
#### ConvertTo-AzVMManagedDisk
Converts a virtual machine with blob-based disks to a virtual machine with managed disks.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/ConvertTo-AzVMManagedDisk) )
#### Deny-AzPrivateEndpointConnection
Denies a private endpoint connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Deny-AzPrivateEndpointConnection) )
#### Disable-AzAdvisorRecommendation
Disable an Azure Advisor recommendation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.advisor/Disable-AzAdvisorRecommendation) )
#### Disable-AzBatchAutoScale
Disables automatic scaling of a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Disable-AzBatchAutoScale) )
#### Disable-AzBatchComputeNodeScheduling
Disables task scheduling on the specified compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Disable-AzBatchComputeNodeScheduling) )
#### Disable-AzBatchJob
Disables a Batch job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Disable-AzBatchJob) )
#### Disable-AzBatchJobSchedule
Disables a Batch job schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Disable-AzBatchJobSchedule) )
#### Disable-AzCdnCustomDomain
Disables Custom Domain HTTPS (Deprecated).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Disable-AzCdnCustomDomain) )
#### Disable-AzCdnCustomDomainHttps
Disables Custom Domain HTTPS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Disable-AzCdnCustomDomainHttps) )
#### Disable-AzContextAutosave
Turn off autosaving Azure credentials. Your login information will be forgotten the next time you open a PowerShell window(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Disable-AzContextAutosave) )
#### Disable-AzDataCollection
Opts out of collecting data to improve the AzurePowerShell cmdlets.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Disable-AzDataCollection) )
#### Disable-AzFrontDoorCustomDomainHttps
Disable HTTPS for a custom domain(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Disable-AzFrontDoorCustomDomainHttps) )
#### Disable-AzHDInsightOperationsManagementSuite
Disables Operations Management Suite (OMS) in a HDInsight cluster and relevant logs will stop flowing to the OMS workspace specified during enable.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Disable-AzHDInsightOperationsManagementSuite) )
#### Disable-AzOperationalInsightsIISLogCollection
Stops collection of IIS logs from computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Disable-AzOperationalInsightsIISLogCollection) )
#### Disable-AzOperationalInsightsLinuxCustomLogCollection
Stops collection of custom logs from Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Disable-AzOperationalInsightsLinuxCustomLogCollection) )
#### Disable-AzOperationalInsightsLinuxPerformanceCollection
Stops collection of performance counters from Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Disable-AzOperationalInsightsLinuxPerformanceCollection) )
#### Disable-AzOperationalInsightsLinuxSyslogCollection
Stops collection of syslog data from Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Disable-AzOperationalInsightsLinuxSyslogCollection) )
#### Disable-AzRecoveryServicesBackupAutoProtection
Disables auto backup for a protectable item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Disable-AzRecoveryServicesBackupAutoProtection) )
#### Disable-AzRecoveryServicesBackupProtection
Disables protection for a Backup-protected item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Disable-AzRecoveryServicesBackupProtection) )
#### Disable-AzRecoveryServicesBackupRPMountScript
Dismounts all the files of the recovery point.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Disable-AzRecoveryServicesBackupRPMountScript) )
#### Disable-AzSecurityAdvancedThreatProtection
Disables the advanced threat protection policy for a storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Disable-AzSecurityAdvancedThreatProtection) )
#### Disable-AzSqlInstanceAdvancedDataSecurity
Disables Advanced Data Security on a managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Disable-AzSqlInstanceAdvancedDataSecurity) )
#### Disable-AzSqlServerAdvancedDataSecurity
Disables Advanced Data Security on a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Disable-AzSqlServerAdvancedDataSecurity) )
#### Disable-AzSqlServerAdvancedThreatProtection
Disables Advanced Threat Protection on a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Disable-AzSqlServerAdvancedThreatProtection) )
#### Disable-AzStorageBlobDeleteRetentionPolicy
Disable delete retention policy for the Azure Storage Blob service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Disable-AzStorageBlobDeleteRetentionPolicy) )
#### Disable-AzStorageDeleteRetentionPolicy
Disable delete retention policy for the Azure Storage Blob service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Disable-AzStorageDeleteRetentionPolicy) )
#### Disable-AzStorageStaticWebsite
Disable static website for the Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Disable-AzStorageStaticWebsite) )
#### Disable-AzTrafficManagerEndpoint
Disables an endpoint in a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Disable-AzTrafficManagerEndpoint) )
#### Disable-AzTrafficManagerProfile
Disables a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Disable-AzTrafficManagerProfile) )
#### Disable-AzureRmAlias
Disables AzureRm prefix aliases for Az modules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Disable-AzureRmAlias) )
#### Disable-AzVMDiskEncryption
Disables encryption on an IaaS virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Disable-AzVMDiskEncryption) )
#### Disable-AzVmssDiskEncryption
Disables disk encryption on a VM scale set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Disable-AzVmssDiskEncryption) )
#### Disconnect-AzAccount
Disconnects a connected Azure account and removes all credentials and contexts associated with that account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Disconnect-AzAccount) )
#### Edit-AzRecoveryServicesAsrRecoveryPlan
Edits a Site Recovery plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Edit-AzRecoveryServicesAsrRecoveryPlan) )
#### Edit-AzWebAppBackupConfiguration
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Edit-AzWebAppBackupConfiguration) )
#### Enable-AzAdvisorRecommendation
Enables Azure Advisor recommendation(s).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.advisor/Enable-AzAdvisorRecommendation) )
#### Enable-AzBatchAutoScale
Enables automatic scaling of a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Enable-AzBatchAutoScale) )
#### Enable-AzBatchComputeNodeScheduling
Enables task scheduling on the specified compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Enable-AzBatchComputeNodeScheduling) )
#### Enable-AzBatchJob
Enables a Batch job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Enable-AzBatchJob) )
#### Enable-AzBatchJobSchedule
Enables a Batch job schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Enable-AzBatchJobSchedule) )
#### Enable-AzBatchTask
Reactivates a task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Enable-AzBatchTask) )
#### Enable-AzCdnCustomDomain
Enables Custom Domain HTTPS (Deprecated).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Enable-AzCdnCustomDomain) )
#### Enable-AzCdnCustomDomainHttps
Enables custom HTTPS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Enable-AzCdnCustomDomainHttps) )
#### Enable-AzContextAutosave
Allow the azure credential, account and subscription information to be saved and automatically loaded when you open a PowerShell window.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Enable-AzContextAutosave) )
#### Enable-AzDataCollection
Enables Azure PowerShell to collect data to improve the user experience with AzurePowerShell cmdlets.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Enable-AzDataCollection) )
#### Enable-AzDataLakeStoreKeyVault
Attempts to enable a user managed Key Vault for encryption of the specified Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Enable-AzDataLakeStoreKeyVault) )
#### Enable-AzFrontDoorCustomDomainHttps
Enable HTTPS for a custom domain using Front Door managed certificate or using own certificate from Azure Key Vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Enable-AzFrontDoorCustomDomainHttps) )
#### Enable-AzHDInsightOperationsManagementSuite
Enables Operations Management Suite (OMS) in a HDInsight cluster and relevant logs will be sent to the OMS workspace specified during enable.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Enable-AzHDInsightOperationsManagementSuite) )
#### Enable-AzOperationalInsightsIISLogCollection
Starts collection of IIS logs from computers in a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Enable-AzOperationalInsightsIISLogCollection) )
#### Enable-AzOperationalInsightsLinuxCustomLogCollection
Starts collection of custom logs from Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Enable-AzOperationalInsightsLinuxCustomLogCollection) )
#### Enable-AzOperationalInsightsLinuxPerformanceCollection
Starts collection of performance counters from Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Enable-AzOperationalInsightsLinuxPerformanceCollection) )
#### Enable-AzOperationalInsightsLinuxSyslogCollection
Starts collection of syslog data from Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Enable-AzOperationalInsightsLinuxSyslogCollection) )
#### Enable-AzRecoveryServicesBackupAutoProtection
Enables auto backup for a protectable item with a specified Backup protection policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Enable-AzRecoveryServicesBackupAutoProtection) )
#### Enable-AzRecoveryServicesBackupProtection
Enables backup for an item with a specified Backup protection policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Enable-AzRecoveryServicesBackupProtection) )
#### Enable-AzSecurityAdvancedThreatProtection
Enables the advanced threat protection policy for a storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Enable-AzSecurityAdvancedThreatProtection) )
#### Enable-AzSqlInstanceAdvancedDataSecurity
Enables Advanced Data Security on a managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Enable-AzSqlInstanceAdvancedDataSecurity) )
#### Enable-AzSqlServerAdvancedDataSecurity
Enables Advanced Data Security on a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Enable-AzSqlServerAdvancedDataSecurity) )
#### Enable-AzSqlServerAdvancedThreatProtection
Enables Advanced Threat Protection on a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Enable-AzSqlServerAdvancedThreatProtection) )
#### Enable-AzStorageBlobDeleteRetentionPolicy
Enable delete retention policy for the Azure Storage Blob service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Enable-AzStorageBlobDeleteRetentionPolicy) )
#### Enable-AzStorageDeleteRetentionPolicy
Enable delete retention policy for the Azure Storage Blob service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Enable-AzStorageDeleteRetentionPolicy) )
#### Enable-AzStorageStaticWebsite
Enable static website for the Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Enable-AzStorageStaticWebsite) )
#### Enable-AzTrafficManagerEndpoint
Enables an endpoint in a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Enable-AzTrafficManagerEndpoint) )
#### Enable-AzTrafficManagerProfile
Enables a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Enable-AzTrafficManagerProfile) )
#### Enable-AzureRmAlias
Enables AzureRm prefix aliases for Az modules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Enable-AzureRmAlias) )
#### Enter-AzWebAppContainerPSSession
Opens a remote PowerShell session into the windows container specified in a given site or slot and given resource group(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Enter-AzWebAppContainerPSSession) )
#### Export-AzAnalysisServicesInstanceLog
Exports a log from an instance of Analysis Services server in the currently logged in Environment as specified in Add-AzAnalysisServicesAccount command(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Export-AzAnalysisServicesInstanceLog) )
#### Export-AzApiManagementApi
Exports an API to a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Export-AzApiManagementApi) )
#### Export-AzAutomationDscConfiguration
Exports a DSC configuration from Automation to a local file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Export-AzAutomationDscConfiguration) )
#### Export-AzAutomationDscNodeReportContent
Exports the raw content of a DSC report sent from a DSC node to Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Export-AzAutomationDscNodeReportContent) )
#### Export-AzAutomationRunbook
Exports an Automation runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Export-AzAutomationRunbook) )
#### Export-AzBlueprintWithArtifact
Export specified blueprint definition to the specified output location as a JSON file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Export-AzBlueprintWithArtifact) )
#### Export-AzDataLakeStoreChildItemProperty
Exports the properties (Disk usage and Acl) for the entire tree from the specified path to a ouput path(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Export-AzDataLakeStoreChildItemProperty) )
#### Export-AzDataLakeStoreItem
Downloads a file from Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Export-AzDataLakeStoreItem) )
#### Export-AzLogAnalyticRequestRateByInterval
Export logs that show Api requests made by this subscription in the given time window to show throttling activities.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Export-AzLogAnalyticRequestRateByInterval) )
#### Export-AzLogAnalyticThrottledRequest
Export logs that show total throttled Api requests for this subscription in the given time window.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Export-AzLogAnalyticThrottledRequest) )
#### Export-AzMlWebService
Exports the web service definition object as a JSON formatted string.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Export-AzMlWebService) )
#### Export-AzRedisCache
Exports data from Azure Redis Cache to a container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Export-AzRedisCache) )
#### Export-AzResourceGroup
Captures a resource group as a template and saves it to a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Export-AzResourceGroup) [3.2e.04](#32e04))
#### Get-AzActionRule
Get Action Rules Information(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Get-AzActionRule) )
#### Get-AzADAppCredential
Retrieves a list of credentials associated with an application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADAppCredential) )
#### Get-AzADApplication
Lists existing azure active directory applications.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADApplication) )
#### Get-AzADGroup
Filters active directory groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADGroup) [1.4c.08](#14c08) [1.4c.11](#14c11))
#### Get-AzADGroupMember
Lists members of an AD group in the current tenant.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADGroupMember) )
#### Get-AzADServicePrincipal
Filters active directory service principals.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADServicePrincipal) )
#### Get-AzADSpCredential
Retrieves a list of credentials associated with a service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADSpCredential) )
#### Get-AzADUser
Filters active directory users.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzADUser) )
#### Get-AzAdvisorConfiguration
Get the Azure Advisor configurations for the given subscription or resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.advisor/Get-AzAdvisorConfiguration) )
#### Get-AzAdvisorRecommendation
Gets a list of Azure Advisor recommendations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.advisor/Get-AzAdvisorRecommendation) )
#### Get-AzAks
List Kubernetes managed clusters.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/Get-AzAks) )
#### Get-AzAlert
Get Alerts Information(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Get-AzAlert) )
#### Get-AzAlertObjectHistory
Gets Alert History information(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Get-AzAlertObjectHistory) )
#### Get-AzAnalysisServicesServer
Gets the details of an Analysis Services server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Get-AzAnalysisServicesServer) )
#### Get-AzApiManagement
Gets a list or a particular API Management Service description.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagement) )
#### Get-AzApiManagementApi
Gets an API.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementApi) )
#### Get-AzApiManagementApiRelease
Get the API Release.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementApiRelease) )
#### Get-AzApiManagementApiRevision
Gets details of all the API Revisions of an API(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementApiRevision) )
#### Get-AzApiManagementApiSchema
Get the details of the API Schema(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementApiSchema) )
#### Get-AzApiManagementApiVersionSet
Get the details of the API Version Sets(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementApiVersionSet) )
#### Get-AzApiManagementAuthorizationServer
Gets an API Management authorization server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementAuthorizationServer) )
#### Get-AzApiManagementBackend
Get the details of the Backend.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementBackend) )
#### Get-AzApiManagementCache
Get the details of the Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementCache) )
#### Get-AzApiManagementCertificate
Gets API Management certificates configured for Mutual Authentication with Backend in the service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementCertificate) )
#### Get-AzApiManagementDiagnostic
Get details of the Diagnostic configured at the service level or the Api Level. Diagnostics are used to log requests/responses from Api Management gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementDiagnostic) )
#### Get-AzApiManagementGroup
Gets all or specific API management groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementGroup) )
#### Get-AzApiManagementIdentityProvider
Get the identity provider configuration details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementIdentityProvider) )
#### Get-AzApiManagementLogger
Gets API Management Logger objects.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementLogger) )
#### Get-AzApiManagementNetworkStatus
Gets the Connectivity Status to the external resources on which the Api Management service depends from inside the Cloud Service. This also returns the DNS Servers as visible to the CloudService.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementNetworkStatus) )
#### Get-AzApiManagementOpenIdConnectProvider
Gets OpenID Connect providers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementOpenIdConnectProvider) )
#### Get-AzApiManagementOperation
Gets a list or a specified API Operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementOperation) )
#### Get-AzApiManagementPolicy
Gets the specified scope policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementPolicy) )
#### Get-AzApiManagementProduct
Gets a list or a particular product.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementProduct) )
#### Get-AzApiManagementProperty
Gets a list or a particular Property (Named-Value).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementProperty) )
#### Get-AzApiManagementSsoToken
Gets a link with an SSO token to a deployed management portal of an API Management service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementSsoToken) )
#### Get-AzApiManagementSubscription
Gets subscriptions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementSubscription) )
#### Get-AzApiManagementTenantAccess
Gets the access configuration for a tenant.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementTenantAccess) )
#### Get-AzApiManagementTenantGitAccess
Gets the Git access configuration for a tenant.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementTenantGitAccess) )
#### Get-AzApiManagementTenantSyncState
Gets the status of the most recent synchronization between the configuration database and the Git repository.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementTenantSyncState) )
#### Get-AzApiManagementUser
Gets a user or users.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementUser) )
#### Get-AzApiManagementUserSsoUrl
Generates an SSO URL for a user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Get-AzApiManagementUserSsoUrl) )
#### Get-AzApplicationGateway
Gets an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGateway) )
#### Get-AzApplicationGatewayAuthenticationCertificate
Gets an authentication certificate for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayAuthenticationCertificate) )
#### Get-AzApplicationGatewayAutoscaleConfiguration
Gets the Autoscale Configuration of the Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayAutoscaleConfiguration) )
#### Get-AzApplicationGatewayAvailableServerVariableAndHeader
Get the supported server variables and available request and response headers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayAvailableServerVariableAndHeader) )
#### Get-AzApplicationGatewayAvailableSslOption
Gets all available ssl options for ssl policy for Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayAvailableSslOption) )
#### Get-AzApplicationGatewayAvailableWafRuleSet
Gets all available web application firewall rule sets.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayAvailableWafRuleSet) )
#### Get-AzApplicationGatewayBackendAddressPool
Gets a back-end address pool for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayBackendAddressPool) )
#### Get-AzApplicationGatewayBackendHealth
Gets application gateway backend health.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayBackendHealth) )
#### Get-AzApplicationGatewayBackendHttpSetting
Gets the back-end HTTP settings of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayBackendHttpSetting) )
#### Get-AzApplicationGatewayConnectionDraining
Gets the connection draining configuration of a back-end HTTP settings object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayConnectionDraining) )
#### Get-AzApplicationGatewayCustomError
Gets custom error(s) from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayCustomError) )
#### Get-AzApplicationGatewayFirewallPolicy
Gets an application gateway firewall policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayFirewallPolicy) )
#### Get-AzApplicationGatewayFrontendIPConfig
Gets the front-end IP configuration of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayFrontendIPConfig) )
#### Get-AzApplicationGatewayFrontendPort
Gets the front-end port of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayFrontendPort) )
#### Get-AzApplicationGatewayHttpListener
Gets the HTTP listener of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayHttpListener) )
#### Get-AzApplicationGatewayHttpListenerCustomError
Gets custom error(s) from a http listener of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayHttpListenerCustomError) )
#### Get-AzApplicationGatewayIdentity
Get identity assigned to the application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayIdentity) )
#### Get-AzApplicationGatewayIPConfiguration
Gets the IP configuration of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayIPConfiguration) )
#### Get-AzApplicationGatewayProbeConfig
Gets an existing health probe configuration from an Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayProbeConfig) )
#### Get-AzApplicationGatewayRedirectConfiguration
Gets an existing redirect configuration from an Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayRedirectConfiguration) )
#### Get-AzApplicationGatewayRequestRoutingRule
Gets the request routing rule of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayRequestRoutingRule) )
#### Get-AzApplicationGatewayRewriteRuleSet
Gets the rewrite rule set of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayRewriteRuleSet) )
#### Get-AzApplicationGatewaySku
Gets the SKU of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewaySku) )
#### Get-AzApplicationGatewaySslCertificate
Gets an SSL certificate for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewaySslCertificate) )
#### Get-AzApplicationGatewaySslPolicy
Gets the SSL policy of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewaySslPolicy) )
#### Get-AzApplicationGatewaySslPredefinedPolicy
Gets Predefined SSL Policies provided by Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewaySslPredefinedPolicy) )
#### Get-AzApplicationGatewayTrustedRootCertificate
Gets the Trusted Root Certificate with a specific name from the Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayTrustedRootCertificate) )
#### Get-AzApplicationGatewayUrlPathMapConfig
Gets an array of URL path mappings to a backend server pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayUrlPathMapConfig) )
#### Get-AzApplicationGatewayWebApplicationFirewallConfiguration
Gets the WAF configuration of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationGatewayWebApplicationFirewallConfiguration) )
#### Get-AzApplicationInsights
Get application insights resources(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Get-AzApplicationInsights) )
#### Get-AzApplicationInsightsApiKey
Get application insights api keys for an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Get-AzApplicationInsightsApiKey) )
#### Get-AzApplicationInsightsContinuousExport
Get application insights continuous export configuration for an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Get-AzApplicationInsightsContinuousExport) )
#### Get-AzApplicationSecurityGroup
Gets an application security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzApplicationSecurityGroup) )
#### Get-AzAppServicePlan
Gets an Azure App Service plan in the specified resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzAppServicePlan) )
#### Get-AzAppServicePlanMetric
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzAppServicePlanMetric) )
#### Get-AzAttestation
Gets an attestation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.attestation/Get-AzAttestation) )
#### Get-AzAutoApprovedPrivateLinkService
Gets an array of private link service id that can be linked to a private end point with auto approved.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzAutoApprovedPrivateLinkService) )
#### Get-AzAutomationAccount
Gets Automation accounts in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationAccount) )
#### Get-AzAutomationCertificate
Gets Automation certificates.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationCertificate) )
#### Get-AzAutomationConnection
Gets an Automation connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationConnection) )
#### Get-AzAutomationCredential
Gets Automation credentials.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationCredential) )
#### Get-AzAutomationDscCompilationJob
Gets DSC compilation jobs in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscCompilationJob) )
#### Get-AzAutomationDscCompilationJobOutput
Gets the logging streams of an Automation DSC compilation job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscCompilationJobOutput) )
#### Get-AzAutomationDscConfiguration
Gets DSC configurations from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscConfiguration) )
#### Get-AzAutomationDscNode
Gets DSC nodes from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscNode) )
#### Get-AzAutomationDscNodeConfiguration
Gets metadata for DSC node configurations in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscNodeConfiguration) )
#### Get-AzAutomationDscNodeConfigurationDeployment
Gets DSC Node configuration deployments in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscNodeConfigurationDeployment) )
#### Get-AzAutomationDscNodeConfigurationDeploymentSchedule
Gets a DSC Node configuration deployment job schedule in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscNodeConfigurationDeploymentSchedule) )
#### Get-AzAutomationDscNodeReport
Gets reports sent from a DSC node to Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscNodeReport) )
#### Get-AzAutomationDscOnboardingMetaconfig
Creates meta-configuration .mof files.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationDscOnboardingMetaconfig) )
#### Get-AzAutomationHybridWorkerGroup
Gets hybrid runbook worker groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationHybridWorkerGroup) )
#### Get-AzAutomationJob
Gets Automation runbook jobs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationJob) )
#### Get-AzAutomationJobOutput
Gets the output of an Automation job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationJobOutput) )
#### Get-AzAutomationJobOutputRecord
Gets the full output of an Automation job output record.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationJobOutputRecord) )
#### Get-AzAutomationModule
Gets metadata for modules from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationModule) )
#### Get-AzAutomationRegistrationInfo
Gets registration information for onboarding a DSC node or hybrid worker to Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationRegistrationInfo) )
#### Get-AzAutomationRunbook
Gets a runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationRunbook) )
#### Get-AzAutomationSchedule
Gets an Automation schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSchedule) )
#### Get-AzAutomationScheduledRunbook
Gets Automation runbooks and associated schedules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationScheduledRunbook) )
#### Get-AzAutomationSoftwareUpdateConfiguration
Gets a list of azure automation software update configurations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSoftwareUpdateConfiguration) )
#### Get-AzAutomationSoftwareUpdateMachineRun
Gets a list of azure automation software update configuration machine runs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSoftwareUpdateMachineRun) )
#### Get-AzAutomationSoftwareUpdateRun
Gets a list of azure automation software update runs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSoftwareUpdateRun) )
#### Get-AzAutomationSourceControl
Gets a list of Azure Automation source controls.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSourceControl) )
#### Get-AzAutomationSourceControlSyncJob
Gets Azure Automation source control sync jobs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSourceControlSyncJob) )
#### Get-AzAutomationSourceControlSyncJobOutput
Gets the output of an Azure Automation source control sync job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationSourceControlSyncJobOutput) )
#### Get-AzAutomationVariable
Gets an Automation variable.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationVariable) )
#### Get-AzAutomationWebhook
Gets webhooks from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Get-AzAutomationWebhook) )
#### Get-AzAvailabilitySet
Gets Azure availability sets in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzAvailabilitySet) )
#### Get-AzAvailablePrivateEndpointType
Return available private end point types in the location(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzAvailablePrivateEndpointType) )
#### Get-AzAvailableServiceDelegation
Get available service delegations in the region.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzAvailableServiceDelegation) )
#### Get-AzBatchAccount
Gets a Batch account in the current subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchAccount) )
#### Get-AzBatchAccountKey
Gets the keys of a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchAccountKey) )
#### Get-AzBatchApplication
Gets information about the specified application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchApplication) )
#### Get-AzBatchApplicationPackage
Gets information about an application package in a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchApplicationPackage) )
#### Get-AzBatchCertificate
Gets the certificates in a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchCertificate) )
#### Get-AzBatchComputeNode
Gets Batch compute nodes from a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchComputeNode) )
#### Get-AzBatchJob
Gets Batch jobs for a Batch account or job schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchJob) )
#### Get-AzBatchJobPreparationAndReleaseTaskStatus
Gets Batch job preparation and release task status.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchJobPreparationAndReleaseTaskStatus) )
#### Get-AzBatchJobSchedule
Gets Batch job schedules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchJobSchedule) )
#### Get-AzBatchJobStatistic
Gets job summary statistics for a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchJobStatistic) )
#### Get-AzBatchLocationQuota
Gets the Batch service quotas for your subscription at the given location.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchLocationQuota) )
#### Get-AzBatchNodeAgentSku
Gets Batch node agent SKUs available in a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchNodeAgentSku) )
#### Get-AzBatchNodeFile
Gets the properties of Batch node files.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchNodeFile) )
#### Get-AzBatchNodeFileContent
Gets a Batch node file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchNodeFileContent) )
#### Get-AzBatchPool
Gets Batch pools under the specified Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchPool) )
#### Get-AzBatchPoolNodeCount
Gets Batch node counts per node state grouped by pool id.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchPoolNodeCount) )
#### Get-AzBatchPoolStatistic
Gets pool summary statistics for a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchPoolStatistic) )
#### Get-AzBatchPoolUsageMetric
Gets pool usage metrics for a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchPoolUsageMetric) )
#### Get-AzBatchRemoteDesktopProtocolFile
Gets an RDP file from a compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchRemoteDesktopProtocolFile) )
#### Get-AzBatchRemoteLoginSetting
Gets remote logon settings for a compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchRemoteLoginSetting) )
#### Get-AzBatchSubtask
Gets the subtask information of the specified task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchSubtask) )
#### Get-AzBatchTask
Gets the Batch tasks for a job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchTask) )
#### Get-AzBatchTaskCount
Gets the task counts for the specified job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Get-AzBatchTaskCount) )
#### Get-AzBgpServiceCommunity
Provides a list of all services / regions, BGP communities, and associated prefixes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzBgpServiceCommunity) )
#### Get-AzBillingInvoice
Get billing invoices of the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzBillingInvoice) )
#### Get-AzBillingPeriod
Get billing periods of the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzBillingPeriod) )
#### Get-AzBlueprint
Get one or more blueprint definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Get-AzBlueprint) )
#### Get-AzBlueprintArtifact
Get artifact from a blueprint definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Get-AzBlueprintArtifact) )
#### Get-AzBlueprintAssignment
Get one or more blueprint assignments.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Get-AzBlueprintAssignment) )
#### Get-AzCdnCustomDomain
Gets a CDN custom domain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnCustomDomain) )
#### Get-AzCdnEdgeNode
Gets Azure CDN edgenodes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnEdgeNode) )
#### Get-AzCdnEndpoint
Gets a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnEndpoint) )
#### Get-AzCdnEndpointNameAvailability
Gets availability status of the CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnEndpointNameAvailability) )
#### Get-AzCdnEndpointResourceUsage
Gets the resource usage of a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnEndpointResourceUsage) )
#### Get-AzCdnOrigin
Gets a CDN origin server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnOrigin) )
#### Get-AzCdnProfile
Gets a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnProfile) )
#### Get-AzCdnProfileResourceUsage
Gets the resource usage of a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnProfileResourceUsage) )
#### Get-AzCdnProfileSsoUrl
Gets the single sign-on URL of a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnProfileSsoUrl) )
#### Get-AzCdnProfileSupportedOptimizationType
Gets the supported optimization types for a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnProfileSupportedOptimizationType) )
#### Get-AzCdnSubscriptionResourceUsage
Gets the resource usage for a susbscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Get-AzCdnSubscriptionResourceUsage) )
#### Get-AzCognitiveServicesAccount
Gets an account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Get-AzCognitiveServicesAccount) )
#### Get-AzCognitiveServicesAccountKey
Gets the API keys for an account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Get-AzCognitiveServicesAccountKey) )
#### Get-AzCognitiveServicesAccountNetworkRuleSet
Get the NetworkRule property of a Cognitive Services account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Get-AzCognitiveServicesAccountNetworkRuleSet) )
#### Get-AzCognitiveServicesAccountSku
Gets the available SKUs for an account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Get-AzCognitiveServicesAccountSku) )
#### Get-AzCognitiveServicesAccountType
Gets the available Cognitive Services Account Types.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Get-AzCognitiveServicesAccountType) )
#### Get-AzCognitiveServicesAccountUsage
Get current usages for a Cognitive Services account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Get-AzCognitiveServicesAccountUsage) )
#### Get-AzComputeResourceSku
List all compute resource Skus(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzComputeResourceSku) )
#### Get-AzConsumptionBudget
Get a list of budgets in either a subscription or a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzConsumptionBudget) )
#### Get-AzConsumptionMarketplace
Get marketplaces of the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzConsumptionMarketplace) )
#### Get-AzConsumptionPriceSheet
Get price sheets of the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzConsumptionPriceSheet) )
#### Get-AzConsumptionReservationDetail
Get reservations details for provided date range.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzConsumptionReservationDetail) )
#### Get-AzConsumptionReservationSummary
Get reservation summaries for daily or monthly grain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzConsumptionReservationSummary) )
#### Get-AzConsumptionUsageDetail
Get usage details of the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzConsumptionUsageDetail) )
#### Get-AzContainerGroup
Gets container groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerinstance/Get-AzContainerGroup) )
#### Get-AzContainerInstanceLog
Get the logs of a container instance in a container group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerinstance/Get-AzContainerInstanceLog) )
#### Get-AzContainerRegistry
Gets a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Get-AzContainerRegistry) )
#### Get-AzContainerRegistryCredential
Gets the login credentials for a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Get-AzContainerRegistryCredential) )
#### Get-AzContainerRegistryReplication
Gets a replication of a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Get-AzContainerRegistryReplication) )
#### Get-AzContainerRegistryWebhook
Gets a container registry webhook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Get-AzContainerRegistryWebhook) )
#### Get-AzContainerRegistryWebhookEvent
Gets events of a container registry webhook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Get-AzContainerRegistryWebhookEvent) )
#### Get-AzContainerService
Gets a container service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzContainerService) )
#### Get-AzContext
Gets the metadata used to authenticate Azure Resource Manager requests.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzContext) )
#### Get-AzContextAutosaveSetting
Display metadata about the context autosave feature, including whether the context is(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzContextAutosaveSetting) )
#### Get-AzDataBoxCredential
Gets the databox credentials of a specific job(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.databox/Get-AzDataBoxCredential) )
#### Get-AzDataBoxJob
Gets information about Databox Jobs(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.databox/Get-AzDataBoxJob) )
#### Get-AzDataFactory
Gets information about Data Factories.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactory) )
#### Get-AzDataFactoryActivityWindow
Gets information about activity windows associated with a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryActivityWindow) )
#### Get-AzDataFactoryDataset
Gets information about datasets in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryDataset) )
#### Get-AzDataFactoryGateway
Gets information about logical gateways in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryGateway) )
#### Get-AzDataFactoryGatewayAuthKey
Gets gateway auth key for an Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryGatewayAuthKey) )
#### Get-AzDataFactoryHub
Gets information about hubs in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryHub) )
#### Get-AzDataFactoryLinkedService
Gets information about linked services in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryLinkedService) )
#### Get-AzDataFactoryPipeline
Gets information about pipelines in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryPipeline) )
#### Get-AzDataFactoryRun
Gets runs for a data slice of a dataset in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryRun) )
#### Get-AzDataFactorySlice
Gets data slices for a dataset in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactorySlice) )
#### Get-AzDataFactoryV2
Gets information about Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2) )
#### Get-AzDataFactoryV2ActivityRun
Gets information about activity runs for a pipeline run.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2ActivityRun) )
#### Get-AzDataFactoryV2Dataset
Gets information about datasets in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2Dataset) )
#### Get-AzDataFactoryV2IntegrationRuntime
Gets information about integration runtime resources.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2IntegrationRuntime) )
#### Get-AzDataFactoryV2IntegrationRuntimeKey
Gets keys for a self-hosted integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2IntegrationRuntimeKey) )
#### Get-AzDataFactoryV2IntegrationRuntimeMetric
Gets metric data for an integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2IntegrationRuntimeMetric) )
#### Get-AzDataFactoryV2IntegrationRuntimeNode
Gets an integration runtime node infomation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2IntegrationRuntimeNode) )
#### Get-AzDataFactoryV2LinkedService
Gets information about linked services in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2LinkedService) )
#### Get-AzDataFactoryV2Pipeline
Gets information about pipelines in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2Pipeline) )
#### Get-AzDataFactoryV2PipelineRun
Gets information about pipeline runs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2PipelineRun) )
#### Get-AzDataFactoryV2Trigger
Gets information about triggers in a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2Trigger) )
#### Get-AzDataFactoryV2TriggerRun
Returns information about trigger runs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Get-AzDataFactoryV2TriggerRun) )
#### Get-AzDataLakeAnalyticsAccount
Gets information about a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsAccount) )
#### Get-AzDataLakeAnalyticsCatalogItem
Gets a Data Lake Analytics catalog item or types of items.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsCatalogItem) )
#### Get-AzDataLakeAnalyticsCatalogItemAclEntry
Gets an entry in the ACL of a catalog or catalog item in Data Lake Analytics.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsCatalogItemAclEntry) )
#### Get-AzDataLakeAnalyticsComputePolicy
Gets a Data Lake Analytics compute policy or list of compute policies.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsComputePolicy) )
#### Get-AzDataLakeAnalyticsDataSource
Gets a Data Lake Analytics data source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsDataSource) )
#### Get-AzDataLakeAnalyticsFirewallRule
Retrieves a firewall rule or list of firewall rules from a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsFirewallRule) )
#### Get-AzDataLakeAnalyticsJob
Gets a Data Lake Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsJob) )
#### Get-AzDataLakeAnalyticsJobPipeline
Gets a Data Lake Analytics Job pipeline or pipelines.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsJobPipeline) )
#### Get-AzDataLakeAnalyticsJobRecurrence
Gets a Data Lake Analytics Job recurrence or recurrences.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Get-AzDataLakeAnalyticsJobRecurrence) )
#### Get-AzDataLakeStoreAccount
Gets details of a Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreAccount) )
#### Get-AzDataLakeStoreChildItem
Gets the list of items in a folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreChildItem) )
#### Get-AzDataLakeStoreChildItemSummary
Gets the summary of total size, files and directories contained in the path specified(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreChildItemSummary) )
#### Get-AzDataLakeStoreFirewallRule
Gets the specified firewall rules in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreFirewallRule) )
#### Get-AzDataLakeStoreItem
Gets the details of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreItem) )
#### Get-AzDataLakeStoreItemAclEntry
Gets an entry in the ACL of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreItemAclEntry) )
#### Get-AzDataLakeStoreItemContent
Gets the contents of a file in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreItemContent) )
#### Get-AzDataLakeStoreItemOwner
Gets the owner of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreItemOwner) )
#### Get-AzDataLakeStoreItemPermission
Gets the permission octal of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreItemPermission) )
#### Get-AzDataLakeStoreTrustedIdProvider
Gets the specified trusted identity provider in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreTrustedIdProvider) )
#### Get-AzDataLakeStoreVirtualNetworkRule
Gets the specified virtual network rules in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Get-AzDataLakeStoreVirtualNetworkRule) )
#### Get-AzDataMigrationProject
Retrieves the properties of an Azure Database Migration project.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Get-AzDataMigrationProject) )
#### Get-AzDataMigrationService
Retrieves the properties associated with an instance of the Azure Database Migration Service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Get-AzDataMigrationService) )
#### Get-AzDataMigrationTask
Retrieves the PSProjectTask object associated with an Azure Database Migration Service migration task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Get-AzDataMigrationTask) )
#### Get-AzDdosProtectionPlan
Gets a DDoS protection plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzDdosProtectionPlan) )
#### Get-AzDefault
Get the defaults set by the user in the current context.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzDefault) )
#### Get-AzDelegation
Get a delegation (or all of the delegations) on a given subnet.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzDelegation) )
#### Get-AzDeletedWebApp
Gets deleted web apps in the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzDeletedWebApp) )
#### Get-AzDenyAssignment
Lists Azure RBAC deny assignments at the specified scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzDenyAssignment) )
#### Get-AzDeployment
Get deployment(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzDeployment) )
#### Get-AzDeploymentManagerArtifactSource
Gets the Artifact source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Get-AzDeploymentManagerArtifactSource) )
#### Get-AzDeploymentManagerRollout
Gets the rollout.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Get-AzDeploymentManagerRollout) )
#### Get-AzDeploymentManagerService
Gets the service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Get-AzDeploymentManagerService) )
#### Get-AzDeploymentManagerServiceTopology
Gets the service topology.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Get-AzDeploymentManagerServiceTopology) )
#### Get-AzDeploymentManagerServiceUnit
Gets the service unit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Get-AzDeploymentManagerServiceUnit) )
#### Get-AzDeploymentManagerStep
Gets the step.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Get-AzDeploymentManagerStep) )
#### Get-AzDeploymentOperation
Get deployment operation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzDeploymentOperation) )
#### Get-AzDevSpacesController
Get or list Azure DevSpaces controller.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devspaces/Get-AzDevSpacesController) )
#### Get-AzDiscoveredSecuritySolution
Gets security solutions that were discovered by Azure Security Center(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzDiscoveredSecuritySolution) )
#### Get-AzDisk
Gets the properties of a Managed disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzDisk) )
#### Get-AzDtlAllowedVMSizesPolicy
Gets the allowed virtual machine sizes policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Get-AzDtlAllowedVMSizesPolicy) )
#### Get-AzDtlAutoShutdownPolicy
Gets the auto shutdown policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Get-AzDtlAutoShutdownPolicy) )
#### Get-AzDtlAutoStartPolicy
Gets the auto start policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Get-AzDtlAutoStartPolicy) )
#### Get-AzDtlVMsPerLabPolicy
Gets the virtual machines per lab policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Get-AzDtlVMsPerLabPolicy) )
#### Get-AzDtlVMsPerUserPolicy
Gets the virtual machines per user policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Get-AzDtlVMsPerUserPolicy) )
#### Get-AzEffectiveNetworkSecurityGroup
Gets the effective network security group of a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzEffectiveNetworkSecurityGroup) [4.4d.02](#44d02))
#### Get-AzEffectiveRouteTable
Gets the effective route table of a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzEffectiveRouteTable) [4.1d.02](#41d02))
#### Get-AzEnrollmentAccount
Get enrollment accounts.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-AzEnrollmentAccount) )
#### Get-AzEnvironment
Get endpoints and metadata for an instance of Azure services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzEnvironment) )
#### Get-AzEventGridDomain
Gets the details of an Event Grid domain, or gets a list of all Event Grid domains in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridDomain) )
#### Get-AzEventGridDomainKey
Gets the shared access keys used to publish events to an Event Grid domain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridDomainKey) )
#### Get-AzEventGridDomainTopic
Gets the details of an Event Grid domain topic, or gets a list of all Event Grid domain topics under specific Event Grid domain in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridDomainTopic) )
#### Get-AzEventGridSubscription
Gets the details of an event subscription, or gets a list of all event subscriptions in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridSubscription) )
#### Get-AzEventGridTopic
Gets the details of an Event Grid topic, or gets a list of all Event Grid topics in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridTopic) )
#### Get-AzEventGridTopicKey
Gets the shared access keys used to publish events to an Event Grid topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridTopicKey) )
#### Get-AzEventGridTopicType
Gets the details about the topic types supported by Azure Event Grid.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Get-AzEventGridTopicType) )
#### Get-AzEventHub
Gets the details of a single Event Hub, or gets a list of Event Hubs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHub) )
#### Get-AzEventHubAuthorizationRule
Gets the details of an authorization rule, or gets a list of authorization rules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHubAuthorizationRule) )
#### Get-AzEventHubConsumerGroup
Gets the details of a specified Event Hubs consumer group, or gets a list of consumer groups in an Event Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHubConsumerGroup) )
#### Get-AzEventHubGeoDRConfiguration
Retrieves Alias(Disaster Recovery configuration) for primary or secondary namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHubGeoDRConfiguration) )
#### Get-AzEventHubKey
Gets the primary key details of the specified Event Hubs authorization rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHubKey) )
#### Get-AzEventHubNamespace
Gets the details of an Event Hubs namespace, or gets a list of all Event Hubs namespaces in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHubNamespace) )
#### Get-AzEventHubNetworkRuleSet
Gets the details of an Event Hubs NetwrokruleSet of namespace in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Get-AzEventHubNetworkRuleSet) )
#### Get-AzExpressRouteCircuit
Gets an Azure ExpressRoute circuit from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuit) )
#### Get-AzExpressRouteCircuitARPTable
Gets the ARP table from an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitARPTable) )
#### Get-AzExpressRouteCircuitAuthorization
Gets information about ExpressRoute circuit authorizations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitAuthorization) )
#### Get-AzExpressRouteCircuitConnectionConfig
Gets an ExpressRoute circuit connection configuration associated with Private Peering of ExpressRouteCircuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitConnectionConfig) )
#### Get-AzExpressRouteCircuitPeeringConfig
Gets an ExpressRoute circuit peering configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitPeeringConfig) )
#### Get-AzExpressRouteCircuitRouteTable
Gets a route table from an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitRouteTable) )
#### Get-AzExpressRouteCircuitRouteTableSummary
Gets a route table summary of an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitRouteTableSummary) )
#### Get-AzExpressRouteCircuitStat
Gets usage statistics of an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCircuitStat) )
#### Get-AzExpressRouteConnection
Gets a ExpressRoute connection by name or lists all ExpressRoute connections connected to a ExpressRouteGateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteConnection) )
#### Get-AzExpressRouteCrossConnection
Gets an Azure ExpressRoute cross connection from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCrossConnection) )
#### Get-AzExpressRouteCrossConnectionArpTable
Gets the ARP table from an ExpressRoute cross connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCrossConnectionArpTable) )
#### Get-AzExpressRouteCrossConnectionPeering
Gets an ExpressRoute cross connection peering configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCrossConnectionPeering) )
#### Get-AzExpressRouteCrossConnectionRouteTable
Gets a route table from an ExpressRoute cross connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCrossConnectionRouteTable) )
#### Get-AzExpressRouteCrossConnectionRouteTableSummary
Gets a route table summary of an ExpressRoute cross connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteCrossConnectionRouteTableSummary) )
#### Get-AzExpressRouteGateway
Gets a ExpressRouteGateway resource using ResourceGroupName and GatewayName OR lists all gateways by ResourceGroupName or SubscriptionId.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteGateway) )
#### Get-AzExpressRoutePort
Gets an Azure ExpressRoutePort resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRoutePort) )
#### Get-AzExpressRoutePortLinkConfig
Gets an ExpressRoutePort link configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRoutePortLinkConfig) )
#### Get-AzExpressRoutePortsLocation
Gets the locations at which ExpressRoutePort resources are available.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRoutePortsLocation) )
#### Get-AzExpressRouteServiceProvider
Gets a list ExpressRoute service providers and their attributes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzExpressRouteServiceProvider) )
#### Get-AzExternalSecuritySolution
Get external security solution(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzExternalSecuritySolution) )
#### Get-AzFirewall
Gets a Azure Firewall.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzFirewall) )
#### Get-AzFirewallFqdnTag
Gets the available Azure Firewall Fqdn Tags.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzFirewallFqdnTag) )
#### Get-AzFrontDoor
Get Front Door load balancer(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Get-AzFrontDoor) )
#### Get-AzFrontDoorFrontendEndpoint
Get a front door frontend endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Get-AzFrontDoorFrontendEndpoint) )
#### Get-AzFrontDoorWafPolicy
Get WAF policy(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Get-AzFrontDoorWafPolicy) )
#### Get-AzGallery
Get or list galleries.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzGallery) )
#### Get-AzGalleryImageDefinition
Get or list gallery image definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzGalleryImageDefinition) )
#### Get-AzGalleryImageVersion
Get or list gallery image versions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzGalleryImageVersion) )
#### Get-AzHDInsightCluster
Gets and lists all of the Azure HDInsight clusters associated with the current subscription or a specified resource group, or retrieves a specific cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightCluster) )
#### Get-AzHDInsightJob
Gets the list of jobs from a cluster and lists them in reverse chronological order, or retrieves a specific job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightJob) )
#### Get-AzHDInsightJobOutput
Gets the log output for a job from the storage account associated with a specified cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightJobOutput) )
#### Get-AzHDInsightOperationsManagementSuite
Gets the status of Operations Management Suite (OMS) installation on the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightOperationsManagementSuite) )
#### Get-AzHDInsightPersistedScriptAction
Gets the persisted script actions for a cluster and lists them in chronological order, or gets details for a specified persisted script action.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightPersistedScriptAction) )
#### Get-AzHDInsightProperty
Gets properties about the HDInsight service, such as available locations and capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightProperty) )
#### Get-AzHDInsightScriptActionHistory
Gets the script action history for a cluster and lists it in reverse chronological order, or gets details of a previously executed script action.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Get-AzHDInsightScriptActionHistory) )
#### Get-AzImage
Gets the properties of an image.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzImage) [3.1a.36](#31a36))
#### Get-AzIntegrationAccount
Gets integration accounts.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccount) )
#### Get-AzIntegrationAccountAgreement
Gets an integration account agreement.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountAgreement) )
#### Get-AzIntegrationAccountAssembly
Gets an integration account assembly.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountAssembly) )
#### Get-AzIntegrationAccountBatchConfiguration
Gets an integration account batch configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountBatchConfiguration) )
#### Get-AzIntegrationAccountCallbackUrl
Gets an integration account callback URL.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountCallbackUrl) )
#### Get-AzIntegrationAccountCertificate
Gets integration account certificates from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountCertificate) )
#### Get-AzIntegrationAccountGeneratedIcn
This cmdlet retrieves the current value of the generated interchange control number per agreement.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountGeneratedIcn) )
#### Get-AzIntegrationAccountMap
Gets an integration account map.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountMap) )
#### Get-AzIntegrationAccountPartner
Gets integration account partners.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountPartner) )
#### Get-AzIntegrationAccountReceivedIcn
This cmdlet retrieves a specific received interchange control number per agreement and control number value.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountReceivedIcn) )
#### Get-AzIntegrationAccountSchema
Gets integration account schemas.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzIntegrationAccountSchema) )
#### Get-AzIoTDeviceProvisioningService
List all or show details of Azure IoT Hub device provisioning services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Get-AzIoTDeviceProvisioningService) )
#### Get-AzIoTDeviceProvisioningServiceAccessPolicy
List all or show details of shared access policies in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Get-AzIoTDeviceProvisioningServiceAccessPolicy) )
#### Get-AzIoTDeviceProvisioningServiceCertificate
Lists all certificates or a particular certificate contained within an Azure IoT Hub Device Provisioning Service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Get-AzIoTDeviceProvisioningServiceCertificate) )
#### Get-AzIoTDeviceProvisioningServiceLinkedHub
List all or show details of linked IoT hubs in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Get-AzIoTDeviceProvisioningServiceLinkedHub) )
#### Get-AzIotHub
Gets information about the IotHubs in a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHub) )
#### Get-AzIotHubCertificate
Lists all certificates or a particular certificate contained within an Azure IoT Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubCertificate) )
#### Get-AzIotHubCertificateVerificationCode
Generates a verification code for an Azure IoT Hub certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubCertificateVerificationCode) )
#### Get-AzIotHubConnectionString
Gets the IotHub connectionstrings.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubConnectionString) )
#### Get-AzIotHubEventHubConsumerGroup
Gets all the eventhub consumergroups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubEventHubConsumerGroup) )
#### Get-AzIotHubJob
Gets the information about an IotHub job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubJob) )
#### Get-AzIotHubKey
Gets an IotHub Key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubKey) )
#### Get-AzIotHubQuotaMetric
Gets the Quota Metrics for an IotHub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubQuotaMetric) )
#### Get-AzIotHubRegistryStatistic
Gets the RegistryStatistics for an IotHub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubRegistryStatistic) )
#### Get-AzIotHubRoute
Get information about the route in IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubRoute) )
#### Get-AzIotHubRoutingEndpoint
Get information on all the endpoints for your IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubRoutingEndpoint) )
#### Get-AzIotHubValidSku
Gets all valid skus that this IotHub can transition to.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Get-AzIotHubValidSku) )
#### Get-AzJitNetworkAccessPolicy
Gets the JIT network access policies(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzJitNetworkAccessPolicy) )
#### Get-AzKeyVault
Gets key vaults.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVault) )
#### Get-AzKeyVaultCertificate
Gets a certificate from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultCertificate) )
#### Get-AzKeyVaultCertificateContact
Gets contacts that are registered for certificate notifications for a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultCertificateContact) )
#### Get-AzKeyVaultCertificateIssuer
Gets a certificate issuer for a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultCertificateIssuer) )
#### Get-AzKeyVaultCertificateOperation
Gets the status of a certificate operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultCertificateOperation) )
#### Get-AzKeyVaultCertificatePolicy
Gets the policy for a certificate in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultCertificatePolicy) )
#### Get-AzKeyVaultKey
Gets Key Vault keys.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultKey) )
#### Get-AzKeyVaultManagedStorageAccount
Gets Key Vault managed Azure Storage Accounts.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultManagedStorageAccount) )
#### Get-AzKeyVaultManagedStorageSasDefinition
Gets Key Vault managed Storage SAS Definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultManagedStorageSasDefinition) )
#### Get-AzKeyVaultSecret
Gets the secrets in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Get-AzKeyVaultSecret) )
#### Get-AzKustoCluster
List all Kusto clusters in a resource group or get a specific Kusto cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Get-AzKustoCluster) )
#### Get-AzKustoDatabase
List all Kusto databases in a cluster or get a specific Kusto database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Get-AzKustoDatabase) )
#### Get-AzLegacyPeering
Used to Convert Legacy Peering resources to Azure Resource Management (ARM) Resources.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Get-AzLegacyPeering) )
#### Get-AzLoadBalancer
Gets a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancer) [4.5a.02](#45a02))
#### Get-AzLoadBalancerBackendAddressPoolConfig
Gets a backend address pool configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerBackendAddressPoolConfig) [4.5a.02](#45a02))
#### Get-AzLoadBalancerFrontendIpConfig
Gets a front-end IP configuration in a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerFrontendIpConfig) )
#### Get-AzLoadBalancerInboundNatPoolConfig
Gets one or more inbound NAT pool configurations from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerInboundNatPoolConfig) )
#### Get-AzLoadBalancerInboundNatRuleConfig
Gets an inbound NAT rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerInboundNatRuleConfig) )
#### Get-AzLoadBalancerOutboundRuleConfig
Gets an outbound rule configuration in a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerOutboundRuleConfig) )
#### Get-AzLoadBalancerProbeConfig
Gets a probe configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerProbeConfig) )
#### Get-AzLoadBalancerRuleConfig
Gets the rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLoadBalancerRuleConfig) )
#### Get-AzLocalNetworkGateway
Gets a Local Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzLocalNetworkGateway) )
#### Get-AzLocation
Gets all locations and the supported resource providers for each location.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzLocation) )
#### Get-AzLogicApp
Gets a logic app from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicApp) )
#### Get-AzLogicAppRunAction
Gets an action from a logic app run.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicAppRunAction) )
#### Get-AzLogicAppRunHistory
Gets the run history of a logic app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicAppRunHistory) )
#### Get-AzLogicAppTrigger
Gets the triggers of a logic app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicAppTrigger) )
#### Get-AzLogicAppTriggerCallbackUrl
Gets a Logic App trigger callback URL.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicAppTriggerCallbackUrl) )
#### Get-AzLogicAppTriggerHistory
Gets the history of triggers in a logic app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicAppTriggerHistory) )
#### Get-AzLogicAppUpgradedDefinition
Gets the upgraded definition for a logic app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Get-AzLogicAppUpgradedDefinition) )
#### Get-AzManagedApplication
Gets managed applications(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzManagedApplication) )
#### Get-AzManagedApplicationDefinition
Gets managed application definitions(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzManagedApplicationDefinition) )
#### Get-AzManagedServicesAssignment
Gets a list of the registration assignments.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedservices/Get-AzManagedServicesAssignment) )
#### Get-AzManagedServicesDefinition
Gets a list of the registration definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedservices/Get-AzManagedServicesDefinition) )
#### Get-AzManagementGroup
Gets Management Group(s)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzManagementGroup) )
#### Get-AzManagementPartner
Gets the Microsoft Partner Network(MPN) ID of the current authenticated user or service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managementpartner/Get-AzManagementPartner) )
#### Get-AzMapsAccount
Gets the account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.maps/Get-AzMapsAccount) )
#### Get-AzMapsAccountKey
Gets the API keys for an account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.maps/Get-AzMapsAccountKey) )
#### Get-AzMarketplaceTerms
Get the agreement terms for a given publisher id(Publisher), offer id(Product) and plan id(Name). The terms object which is returned by this command should be passed to Set-AzMarketplaceTerms to accept the legal terms.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.marketplaceordering/Get-AzMarketplaceTerms) )
#### Get-AzMediaService
Gets information about a media service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Get-AzMediaService) )
#### Get-AzMediaServiceKey
Gets key information for accessing the REST endpoint associated with the media service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Get-AzMediaServiceKey) )
#### Get-AzMediaServiceNameAvailability
Checks whether a media service name is available.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Get-AzMediaServiceNameAvailability) )
#### Get-AzMlCommitmentAssociation
Retrieves the summary information for one or more commitment associations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlCommitmentAssociation) )
#### Get-AzMlCommitmentPlan
Retrieves the summary information for one or more commitment plans.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlCommitmentPlan) )
#### Get-AzMlCommitmentPlanUsageHistory
Retrieves usage history information for a specified commitment plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlCommitmentPlanUsageHistory) )
#### Get-AzMlOpCluster
Gets an operationalization cluster object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlOpCluster) )
#### Get-AzMlOpClusterKey
Gets the access keys associated with an operationalization cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlOpClusterKey) )
#### Get-AzMlWebService
Retrieves the summary information for one or more web services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlWebService) )
#### Get-AzMlWebServiceKey
Retrieves the web service's keys.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Get-AzMlWebServiceKey) )
#### Get-AzNatGateway
Gets a Nat Gateway resource in a resource group by name or NatGateway Id or all Nat Gateway resources in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNatGateway) )
#### Get-AzNetAppFilesAccount
Gets details of an Azure NetApp Files (ANF) account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Get-AzNetAppFilesAccount) )
#### Get-AzNetAppFilesPool
Gets details of an Azure NetApp Files (ANF) pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Get-AzNetAppFilesPool) )
#### Get-AzNetAppFilesSnapshot
Gets details of an Azure NetApp Files (ANF) snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Get-AzNetAppFilesSnapshot) )
#### Get-AzNetAppFilesVolume
Gets details of an Azure NetApp Files (ANF) volume.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Get-AzNetAppFilesVolume) )
#### Get-AzNetworkInterface
Gets a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkInterface) [4.3b.02](#43b02))
#### Get-AzNetworkInterfaceIpConfig
Gets a network interface IP configuration for a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkInterfaceIpConfig) [4.5a.02](#45a02))
#### Get-AzNetworkInterfaceTapConfig
Gets a Tap configuration resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkInterfaceTapConfig) )
#### Get-AzNetworkProfile
Gets an existing network profile top level resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkProfile) )
#### Get-AzNetworkSecurityGroup
Gets a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkSecurityGroup) )
#### Get-AzNetworkSecurityRuleConfig
Get a network security rule configuration for a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkSecurityRuleConfig) )
#### Get-AzNetworkServiceTag
Gets the list of service tag information resources.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkServiceTag) )
#### Get-AzNetworkUsage
Lists network usages for a subscription(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkUsage) )
#### Get-AzNetworkWatcher
Gets the properties of a Network Watcher(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcher) [4.6c.10](#46c10) [4.6d.02](#46d02))
#### Get-AzNetworkWatcherConnectionMonitor
Returns connection monitor with specified name or the list of connection monitors(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherConnectionMonitor) )
#### Get-AzNetworkWatcherConnectionMonitorReport
Query a snapshot of the most recent connection states.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherConnectionMonitorReport) )
#### Get-AzNetworkWatcherFlowLogStatus
Gets the status of flow logging on a resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherFlowLogStatus) )
#### Get-AzNetworkWatcherNextHop
Gets the next hop from a VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherNextHop) [4.6c.07](#46c07))
#### Get-AzNetworkWatcherPacketCapture
Gets information and properties and status of a packet capture resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherPacketCapture) [4.6c.10](#46c10))
#### Get-AzNetworkWatcherReachabilityProvidersList
Lists all available internet service providers for a specified Azure region.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherReachabilityProvidersList) )
#### Get-AzNetworkWatcherReachabilityReport
Gets the relative latency score for internet service providers from a specified location to Azure regions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherReachabilityReport) )
#### Get-AzNetworkWatcherSecurityGroupView
View the configured and effective network security group rules applied on a VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherSecurityGroupView) )
#### Get-AzNetworkWatcherTopology
Gets a network level view of resources and their relationships in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherTopology) [4.6c.13](#46c13))
#### Get-AzNetworkWatcherTroubleshootingResult
Gets the troubleshooting result from the previously run or currently running troubleshooting operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzNetworkWatcherTroubleshootingResult) )
#### Get-AzNotificationHub
Gets information about your notification hubs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHub) )
#### Get-AzNotificationHubAuthorizationRule
Gets information about the authorization rules associated with a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHubAuthorizationRule) )
#### Get-AzNotificationHubListKey
Gets the primary and secondary connection strings associated with a notification hub authorization rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHubListKey) )
#### Get-AzNotificationHubPNSCredential
Gets the PNS credentials for a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHubPNSCredential) )
#### Get-AzNotificationHubsNamespace
Gets information about a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHubsNamespace) )
#### Get-AzNotificationHubsNamespaceAuthorizationRule
Gets information about the authorization rules associated with a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHubsNamespaceAuthorizationRule) )
#### Get-AzNotificationHubsNamespaceListKey
Gets the primary and secondary connection strings associated with a notification hub namespace authorization rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Get-AzNotificationHubsNamespaceListKey) )
#### Get-AzOperationalInsightsDataSource
Get datasources under Azure Log Analytics workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsDataSource) )
#### Get-AzOperationalInsightsIntelligencePack
Gets the available Intelligence Packs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsIntelligencePack) )
#### Get-AzOperationalInsightsLinkTarget
Gets accounts that are not associated with a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsLinkTarget) )
#### Get-AzOperationalInsightsSavedSearch
Returns all of the saved searches for a specified workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsSavedSearch) )
#### Get-AzOperationalInsightsSavedSearchResult
Returns the results from a query.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsSavedSearchResult) )
#### Get-AzOperationalInsightsSchema
Returns the schema associated with a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsSchema) )
#### Get-AzOperationalInsightsSearchResult
Returns search results based on the specified parameters.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsSearchResult) )
#### Get-AzOperationalInsightsStorageInsight
Gets information about a Storage Insight.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsStorageInsight) )
#### Get-AzOperationalInsightsWorkspace
Gets information about a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsWorkspace) [1.2a.04](#12a04))
#### Get-AzOperationalInsightsWorkspaceManagementGroup
Gets details of management groups connected to a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsWorkspaceManagementGroup) )
#### Get-AzOperationalInsightsWorkspaceSharedKey
Gets the shared keys for a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsWorkspaceSharedKey) )
#### Get-AzOperationalInsightsWorkspaceUsage
Gets the usage data for a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Get-AzOperationalInsightsWorkspaceUsage) )
#### Get-AzPeerAsn
Gets PeerAsn object from ARM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Get-AzPeerAsn) )
#### Get-AzPeering
Gets the Peering Resources for a subsription(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Get-AzPeering) )
#### Get-AzPeeringLocation
Gets the Peering locations offered by Microsoft(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Get-AzPeeringLocation) )
#### Get-AzPolicyAlias
Get-AzPolicyAlias retrieves and outputs Azure provider resource types that have aliases defined and match the(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzPolicyAlias) )
#### Get-AzPolicyAssignment
Gets policy assignments.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzPolicyAssignment) )
#### Get-AzPolicyDefinition
Gets policy definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzPolicyDefinition) )
#### Get-AzPolicyEvent
Gets policy evaluation events generated as resources are created or updated.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Get-AzPolicyEvent) )
#### Get-AzPolicyRemediation
Gets policy remediations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Get-AzPolicyRemediation) )
#### Get-AzPolicySetDefinition
Gets policy set definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzPolicySetDefinition) )
#### Get-AzPolicyState
Gets policy compliance states for resources.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Get-AzPolicyState) )
#### Get-AzPolicyStateSummary
Gets latest policy compliance states summary for resources.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Get-AzPolicyStateSummary) )
#### Get-AzPowerBIEmbeddedCapacity
Gets the details of a PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Get-AzPowerBIEmbeddedCapacity) )
#### Get-AzPowerBIWorkspace
Gets the workspaces in a Power BI workspace collection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Get-AzPowerBIWorkspace) )
#### Get-AzPowerBIWorkspaceCollection
Gets Power BI workspace collections.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Get-AzPowerBIWorkspaceCollection) )
#### Get-AzPowerBIWorkspaceCollectionAccessKey
Gets the current access keys associated with a Power BI workspace collection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Get-AzPowerBIWorkspaceCollectionAccessKey) )
#### Get-AzPrivateDnsRecordSet
Gets a record set from a Private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Get-AzPrivateDnsRecordSet) )
#### Get-AzPrivateDnsVirtualNetworkLink
Gets a virtual network link associated with the specified Private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Get-AzPrivateDnsVirtualNetworkLink) )
#### Get-AzPrivateDnsZone
Gets a Private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Get-AzPrivateDnsZone) )
#### Get-AzPrivateEndpoint
Get a private endpoint(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzPrivateEndpoint) )
#### Get-AzPrivateEndpointConnection
Get a private endpoint connection(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzPrivateEndpointConnection) )
#### Get-AzPrivateLinkService
Gets private link service(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzPrivateLinkService) )
#### Get-AzProfile
Get the service profiles supported by installed modules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzProfile) )
#### Get-AzProviderFeature
Gets information about Azure provider features.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzProviderFeature) )
#### Get-AzProviderOperation
Gets the operations for an Azure resource provider that are securable using Azure RBAC.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzProviderOperation) [1.4b.03](#14b03))
#### Get-AzProximityPlacementGroup
Get or list Proximity Placement Group resource(s).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzProximityPlacementGroup) )
#### Get-AzPublicIpAddress
Gets a public IP address.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzPublicIpAddress) )
#### Get-AzPublicIpPrefix
Gets a public IP prefix(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzPublicIpPrefix) )
#### Get-AzRecoveryServicesAsrAlertSetting
Gets the configured Azure Site Recovery notification settings for the vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrAlertSetting) )
#### Get-AzRecoveryServicesAsrEvent
Gets details of Azure Site Recovery events in the vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrEvent) )
#### Get-AzRecoveryServicesAsrFabric
Get the details of an Azure Site Recovery Fabric.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrFabric) )
#### Get-AzRecoveryServicesAsrJob
Gets the details of the specified ASR job or the list of recent ASR jobs in the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrJob) )
#### Get-AzRecoveryServicesAsrNetwork
Gets information about the networks managed by Site Recovery for the current vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrNetwork) )
#### Get-AzRecoveryServicesAsrNetworkMapping
Gets information about Site Recovery network mappings for the current vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrNetworkMapping) )
#### Get-AzRecoveryServicesAsrPolicy
Gets ASR replication policies.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrPolicy) )
#### Get-AzRecoveryServicesAsrProtectableItem
Get the protectable items in an ASR protection container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrProtectableItem) )
#### Get-AzRecoveryServicesAsrProtectionContainer
Gets ASR protection containers in the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrProtectionContainer) )
#### Get-AzRecoveryServicesAsrProtectionContainerMapping
Gets Azure Site Recovery Protection Container mappings.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrProtectionContainerMapping) )
#### Get-AzRecoveryServicesAsrRecoveryPlan
Gets a recovery plan or all the recovery plans in the Recovery Services vault(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrRecoveryPlan) )
#### Get-AzRecoveryServicesAsrRecoveryPoint
Gets the available recovery points for a replication protected item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrRecoveryPoint) )
#### Get-AzRecoveryServicesAsrReplicationProtectedItem
Gets the properties of an Azure Site Recovery Replication Protected Items.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrReplicationProtectedItem) )
#### Get-AzRecoveryServicesAsrServicesProvider
Gets the details of the ASR recovery services providers registered to the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrServicesProvider) )
#### Get-AzRecoveryServicesAsrStorageClassification
Gets the available(discovered) ASR storage classifications in the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrStorageClassification) )
#### Get-AzRecoveryServicesAsrStorageClassificationMapping
Gets ASR storage classification mappings.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrStorageClassificationMapping) )
#### Get-AzRecoveryServicesAsrVaultContext
Gets ASR vault settings information for the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrVaultContext) )
#### Get-AzRecoveryServicesAsrvCenter
Gets details of the vCenter servers registered for discovery on the Configuration server specified by the ASR fabric.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesAsrvCenter) )
#### Get-AzRecoveryServicesBackupContainer
Gets Backup containers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupContainer) )
#### Get-AzRecoveryServicesBackupItem
Gets the items from a container in Backup.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupItem) )
#### Get-AzRecoveryServicesBackupJob
Gets Backup jobs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupJob) )
#### Get-AzRecoveryServicesBackupJobDetail
Gets details for a Backup job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupJobDetail) )
#### Get-AzRecoveryServicesBackupManagementServer
Gets SCDPM and Azure Backup management servers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupManagementServer) )
#### Get-AzRecoveryServicesBackupProperty
Gets Backup properties.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupProperty) )
#### Get-AzRecoveryServicesBackupProtectableItem
Get protectable items from a container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupProtectableItem) )
#### Get-AzRecoveryServicesBackupProtectionPolicy
Gets Backup protection policies for a vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupProtectionPolicy) )
#### Get-AzRecoveryServicesBackupRecoveryLogChain
Get time ranges for a backed up item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupRecoveryLogChain) )
#### Get-AzRecoveryServicesBackupRecoveryPoint
Gets the recovery points for a backed up item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupRecoveryPoint) )
#### Get-AzRecoveryServicesBackupRetentionPolicyObject
Gets a base retention policy object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupRetentionPolicyObject) )
#### Get-AzRecoveryServicesBackupRPMountScript
Downloads a script to mount all the files of the recovery point.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupRPMountScript) )
#### Get-AzRecoveryServicesBackupSchedulePolicyObject
Gets a base schedule policy object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupSchedulePolicyObject) )
#### Get-AzRecoveryServicesBackupStatus
Checks whether your ARM resource is backed up or not.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupStatus) )
#### Get-AzRecoveryServicesBackupWorkloadRecoveryConfig
Get recovery plan for a backup up item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesBackupWorkloadRecoveryConfig) )
#### Get-AzRecoveryServicesVault
Gets a list of Recovery Services vaults.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesVault) )
#### Get-AzRecoveryServicesVaultSettingsFile
Gets the Azure Site Recovery vault settings file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Get-AzRecoveryServicesVaultSettingsFile) )
#### Get-AzRedisCache
Gets a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Get-AzRedisCache) )
#### Get-AzRedisCacheFirewallRule
Get firewall rules set on Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Get-AzRedisCacheFirewallRule) )
#### Get-AzRedisCacheKey
Gets the access keys for a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Get-AzRedisCacheKey) )
#### Get-AzRedisCacheLink
Get geo replication link for Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Get-AzRedisCacheLink) )
#### Get-AzRedisCachePatchSchedule
Gets a patch schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Get-AzRedisCachePatchSchedule) )
#### Get-AzRelayAuthorizationRule
Gets the description of a specified authorization rule for a given Relay entities (Namespace/WcfRelay/HybridConnection).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Get-AzRelayAuthorizationRule) )
#### Get-AzRelayHybridConnection
Gets a description for the specified HybridConnection within the Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Get-AzRelayHybridConnection) )
#### Get-AzRelayKey
Gets the primary and secondary connection strings for the given Relay entities (Namespace/WcfRelay/HybridConnection).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Get-AzRelayKey) )
#### Get-AzRelayNamespace
Gets a description for the specified Relay namespace within the resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Get-AzRelayNamespace) )
#### Get-AzRelayOperation
List supported Relay Operations(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Get-AzRelayOperation) )
#### Get-AzRemoteDesktopFile
Gets an .rdp file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzRemoteDesktopFile) [3.1f.01](#31f01))
#### Get-AzReservation
Get Reservations in a given reservation Order(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Get-AzReservation) )
#### Get-AzReservationCatalog
Get the catalog of available reservations(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Get-AzReservationCatalog) )
#### Get-AzReservationHistory
Get Reservation revision history.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Get-AzReservationHistory) )
#### Get-AzReservationOrder
Get ReservationOrder(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Get-AzReservationOrder) )
#### Get-AzReservationOrderId
Get list of applicable ReservationOrder Ids.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Get-AzReservationOrderId) )
#### Get-AzResource
Gets resources.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzResource) [1.2a.02](#12a02) [3.3d.02](#33d02) [4.6c.10](#46c10) [4.6d.02](#46d02))
#### Get-AzResourceGroup
Gets resource groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzResourceGroup) [1.1b.04](#11b04))
#### Get-AzResourceGroupDeployment
Gets the deployments in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzResourceGroupDeployment) )
#### Get-AzResourceGroupDeploymentOperation
Gets the resource group deployment operation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzResourceGroupDeploymentOperation) )
#### Get-AzResourceLock
Gets a resource lock.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzResourceLock) )
#### Get-AzResourceProvider
Gets a resource provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzResourceProvider) )
#### Get-AzRmStorageContainer
Gets or lists Storage blob containers(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzRmStorageContainer) )
#### Get-AzRmStorageContainerImmutabilityPolicy
Gets ImmutabilityPolicy of a Storage blob containers(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzRmStorageContainerImmutabilityPolicy) )
#### Get-AzRoleAssignment
Lists Azure RBAC role assignments at the specified scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzRoleAssignment) )
#### Get-AzRoleDefinition
Lists all Azure RBAC roles that are available for assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzRoleDefinition) [1.4b.01](#14b01) [1.4c.03](#14c03))
#### Get-AzRouteConfig
Gets routes from a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzRouteConfig) )
#### Get-AzRouteFilter
Gets a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzRouteFilter) )
#### Get-AzRouteFilterRuleConfig
Gets a route filter rule in a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzRouteFilterRuleConfig) )
#### Get-AzRouteTable
Gets route tables.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzRouteTable) )
#### Get-AzSearchAdminKeyPair
Gets admin key pair of the Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/Get-AzSearchAdminKeyPair) )
#### Get-AzSearchQueryKey
Gets query key(s) of the Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/Get-AzSearchQueryKey) )
#### Get-AzSearchService
Gets an Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/Get-AzSearchService) )
#### Get-AzSecurityAdvancedThreatProtection
Gets the advanced threat protection policy for a storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityAdvancedThreatProtection) )
#### Get-AzSecurityAlert
Gets security alerts that were detected by Azure Security Center(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityAlert) )
#### Get-AzSecurityAutoProvisioningSetting
Gets the security automatic provisioning settings(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityAutoProvisioningSetting) )
#### Get-AzSecurityCompliance
Get the security compliance of a subscription over time(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityCompliance) )
#### Get-AzSecurityContact
Gets security contacts that were configured on this subscription(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityContact) )
#### Get-AzSecurityLocation
Gets the location where Azure Security Center will automatically save data for the specific subscription(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityLocation) )
#### Get-AzSecurityPricing
Gets the pricing tier data for Azure Security Center for a scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityPricing) )
#### Get-AzSecurityTask
Gets the security tasks that Azure Security Center recommends you to do in order to strengthen your security posture.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityTask) )
#### Get-AzSecurityWorkspaceSetting
Gets the configured security workspace settings on a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Get-AzSecurityWorkspaceSetting) )
#### Get-AzServiceBusAuthorizationRule
Gets a description of the specified authorization rule for a given Namespace or Queue or Topic or Alias (GeoDR Configurations).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusAuthorizationRule) )
#### Get-AzServiceBusGeoDRConfiguration
Retrieves Alias(Disaster Recovery configuration) for primary or secondary namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusGeoDRConfiguration) )
#### Get-AzServiceBusKey
Gets the primary and secondary connection strings for the given Namespace or Queue or Topic or Alias (GeoDR Configurations).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusKey) )
#### Get-AzServiceBusMigration
Retrieves MigrationConfiguration for the namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusMigration) )
#### Get-AzServiceBusNamespace
Gets a description for the specified Service Bus namespace within the resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusNamespace) )
#### Get-AzServiceBusOperation
List supported ServiceBus Operations(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusOperation) )
#### Get-AzServiceBusQueue
Returns a description for the specified Service Bus queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusQueue) )
#### Get-AzServiceBusRule
Creates a new rule for a given Subscription of Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusRule) [1.2a.03](#12a03))
#### Get-AzServiceBusSubscription
Returns a subscription description for the specified topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusSubscription) )
#### Get-AzServiceBusTopic
Returns a description for the specified Service Bus topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Get-AzServiceBusTopic) )
#### Get-AzServiceEndpointPolicy
Gets a service endpoint policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzServiceEndpointPolicy) )
#### Get-AzServiceEndpointPolicyDefinition
Gets a service endpoint policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzServiceEndpointPolicyDefinition) )
#### Get-AzServiceFabricCluster
Get the cluster resource details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Get-AzServiceFabricCluster) )
#### Get-AzSignalR
Get a specific SignalR service or all the SignalR services in a resource group or a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.signalr/Get-AzSignalR) )
#### Get-AzSignalRKey
Get the access keys of a SignalR service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.signalr/Get-AzSignalRKey) )
#### Get-AzSmartGroup
Gets Smart Groups information(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Get-AzSmartGroup) )
#### Get-AzSmartGroupHistory
Gets smart group history(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Get-AzSmartGroupHistory) )
#### Get-AzSnapshot
Gets the properties of a snapshot(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzSnapshot) )
#### Get-AzSpatialAnchorsAccount
Get or list Spatial Anchors Account(s) in certain Subscription and Resource Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.mixedreality/Get-AzSpatialAnchorsAccount) )
#### Get-AzSpatialAnchorsAccountKey
Get developer keys of Spatial Anchors Account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.mixedreality/Get-AzSpatialAnchorsAccountKey) )
#### Get-AzSqlCapability
Gets SQL Database capabilities for the current subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlCapability) )
#### Get-AzSqlDatabase
Gets one or more databases.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabase) )
#### Get-AzSqlDatabaseActivity
Gets the status of database operations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseActivity) )
#### Get-AzSqlDatabaseAdvancedThreatProtectionSettings
Gets the advanced threat protection settings for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseAdvancedThreatProtectionSettings) )
#### Get-AzSqlDatabaseAdvisor
Gets one or more Advisors for an Azure SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseAdvisor) )
#### Get-AzSqlDatabaseAudit
Gets the auditing settings of an Azure SQL database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseAudit) )
#### Get-AzSqlDatabaseAuditing
Gets the auditing settings of an Azure SQL database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseAuditing) )
#### Get-AzSqlDatabaseBackupLongTermRetentionPolicy
Gets a database long term retention policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseBackupLongTermRetentionPolicy) )
#### Get-AzSqlDatabaseBackupShortTermRetentionPolicy
Gets a backup short term retention policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseBackupShortTermRetentionPolicy) )
#### Get-AzSqlDatabaseDataMaskingPolicy
Gets the data masking policy for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseDataMaskingPolicy) )
#### Get-AzSqlDatabaseDataMaskingRule
Gets the data masking rules from a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseDataMaskingRule) )
#### Get-AzSqlDatabaseExpanded
Gets a database and its expanded property values.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseExpanded) )
#### Get-AzSqlDatabaseFailoverGroup
Gets or lists Azure SQL Database Failover Groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseFailoverGroup) )
#### Get-AzSqlDatabaseGeoBackup
Gets a geo-redundant backup of a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseGeoBackup) )
#### Get-AzSqlDatabaseGeoBackupPolicy
Gets a database geo backup policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseGeoBackupPolicy) )
#### Get-AzSqlDatabaseImportExportStatus
Gets the details of an import or export of an Azure SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseImportExportStatus) )
#### Get-AzSqlDatabaseIndexRecommendation
Gets the recommended index operations for a server or database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseIndexRecommendation) )
#### Get-AzSqlDatabaseInstanceFailoverGroup
Gets or lists Azure SQL Database Instance Failover Groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseInstanceFailoverGroup) )
#### Get-AzSqlDatabaseLongTermRetentionBackup
Gets one or more long term retention backups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseLongTermRetentionBackup) )
#### Get-AzSqlDatabaseRecommendedAction
Gets one or more recommended actions for an Azure SQL Database Advisor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseRecommendedAction) )
#### Get-AzSqlDatabaseReplicationLink
Gets the geo-replication links between an Azure SQL Database and a resource group or SQL Server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseReplicationLink) )
#### Get-AzSqlDatabaseRestorePoint
Retrieves the distinct restore points from which a SQL Data Warehouse can be restored.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseRestorePoint) )
#### Get-AzSqlDatabaseSecureConnectionPolicy
Gets the secure connection policy for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseSecureConnectionPolicy) )
#### Get-AzSqlDatabaseSensitivityClassification
Gets the current information types and sensitivity labels of columns in the database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseSensitivityClassification) )
#### Get-AzSqlDatabaseSensitivityRecommendation
Gets the recommended information types and sensitivity labels of columns in the database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseSensitivityRecommendation) )
#### Get-AzSqlDatabaseTransparentDataEncryption
Gets the TDE state for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseTransparentDataEncryption) )
#### Get-AzSqlDatabaseTransparentDataEncryptionActivity
Gets the progress of a TDE scan of a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseTransparentDataEncryptionActivity) )
#### Get-AzSqlDatabaseUpgradeHint
Gets pricing tier hints for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseUpgradeHint) )
#### Get-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline
Gets the vulnerability assessment rule baseline.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline) )
#### Get-AzSqlDatabaseVulnerabilityAssessmentScanRecord
Gets all vulnerability assessment scan record(s) associated with a given database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseVulnerabilityAssessmentScanRecord) )
#### Get-AzSqlDatabaseVulnerabilityAssessmentSetting
Gets the vulnerability assessment settings of a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDatabaseVulnerabilityAssessmentSetting) )
#### Get-AzSqlDeletedDatabaseBackup
Gets a deleted database that you can restore.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDeletedDatabaseBackup) )
#### Get-AzSqlDeletedInstanceDatabaseBackup
Gets a deleted database that you can restore.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlDeletedInstanceDatabaseBackup) )
#### Get-AzSqlElasticPool
Gets elastic pools and their property values in an Azure SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlElasticPool) )
#### Get-AzSqlElasticPoolActivity
Gets the status of operations on an elastic pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlElasticPoolActivity) )
#### Get-AzSqlElasticPoolAdvisor
Gets one or more Advisors for an Azure SQL Elastic Pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlElasticPoolAdvisor) )
#### Get-AzSqlElasticPoolDatabase
Gets elastic databases in an elastic pool and their property values.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlElasticPoolDatabase) )
#### Get-AzSqlElasticPoolRecommendation
Gets elastic pool recommendations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlElasticPoolRecommendation) )
#### Get-AzSqlElasticPoolRecommendedAction
Gets one or more recommended actions for an Azure SQL Elastic Pool Advisor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlElasticPoolRecommendedAction) )
#### Get-AzSqlInstance
Returns information about Azure SQL Managed Database Instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstance) )
#### Get-AzSqlInstanceAdvancedDataSecurityPolicy
Gets Advanced Data Security policy of a managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceAdvancedDataSecurityPolicy) )
#### Get-AzSqlInstanceDatabase
Returns information about Azure SQL Managed Instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabase) )
#### Get-AzSqlInstanceDatabaseBackupShortTermRetentionPolicy
Gets a backup short term retention policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseBackupShortTermRetentionPolicy) )
#### Get-AzSqlInstanceDatabaseGeoBackup
Returns information about Azure SQL Managed Instance database redundant backup.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseGeoBackup) )
#### Get-AzSqlInstanceDatabaseSensitivityClassification
Gets the current information types and sensitivity labels of columns in the Azure SQL managed instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseSensitivityClassification) )
#### Get-AzSqlInstanceDatabaseSensitivityRecommendation
Gets the recommended information types and sensitivity labels of columns in the Azure SQL managed instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseSensitivityRecommendation) )
#### Get-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline
Gets the vulnerability assessment rule baseline.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline) )
#### Get-AzSqlInstanceDatabaseVulnerabilityAssessmentScanRecord
Gets all vulnerability assessment scan record(s) associated with a given managed database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseVulnerabilityAssessmentScanRecord) )
#### Get-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting
Gets the vulnerability assessment settings of a managed database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting) )
#### Get-AzSqlInstanceKeyVaultKey
Gets a SQL managed instance's Key Vault keys.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceKeyVaultKey) )
#### Get-AzSqlInstanceTransparentDataEncryptionProtector
Gets the Transparent Data Encryption (TDE) protector for a SQL managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceTransparentDataEncryptionProtector) )
#### Get-AzSqlInstanceVulnerabilityAssessmentSetting
Gets the vulnerability assessment settings of a managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlInstanceVulnerabilityAssessmentSetting) )
#### Get-AzSqlServer
Returns information about SQL Database servers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServer) )
#### Get-AzSqlServerActiveDirectoryAdministrator
Gets information about an Azure AD administrator for SQL Server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerActiveDirectoryAdministrator) )
#### Get-AzSqlServerAdvancedDataSecurityPolicy
Gets Advanced Data Security policy of a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerAdvancedDataSecurityPolicy) )
#### Get-AzSqlServerAdvancedThreatProtectionPolicy
Gets Advanced Threat Protection policy of a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerAdvancedThreatProtectionPolicy) )
#### Get-AzSqlServerAdvancedThreatProtectionSettings
Gets the advanced threat protection settings for a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerAdvancedThreatProtectionSettings) )
#### Get-AzSqlServerAdvisor
Gets one or more Advisors for an Azure SQL Server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerAdvisor) )
#### Get-AzSqlServerAudit
Gets the auditing settings of an Azure SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerAudit) )
#### Get-AzSqlServerAuditing
Gets the auditing settings of an Azure SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerAuditing) )
#### Get-AzSqlServerCommunicationLink
Gets communication links for elastic database transactions between database servers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerCommunicationLink) )
#### Get-AzSqlServerDisasterRecoveryConfiguration
Gets a database server system recovery configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerDisasterRecoveryConfiguration) )
#### Get-AzSqlServerDisasterRecoveryConfigurationActivity
Gets activity for a database server system recovery configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerDisasterRecoveryConfigurationActivity) )
#### Get-AzSqlServerDnsAlias
Gets or lists Azure SQL Server DNS Alias.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerDnsAlias) )
#### Get-AzSqlServerFirewallRule
Gets firewall rules for a SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerFirewallRule) )
#### Get-AzSqlServerKeyVaultKey
Gets a SQL server's Key Vault keys.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerKeyVaultKey) )
#### Get-AzSqlServerRecommendedAction
Gets one or more recommended actions for an Azure SQL Server Advisor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerRecommendedAction) )
#### Get-AzSqlServerServiceObjective
Gets service objectives for an Azure SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerServiceObjective) )
#### Get-AzSqlServerTransparentDataEncryptionProtector
Gets the Transparent Data Encryption (TDE) protector(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerTransparentDataEncryptionProtector) )
#### Get-AzSqlServerUpgradeHint
Gets pricing tier hints for upgrading an Azure SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerUpgradeHint) )
#### Get-AzSqlServerVirtualNetworkRule
Gets or lists Azure SQL Server Virtual Network Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerVirtualNetworkRule) )
#### Get-AzSqlServerVulnerabilityAssessmentSetting
Gets the vulnerability assessment settings of a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlServerVulnerabilityAssessmentSetting) )
#### Get-AzSqlSyncAgent
Returns information about Azure SQL Sync Agents.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlSyncAgent) )
#### Get-AzSqlSyncAgentLinkedDatabase
Returns information about SQL Server databases linked by a sync agent.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlSyncAgentLinkedDatabase) )
#### Get-AzSqlSyncGroup
Returns information about Azure SQL Database Sync Groups.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlSyncGroup) )
#### Get-AzSqlSyncGroupLog
Returns the logs of an Azure SQL Database Sync Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlSyncGroupLog) )
#### Get-AzSqlSyncMember
Returns information about Azure SQL Database Sync Members.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlSyncMember) )
#### Get-AzSqlSyncSchema
Returns information about the sync schema of a member database or a hub database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlSyncSchema) )
#### Get-AzSqlVirtualCluster
Returns information about Azure SQL Virtual Cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Get-AzSqlVirtualCluster) )
#### Get-AzStorageAccount
Gets a Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageAccount) [4.6c.10](#46c10))
#### Get-AzStorageAccountKey
Gets the access keys for an Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageAccountKey) [2.1c.02](#21c02) [2.1c.04](#21c04) [2.1d.01](#21d01) [2.1f.02](#21f02) [2.2a.01](#22a01) [2.3a.02](#23a02) [2.3a.06](#23a06))
#### Get-AzStorageAccountManagementPolicy
Gets the management policy of an Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageAccountManagementPolicy) )
#### Get-AzStorageAccountNameAvailability
Checks the availability of a Storage account name.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageAccountNameAvailability) )
#### Get-AzStorageAccountNetworkRuleSet
Get the NetWorkRule property of a Storage account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageAccountNetworkRuleSet) )
#### Get-AzStorageBlob
Lists blobs in a container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageBlob) )
#### Get-AzStorageBlobContent
Downloads a storage blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageBlobContent) )
#### Get-AzStorageBlobCopyState
Gets the copy status of an Azure Storage blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageBlobCopyState) [2.1f.03](#21f03))
#### Get-AzStorageBlobServiceProperty
Gets service properties for Azure Storage Blob services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageBlobServiceProperty) )
#### Get-AzStorageContainer
Lists the storage containers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageContainer) )
#### Get-AzStorageContainerStoredAccessPolicy
Gets the stored access policy or policies for an Azure storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageContainerStoredAccessPolicy) )
#### Get-AzStorageCORSRule
Gets CORS rules for a Storage service type.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageCORSRule) )
#### Get-AzStorageFile
Lists directories and files for a path.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageFile) )
#### Get-AzStorageFileContent
Downloads the contents of a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageFileContent) )
#### Get-AzStorageFileCopyState
Gets the state of a copy operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageFileCopyState) )
#### Get-AzStorageFileHandle
Lists file handles of a file share, a file directory or a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageFileHandle) )
#### Get-AzStorageQueue
Lists storage queues.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageQueue) )
#### Get-AzStorageQueueStoredAccessPolicy
Gets the stored access policy or policies for an Azure storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageQueueStoredAccessPolicy) )
#### Get-AzStorageServiceLoggingProperty
Gets logging properties for Azure Storage services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageServiceLoggingProperty) )
#### Get-AzStorageServiceMetricsProperty
Gets metrics properties for the Azure Storage service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageServiceMetricsProperty) )
#### Get-AzStorageServiceProperty
Gets properties for Azure Storage services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageServiceProperty) )
#### Get-AzStorageShare
Gets a list of file shares.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageShare) )
#### Get-AzStorageShareStoredAccessPolicy
Gets stored access policies for a Storage share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageShareStoredAccessPolicy) )
#### Get-AzStorageSyncCloudEndpoint
This command lists all cloud endpoints within a given sync group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Get-AzStorageSyncCloudEndpoint) )
#### Get-AzStorageSyncGroup
This command lists all sync groups within a given storage sync service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Get-AzStorageSyncGroup) )
#### Get-AzStorageSyncServer
This command lists all servers registered to a given storage sync service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Get-AzStorageSyncServer) )
#### Get-AzStorageSyncServerEndpoint
This command lists all server endpoints within a given sync group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Get-AzStorageSyncServerEndpoint) )
#### Get-AzStorageSyncService
This command lists all storage sync services within a given scope of subscription/resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Get-AzStorageSyncService) )
#### Get-AzStorageTable
Lists the storage tables.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageTable) )
#### Get-AzStorageTableStoredAccessPolicy
Gets the stored access policy or policies for an Azure storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageTableStoredAccessPolicy) )
#### Get-AzStorageUsage
Gets the Storage resource usage of the current subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Get-AzStorageUsage) [1.1b.01](#11b01))
#### Get-AzStreamAnalyticsDefaultFunctionDefinition
Gets the default definition of a function in Stream Analytics.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsDefaultFunctionDefinition) )
#### Get-AzStreamAnalyticsFunction
Gets functions in a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsFunction) )
#### Get-AzStreamAnalyticsInput
Gets Stream Analytics job inputs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsInput) )
#### Get-AzStreamAnalyticsJob
Gets Stream Analytics jobs information.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsJob) )
#### Get-AzStreamAnalyticsOutput
Gets the outputs defined in a specified Stream Analytics job or output.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsOutput) )
#### Get-AzStreamAnalyticsQuota
Gets information about the Streaming Unit quota for a region.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsQuota) )
#### Get-AzStreamAnalyticsTransformation
Gets information about a Stream Analytics job transformation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Get-AzStreamAnalyticsTransformation) )
#### Get-AzSubscription
Get subscriptions that the current account can access.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzSubscription) )
#### Get-AzTag
Gets predefined Azure tags.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Get-AzTag) )
#### Get-AzTenant
Gets tenants that are authorized for the current user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Get-AzTenant) )
#### Get-AzTrafficManagerEndpoint
Gets an endpoint for a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Get-AzTrafficManagerEndpoint) )
#### Get-AzTrafficManagerProfile
Gets a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Get-AzTrafficManagerProfile) )
#### Get-AzUserAssignedIdentity
Gets User Assigned Identity/identities.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedserviceidentity/Get-AzUserAssignedIdentity) )
#### Get-AzVirtualHub
Gets an Azure VirtualHub by Name and ResourceGroupName or lists all Virtual Hubs by ResourceGroupName/Subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualHub) )
#### Get-AzVirtualHubVnetConnection
Gets a Virtual Network Connection in a virtual hub or lists all virtual network connections in a virtual hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualHubVnetConnection) )
#### Get-AzVirtualNetwork
Gets a virtual network in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetwork) [3.3b.02](#33b02) [3.3b.02](#33b02) [4.1d.02](#41d02) [4.2a.02](#42a02) [4.2b.02](#42b02) [4.3c.01](#43c01) [4.7a.02](#47a02))
#### Get-AzVirtualNetworkAvailableEndpointService
Lists available endpoint services for location.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkAvailableEndpointService) )
#### Get-AzVirtualNetworkGateway
Gets a Virtual Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGateway) [4.7b.02](#47b02))
#### Get-AzVirtualNetworkGatewayAdvertisedRoute
Lists routes being advertised by an Azure virtual network gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayAdvertisedRoute) )
#### Get-AzVirtualNetworkGatewayBGPPeerStatus
Lists an Azure virtual network gateway's BGP peers(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayBGPPeerStatus) )
#### Get-AzVirtualNetworkGatewayConnection
Gets a Virtual Network Gateway Connection(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayConnection) [4.6d.02](#46d02))
#### Get-AzVirtualNetworkGatewayConnectionSharedKey
Displays the shared key used for the connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayConnectionSharedKey) )
#### Get-AzVirtualNetworkGatewayConnectionVpnDeviceConfigScript
This commandlet takes the connection resource, VPN device brand, model, firmware version, and return the corresponding configuration script that customers can apply directly on their on-premises VPN devices. The script will follow the syntax of the selected device, and fill in the necessary parameters such as Azure gateway public IP addresses, virtual network address prefixes, VPN tunnel pre-shared key, etc. so customers can simply copy-paste to their VPN device configurations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayConnectionVpnDeviceConfigScript) )
#### Get-AzVirtualNetworkGatewayLearnedRoute
Lists routes learned by an Azure virtual network gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayLearnedRoute) )
#### Get-AzVirtualNetworkGatewaySupportedVpnDevice
This commandlet returns a list of supported VPN device brands, models, and firmware versions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewaySupportedVpnDevice) )
#### Get-AzVirtualNetworkGatewayVpnClientConnectionHealth
Gets virtual network vpn client connection health for per vpn client connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkGatewayVpnClientConnectionHealth) )
#### Get-AzVirtualNetworkPeering
Gets the virtual network peering.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkPeering) [4.2a.02](#42a02))
#### Get-AzVirtualNetworkSubnetConfig
Gets a subnet in a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkSubnetConfig) [4.2b.02](#42b02) [4.7a.02](#47a02))
#### Get-AzVirtualNetworkTap
Gets a virtual network tap(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkTap) )
#### Get-AzVirtualNetworkUsageList
Gets virtual network current usage.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualNetworkUsageList) )
#### Get-AzVirtualWan
Gets a Virtual WAN or all Virtual WANs in a resource group or subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualWan) )
#### Get-AzVirtualWanVpnConfiguration
Gets the Vpn configuration for a subset of VpnSites connected to this WAN via VpnConnections. Uploads the generated Vpn(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVirtualWanVpnConfiguration) )
#### Get-AzVM
Gets the properties of a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVM) [3.1a.02](#31a02) [3.1c.01](#31c01) [3.1e.02](#31e02) [3.3a.02](#33a02) [3.3b.02](#33b02) [3.3c.02](#33c02) [4.3b.02](#43b02) [4.4c.02](#44c02) [4.5a.02](#45a02) [4.6c.10](#46c10))
#### Get-AzVMAccessExtension
Gets information about the VMAccess extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMAccessExtension) )
#### Get-AzVMADDomainExtension
Gets information about an AD domain extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMADDomainExtension) )
#### Get-AzVMAEMExtension
Gets information about the AEM extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMAEMExtension) )
#### Get-AzVMBootDiagnosticsData
Gets boot diagnostics data for a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMBootDiagnosticsData) )
#### Get-AzVMChefExtension
Gets information about a Chef extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMChefExtension) )
#### Get-AzVMCustomScriptExtension
Gets information about a custom script extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMCustomScriptExtension) )
#### Get-AzVMDiagnosticsExtension
Gets the settings of the Diagnostics extension on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMDiagnosticsExtension) )
#### Get-AzVMDiskEncryptionStatus
Gets the encryption status of the virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMDiskEncryptionStatus) )
#### Get-AzVMDscExtension
Gets the settings of the DSC extension on a particular virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMDscExtension) )
#### Get-AzVMDscExtensionStatus
Gets the status of the DSC extension handler for a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMDscExtensionStatus) )
#### Get-AzVMExtension
Gets properties of Virtual Machine Extensions installed on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMExtension) )
#### Get-AzVMExtensionImage
Gets all versions for an Azure extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMExtensionImage) )
#### Get-AzVMExtensionImageType
Gets the type of an Azure extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMExtensionImageType) )
#### Get-AzVMGuestPolicyStatus
Gets guest configuration policy statuses (detailed) for an initiative of type "Guest Configuration" that is assigned to a VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.guestconfiguration/Get-AzVMGuestPolicyStatus) )
#### Get-AzVMGuestPolicyStatusHistory
Gets guest configuration policy compliance status history for an initiative of type "Guest Configuration" that is assigned to a VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.guestconfiguration/Get-AzVMGuestPolicyStatusHistory) )
#### Get-AzVMImage
Gets all the versions of a VMImage.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMImage) )
#### Get-AzVMImageOffer
Gets VMImage offer types.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMImageOffer) )
#### Get-AzVMImagePublisher
Gets the VMImage publishers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMImagePublisher) )
#### Get-AzVMImageSku
Gets VMImage SKUs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMImageSku) )
#### Get-AzVMRunCommandDocument
Get a run command document.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMRunCommandDocument) )
#### Get-AzVMSize
Gets available virtual machine sizes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMSize) [3.1c.01](#31c01) [3.3c.01](#33c01))
#### Get-AzVMSqlServerExtension
Gets the settings for a SQL Server extension on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMSqlServerExtension) )
#### Get-AzVmss
Gets the properties of a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVmss) )
#### Get-AzVmssDiskEncryption
Shows the disk encryption status of a VM scale set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVmssDiskEncryption) )
#### Get-AzVmssRollingUpgrade
Shows the status of the latest virtual machine scale set rolling upgrade.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVmssRollingUpgrade) )
#### Get-AzVmssSku
Gets the available SKUs for the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVmssSku) )
#### Get-AzVmssVM
Gets the properties of a VMSS virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVmssVM) )
#### Get-AzVmssVMDiskEncryption
Shows the disk encryption status of VMs in a VM scale set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVmssVMDiskEncryption) )
#### Get-AzVMUsage
Gets the virtual machine core count usage for a location.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Get-AzVMUsage) [1.1b.01](#11b01))
#### Get-AzVpnClientConfiguration
Allows users to easily download the Vpn Profile package that was generated using the New-AzVpnClientConfiguration commandlet.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnClientConfiguration) )
#### Get-AzVpnClientIpsecParameter
Gets the vpn Ipsec parameters set on Virtual Network Gateway for Point to site connections.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnClientIpsecParameter) )
#### Get-AzVpnClientPackage
Gets information about a VPN client package.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnClientPackage) )
#### Get-AzVpnClientRevokedCertificate
Gets information about VPN client-revocation certificates.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnClientRevokedCertificate) )
#### Get-AzVpnClientRootCertificate
Gets information about VPN root certificates.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnClientRootCertificate) )
#### Get-AzVpnConnection
Gets a vpn connection by name or lists all vpn connections connected to a VpnGateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnConnection) )
#### Get-AzVpnGateway
Gets a VpnGateway resource using ResourceGroupName and GatewayName OR lists all gateways by ResourceGroupName or SubscriptionId.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnGateway) )
#### Get-AzVpnSite
Gets an Azure VpnSite resource by name OR lists all VpnSites in a ResourceGroup or SubscriptionId.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Get-AzVpnSite) )
#### Get-AzWcfRelay
Returns a description for the specified WcfRelay.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Get-AzWcfRelay) )
#### Get-AzWebApp
Gets Azure Web Apps in the specified resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebApp) )
#### Get-AzWebAppBackup
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppBackup) )
#### Get-AzWebAppBackupConfiguration
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppBackupConfiguration) )
#### Get-AzWebAppBackupList
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppBackupList) )
#### Get-AzWebAppCertificate
Gets an Azure Web App certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppCertificate) )
#### Get-AzWebAppContainerContinuousDeploymentUrl
Get-AzWebAppContainerContinuousDeploymentUrl will return container continuous deployment url(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppContainerContinuousDeploymentUrl) )
#### Get-AzWebAppMetric
Gets Azure Web App metrics.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppMetric) )
#### Get-AzWebAppPublishingProfile
Gets an Azure Web App publishing profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppPublishingProfile) )
#### Get-AzWebAppSlot
Gets an Azure Web App slot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppSlot) )
#### Get-AzWebAppSlotConfigName
Get the list of Web App Slot Config names(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppSlotConfigName) )
#### Get-AzWebAppSlotMetric
Gets metrics for an Azure Web App slot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppSlotMetric) )
#### Get-AzWebAppSlotPublishingProfile
Gets an Azure Web App slot publishing profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppSlotPublishingProfile) )
#### Get-AzWebAppSnapshot
Gets the snapshots available for a web app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppSnapshot) )
#### Get-AzWebAppSSLBinding
Gets an Azure Web App certificate SSL binding.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Get-AzWebAppSSLBinding) )
#### Get-UsageAggregates
Gets the reported Azure subscription usage details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Get-UsageAggregates) )
#### Grant-AzDiskAccess
Grants an access to a disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Grant-AzDiskAccess) )
#### Grant-AzHDInsightRdpServicesAccess
Grants RDP access to the Windows cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Grant-AzHDInsightRdpServicesAccess) )
#### Grant-AzSnapshotAccess
Grants an access to a snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Grant-AzSnapshotAccess) )
#### Import-AzAksCredential
Import and merge Kubectl config for a managed Kubernetes Cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/Import-AzAksCredential) )
#### Import-AzApiManagementApi
Imports an API from a file or a URL.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Import-AzApiManagementApi) )
#### Import-AzAutomationDscConfiguration
Imports a DSC configuration into Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Import-AzAutomationDscConfiguration) )
#### Import-AzAutomationDscNodeConfiguration
Imports a MOF document as a DSC node configuration in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Import-AzAutomationDscNodeConfiguration) )
#### Import-AzAutomationRunbook
Imports an Automation runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Import-AzAutomationRunbook) )
#### Import-AzBlueprintWithArtifact
Import a blueprint definition file in JSON format and save it to a blueprint object within the specified subscription or management group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Import-AzBlueprintWithArtifact) )
#### Import-AzContext
Loads Azure authentication information from a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Import-AzContext) )
#### Import-AzDataLakeStoreItem
Uploads a local file or directory to a Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Import-AzDataLakeStoreItem) )
#### Import-AzKeyVaultCertificate
Imports a certificate to a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Import-AzKeyVaultCertificate) )
#### Import-AzMlWebService
Imports a JSON object into a web service definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Import-AzMlWebService) )
#### Import-AzRecoveryServicesAsrVaultSettingsFile
Imports the specified ASR vault settings file to set the vault context(PowerShell session context) for subsequent ASR operations in the PowerShell session.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Import-AzRecoveryServicesAsrVaultSettingsFile) )
#### Import-AzRedisCache
Imports data from blobs to Azure Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Import-AzRedisCache) )
#### Initialize-AzRecoveryServicesBackupProtectableItem
Enquires for new DBs in the workload.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Initialize-AzRecoveryServicesBackupProtectableItem) )
#### Invoke-AzDataFactoryV2IntegrationRuntimeUpgrade
Upgrades self-hosted integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Invoke-AzDataFactoryV2IntegrationRuntimeUpgrade) )
#### Invoke-AzDataFactoryV2Pipeline
Invokes a pipeline to start a run for it.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Invoke-AzDataFactoryV2Pipeline) )
#### Invoke-AzDataMigrationCommand
Creates a new command to be executed on an existing DMS task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Invoke-AzDataMigrationCommand) )
#### Invoke-AzHDInsightHiveJob
Submits a Hive query to an HDInsight cluster and retrieves query results in one operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Invoke-AzHDInsightHiveJob) )
#### Invoke-AzNetworkWatcherNetworkConfigurationDiagnostic
Invoke network configuration diagnostic session for specified network profiles on target resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Invoke-AzNetworkWatcherNetworkConfigurationDiagnostic) )
#### Invoke-AzOperationalInsightsQuery
Returns search results based on the specified parameters.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Invoke-AzOperationalInsightsQuery) )
#### Invoke-AzResourceAction
Invokes an action on a resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Invoke-AzResourceAction) )
#### Invoke-AzStorageSyncChangeDetection
This command can be used to manually initiate the detection of namespaces changes. It can be targeted to the entire share, subfolder or set of files. A maximum of 10,000 changes can be detected. If the scope of changes is known to you, limit the execution of this command to parts of the namespace, so change detection can finish quickly and within a 10,000 changes limit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Invoke-AzStorageSyncChangeDetection) )
#### Invoke-AzStorageSyncCompatibilityCheck
Checks for potential compatibility issues between your system and Azure File Sync.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Invoke-AzStorageSyncCompatibilityCheck) )
#### Invoke-AzStorageSyncFileRecall
This command recalls all tiered files back to local disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Invoke-AzStorageSyncFileRecall) )
#### Invoke-AzVMReimage
Reimage an Azure virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Invoke-AzVMReimage) )
#### Invoke-AzVMRunCommand
Run a command on the VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Invoke-AzVMRunCommand) )
#### Invoke-AzVmssVMRunCommand
Run command on the Virtual Machine Scale Set VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Invoke-AzVmssVMRunCommand) )
#### Join-AzDataLakeStoreItem
Joins one or more files to create one file in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Join-AzDataLakeStoreItem) )
#### Lock-AzRmStorageContainerImmutabilityPolicy
Locks ImmutabilityPolicy of a Storage blob containers(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Lock-AzRmStorageContainerImmutabilityPolicy) )
#### Measure-AzAlertStatistic
Gets Alert Summary Information(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Measure-AzAlertStatistic) )
#### Merge-AzReservation
Merges two Reservations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Merge-AzReservation) )
#### Move-AzDataLakeStoreItem
Moves or renames a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Move-AzDataLakeStoreItem) )
#### Move-AzExpressRouteCircuit
Moves an ExpressRoute circuit from the classic deployment model to the Resource Manager deployment model.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Move-AzExpressRouteCircuit) )
#### Move-AzMlCommitmentAssociation
Moves a commitment association from one commitment plan to another.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Move-AzMlCommitmentAssociation) )
#### Move-AzResource
Moves a resource to a different resource group or subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Move-AzResource) [3.3d.02](#33d02))
#### New-AzADAppCredential
Adds a credential to an existing application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzADAppCredential) )
#### New-AzADApplication
Creates a new azure active directory application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzADApplication) )
#### New-AzADGroup
Creates a new active directory group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzADGroup) )
#### New-AzADServicePrincipal
Creates a new azure active directory service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzADServicePrincipal) )
#### New-AzADSpCredential
Adds a credential to an existing service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzADSpCredential) )
#### New-AzADUser
Creates a new active directory user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzADUser) )
#### New-AzAks
Create a new managed Kubernetes cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/New-AzAks) )
#### New-AzAnalysisServicesFirewallConfig
Creates a new Analysis Services firewall config(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/New-AzAnalysisServicesFirewallConfig) )
#### New-AzAnalysisServicesFirewallRule
Creates a new Analysis Services firewall rule(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/New-AzAnalysisServicesFirewallRule) )
#### New-AzAnalysisServicesServer
Creates a new Analysis Services server(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/New-AzAnalysisServicesServer) )
#### New-AzApiManagement
Creates an API Management deployment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagement) )
#### New-AzApiManagementApi
Creates an API.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementApi) )
#### New-AzApiManagementApiRelease
Creates an API Release of an API Revision(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementApiRelease) )
#### New-AzApiManagementApiRevision
Creates a new Revision of an Existing API.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementApiRevision) )
#### New-AzApiManagementApiSchema
Creates the new API Schema in the ApiManagement service(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementApiSchema) )
#### New-AzApiManagementApiVersionSet
Creates an API Version Set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementApiVersionSet) )
#### New-AzApiManagementAuthorizationServer
Creates an authorization server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementAuthorizationServer) )
#### New-AzApiManagementBackend
Creates a new backend entity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementBackend) )
#### New-AzApiManagementBackendCredential
Creates a new Backend Credential contract.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementBackendCredential) )
#### New-AzApiManagementBackendProxy
Creates a new Backend Proxy Object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementBackendProxy) )
#### New-AzApiManagementBackendServiceFabric
Creates an object of PsApiManagementServiceFabric(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementBackendServiceFabric) )
#### New-AzApiManagementCache
Creates a new Cache entity(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementCache) )
#### New-AzApiManagementCertificate
Creates an API Management certificate to be used during Authentication with Backend.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementCertificate) )
#### New-AzApiManagementContext
Creates an instance of PsAzureApiManagementContext.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementContext) )
#### New-AzApiManagementCustomHostnameConfiguration
Creates an instance of PsApiManagementCustomHostNameConfiguration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementCustomHostnameConfiguration) )
#### New-AzApiManagementDiagnostic
Creates a new diagnostics at the Global scope or Api Scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementDiagnostic) )
#### New-AzApiManagementGroup
Creates an API management group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementGroup) )
#### New-AzApiManagementHttpMessageDiagnostic
Creates an instance of PsApiManagementHttpMessageDiagnostic which is an Http Message diagnostic setting of the Diagnostic(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementHttpMessageDiagnostic) )
#### New-AzApiManagementIdentityProvider
Creates a new Identity Provider configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementIdentityProvider) )
#### New-AzApiManagementLogger
Creates an API Management Logger.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementLogger) )
#### New-AzApiManagementOpenIdConnectProvider
Creates an OpenID Connect provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementOpenIdConnectProvider) )
#### New-AzApiManagementOperation
Creates an API management operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementOperation) )
#### New-AzApiManagementPipelineDiagnosticSetting
Create Diagnostic settings for incoming/outgoing HTTP messages to the Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementPipelineDiagnosticSetting) )
#### New-AzApiManagementProduct
Creates an API Management product.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementProduct) )
#### New-AzApiManagementProperty
Creates a new Property.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementProperty) )
#### New-AzApiManagementRegion
Creates an instance of PsApiManagementRegion.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementRegion) )
#### New-AzApiManagementSamplingSetting
Create a new sampling setting for the Diagnostic(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementSamplingSetting) )
#### New-AzApiManagementSslSetting
Creates an instance of PsApiManagementSslSetting(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementSslSetting) )
#### New-AzApiManagementSubscription
Creates a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementSubscription) )
#### New-AzApiManagementSystemCertificate
Creates an instance of PsApiManagementSystemCertificate. The certificate can be issued by private CA's and will be installed on the API Management service into CertificateAuthority or Root store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementSystemCertificate) )
#### New-AzApiManagementUser
Registers a new user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementUser) )
#### New-AzApiManagementUserToken
Generates a Shared Access Token for the User.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementUserToken) )
#### New-AzApiManagementVirtualNetwork
Creates an instance of PsApiManagementVirtualNetwork.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/New-AzApiManagementVirtualNetwork) )
#### New-AzApplicationGateway
Creates an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGateway) )
#### New-AzApplicationGatewayAuthenticationCertificate
Creates an authentication certificate for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayAuthenticationCertificate) )
#### New-AzApplicationGatewayAutoscaleConfiguration
Creates a Autoscale Configuration for the Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayAutoscaleConfiguration) )
#### New-AzApplicationGatewayBackendAddressPool
Creates a back-end address pool for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayBackendAddressPool) )
#### New-AzApplicationGatewayBackendHttpSetting
Creates back-end HTTP setting for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayBackendHttpSetting) )
#### New-AzApplicationGatewayConnectionDraining
Creates a new connection draining configuration for back-end HTTP settings.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayConnectionDraining) )
#### New-AzApplicationGatewayCustomError
Creates a custom error with http status code and custom error page url(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayCustomError) )
#### New-AzApplicationGatewayFirewallCondition
Creates a match condition for custom rule(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFirewallCondition) )
#### New-AzApplicationGatewayFirewallCustomRule
Creates a new custom rule for the application gateway firewall policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFirewallCustomRule) )
#### New-AzApplicationGatewayFirewallDisabledRuleGroupConfig
Creates a new disabled rule group configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFirewallDisabledRuleGroupConfig) )
#### New-AzApplicationGatewayFirewallExclusionConfig
Creates a new exclusion rule list for application gateway waf(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFirewallExclusionConfig) )
#### New-AzApplicationGatewayFirewallMatchVariable
Creates a match variable for firewall condition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFirewallMatchVariable) )
#### New-AzApplicationGatewayFirewallPolicy
Creates a application gateway firewall policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFirewallPolicy) )
#### New-AzApplicationGatewayFrontendIPConfig
Creates a front-end IP configuration for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFrontendIPConfig) )
#### New-AzApplicationGatewayFrontendPort
Creates a front-end port for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayFrontendPort) )
#### New-AzApplicationGatewayHttpListener
Creates an HTTP listener for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayHttpListener) )
#### New-AzApplicationGatewayIdentity
Creates an identity object for an application gateway. This will hold reference to the user assigned identity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayIdentity) )
#### New-AzApplicationGatewayIPConfiguration
Creates an IP configuration for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayIPConfiguration) )
#### New-AzApplicationGatewayPathRuleConfig
Creates an application gateway path rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayPathRuleConfig) )
#### New-AzApplicationGatewayProbeConfig
Creates a health probe.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayProbeConfig) )
#### New-AzApplicationGatewayProbeHealthResponseMatch
Creates a health probe response match used by Health Probe for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayProbeHealthResponseMatch) )
#### New-AzApplicationGatewayRedirectConfiguration
Creates a redirect configuration for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRedirectConfiguration) )
#### New-AzApplicationGatewayRequestRoutingRule
Creates a request routing rule for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRequestRoutingRule) )
#### New-AzApplicationGatewayRewriteRule
Creates a rewrite rule for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRewriteRule) )
#### New-AzApplicationGatewayRewriteRuleActionSet
Creates a rewrite rule actionset for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRewriteRuleActionSet) )
#### New-AzApplicationGatewayRewriteRuleCondition
Adds a condition to the RewriteRule for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRewriteRuleCondition) )
#### New-AzApplicationGatewayRewriteRuleHeaderConfiguration
Creates a rewrite rule header configuration for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRewriteRuleHeaderConfiguration) )
#### New-AzApplicationGatewayRewriteRuleSet
Creates a request routing rule for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayRewriteRuleSet) )
#### New-AzApplicationGatewaySku
Creates a SKU for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewaySku) )
#### New-AzApplicationGatewaySslCertificate
Creates an SSL certificate for an Azure application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewaySslCertificate) )
#### New-AzApplicationGatewaySslPolicy
Creates an SSL policy for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewaySslPolicy) )
#### New-AzApplicationGatewayTrustedRootCertificate
Creates a Trusted Root Certificate for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayTrustedRootCertificate) )
#### New-AzApplicationGatewayUrlPathMapConfig
Creates an array of URL path mappings to a backend server pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayUrlPathMapConfig) )
#### New-AzApplicationGatewayWebApplicationFirewallConfiguration
Creates a WAF configuration for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationGatewayWebApplicationFirewallConfiguration) )
#### New-AzApplicationInsights
Create a new application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/New-AzApplicationInsights) )
#### New-AzApplicationInsightsApiKey
Create an application insights api key for an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/New-AzApplicationInsightsApiKey) )
#### New-AzApplicationInsightsContinuousExport
Create a new application insights continuous export configuration for an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/New-AzApplicationInsightsContinuousExport) )
#### New-AzApplicationSecurityGroup
Creates an application security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzApplicationSecurityGroup) )
#### New-AzAppServicePlan
Creates an Azure App Service plan in a given Geo location.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzAppServicePlan) )
#### New-AzAttestation
Creates an attestation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.attestation/New-AzAttestation) )
#### New-AzAutomationAccount
Creates an Automation account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationAccount) )
#### New-AzAutomationCertificate
Creates an Automation certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationCertificate) )
#### New-AzAutomationConnection
Creates an Automation connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationConnection) )
#### New-AzAutomationCredential
Creates an Automation credential.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationCredential) )
#### New-AzAutomationKey
Regenerates registration keys for an Automation account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationKey) )
#### New-AzAutomationModule
Imports a module into Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationModule) )
#### New-AzAutomationRunbook
Creates an Automation runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationRunbook) )
#### New-AzAutomationSchedule
Creates an Automation schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationSchedule) )
#### New-AzAutomationSoftwareUpdateConfiguration
Creates a scheduled azure automation software update configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationSoftwareUpdateConfiguration) )
#### New-AzAutomationSourceControl
Creates an A Automation source control.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationSourceControl) )
#### New-AzAutomationVariable
Creates an Automation variable.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationVariable) )
#### New-AzAutomationWebhook
Creates a webhook for an Automation runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/New-AzAutomationWebhook) )
#### New-AzAvailabilitySet
Creates an Azure availability set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzAvailabilitySet) [3.1b.02](#31b02))
#### New-AzBatchAccount
Creates a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchAccount) )
#### New-AzBatchAccountKey
Regenerates a key of a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchAccountKey) )
#### New-AzBatchApplication
Adds an application to the specified Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchApplication) )
#### New-AzBatchApplicationPackage
Creates an application package in a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchApplicationPackage) )
#### New-AzBatchCertificate
Adds a certificate to the specified Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchCertificate) )
#### New-AzBatchComputeNodeUser
Creates a user account on a Batch compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchComputeNodeUser) )
#### New-AzBatchJob
Creates a job in the Batch service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchJob) )
#### New-AzBatchJobSchedule
Creates a job schedule in the Batch service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchJobSchedule) )
#### New-AzBatchPool
Creates a pool in the Batch service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchPool) )
#### New-AzBatchTask
Creates a Batch task under a job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/New-AzBatchTask) )
#### New-AzBlueprint
Create a new blueprint definition and save it within the specified subscription or management group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/New-AzBlueprint) )
#### New-AzBlueprintArtifact
Create a new artifact and save it within a blueprint definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/New-AzBlueprintArtifact) )
#### New-AzBlueprintAssignment
Assign a blueprint definition to a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/New-AzBlueprintAssignment) )
#### New-AzCdnCustomDomain
Creates a custom domain for a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnCustomDomain) )
#### New-AzCdnDeliveryPolicy
Creates a deliveryPolicy for a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnDeliveryPolicy) )
#### New-AzCdnDeliveryRule
Creates a deliveryRule for deliveryPolicy creation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnDeliveryRule) )
#### New-AzCdnDeliveryRuleAction
Creates a deliveryRuleAction for deliveryRule creation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnDeliveryRuleAction) )
#### New-AzCdnDeliveryRuleCondition
Creates a deliveryRuleCondition for deliveryRule creation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnDeliveryRuleCondition) )
#### New-AzCdnEndpoint
Creates a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnEndpoint) )
#### New-AzCdnProfile
Creates a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/New-AzCdnProfile) )
#### New-AzCognitiveServicesAccount
Creates a Cognitive Services account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/New-AzCognitiveServicesAccount) )
#### New-AzCognitiveServicesAccountKey
Regenerates an account key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/New-AzCognitiveServicesAccountKey) )
#### New-AzConsumptionBudget
Create a budget in either a subscription or a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/New-AzConsumptionBudget) )
#### New-AzContainerGroup
Creates a container group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerinstance/New-AzContainerGroup) )
#### New-AzContainerNicConfig
Creates a new container network interface configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzContainerNicConfig) )
#### New-AzContainerNicConfigIpConfig
Creates a container nic configuration ip configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzContainerNicConfigIpConfig) )
#### New-AzContainerRegistry
Creates a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/New-AzContainerRegistry) )
#### New-AzContainerRegistryReplication
Creates a container registry replication.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/New-AzContainerRegistryReplication) )
#### New-AzContainerRegistryWebhook
Creates a container registry webhook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/New-AzContainerRegistryWebhook) )
#### New-AzContainerService
Creates a container service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzContainerService) )
#### New-AzContainerServiceConfig
Creates a local configuration object for a container service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzContainerServiceConfig) )
#### New-AzDataBoxJob
Creates a new databox job using the specified parameters(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.databox/New-AzDataBoxJob) )
#### New-AzDataFactory
Creates a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactory) )
#### New-AzDataFactoryDataset
Creates a dataset in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryDataset) )
#### New-AzDataFactoryEncryptValue
Encrypts sensitive data.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryEncryptValue) )
#### New-AzDataFactoryGateway
Creates a gateway for an Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryGateway) )
#### New-AzDataFactoryGatewayAuthKey
Creates auth key for an Azure Data Factory Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryGatewayAuthKey) )
#### New-AzDataFactoryHub
Creates a hub for an Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryHub) )
#### New-AzDataFactoryLinkedService
Links a data store or a cloud service to an Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryLinkedService) )
#### New-AzDataFactoryPipeline
Creates a pipeline in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryPipeline) )
#### New-AzDataFactoryV2IntegrationRuntimeKey
Regenerate self-hosted integration runtime key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryV2IntegrationRuntimeKey) )
#### New-AzDataFactoryV2LinkedServiceEncryptedCredential
Encrypt credential in linked service with specified integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/New-AzDataFactoryV2LinkedServiceEncryptedCredential) )
#### New-AzDataLakeAnalyticsAccount
Creates a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/New-AzDataLakeAnalyticsAccount) )
#### New-AzDataLakeAnalyticsCatalogCredential
Creates a new Azure Data Lake Analytics catalog credential.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/New-AzDataLakeAnalyticsCatalogCredential) )
#### New-AzDataLakeAnalyticsComputePolicy
Creates a Data Lake Analytics compute policy rule for a specific AAD entity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/New-AzDataLakeAnalyticsComputePolicy) )
#### New-AzDataLakeStoreAccount
Creates a new Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/New-AzDataLakeStoreAccount) )
#### New-AzDataLakeStoreItem
Creates a new file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/New-AzDataLakeStoreItem) )
#### New-AzDataMigrationConnectionInfo
Creates a new Connection Info object specifying the server type and name for connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationConnectionInfo) )
#### New-AzDataMigrationDatabaseInfo
Creates the DatabaseInfo object for the Azure Database Migration Service, which specifies the database source for migration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationDatabaseInfo) )
#### New-AzDataMigrationFileShare
Creates the FileShare object for the Azure Database Migration Service, which specifies the local network share to take the source database backups to.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationFileShare) )
#### New-AzDataMigrationProject
Creates a new Azure Database Migration Service project.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationProject) )
#### New-AzDataMigrationSelectedDBObject
Creates a database input object that contains information about source and target databases for migration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationSelectedDBObject) )
#### New-AzDataMigrationService
Creates a new instance of the Azure Database Migration Service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationService) )
#### New-AzDataMigrationSyncSelectedDBObject
Creates a database info object specific to the sync scenario to be used for a migration task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationSyncSelectedDBObject) )
#### New-AzDataMigrationTask
Creates and starts a data migration task in the Azure Database Migration Service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/New-AzDataMigrationTask) )
#### New-AzDdosProtectionPlan
Creates a DDoS protection plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzDdosProtectionPlan) )
#### New-AzDelegation
Creates a service delegation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzDelegation) )
#### New-AzDeployment
Create a deployment(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzDeployment) )
#### New-AzDeploymentManagerArtifactSource
Creates an artifact source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/New-AzDeploymentManagerArtifactSource) )
#### New-AzDeploymentManagerService
Creates a service under the specified service topology.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/New-AzDeploymentManagerService) )
#### New-AzDeploymentManagerServiceTopology
Creates a service topology.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/New-AzDeploymentManagerServiceTopology) )
#### New-AzDeploymentManagerServiceUnit
Creates a service unit under the specified service and service topology.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/New-AzDeploymentManagerServiceUnit) )
#### New-AzDeploymentManagerStep
Creates a step.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/New-AzDeploymentManagerStep) )
#### New-AzDevSpacesController
Create a new Azure DevSpaces controller.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devspaces/New-AzDevSpacesController) )
#### New-AzDisk
Creates a managed disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzDisk) )
#### New-AzDiskConfig
Creates a configurable disk object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzDiskConfig) [3.3a.02](#33a02) [3.3a.02](#33a02))
#### New-AzDiskUpdateConfig
Creates a configurable disk update object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzDiskUpdateConfig) )
#### New-AzEventGridDomain
Creates a new Azure Event Grid Domain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/New-AzEventGridDomain) )
#### New-AzEventGridDomainKey
Regenerates the shared access key for an Azure Event Grid Domain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/New-AzEventGridDomainKey) )
#### New-AzEventGridDomainTopic
Creates a new Azure Event Grid Domain Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/New-AzEventGridDomainTopic) )
#### New-AzEventGridSubscription
Creates a new Azure Event Grid Event Subscription to a topic, Azure resource, Azure subscription or Resource Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/New-AzEventGridSubscription) )
#### New-AzEventGridTopic
Creates a new Azure Event Grid Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/New-AzEventGridTopic) )
#### New-AzEventGridTopicKey
Regenerates the shared access key for an Azure Event Grid Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/New-AzEventGridTopicKey) )
#### New-AzEventHub
Creates a new Event Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHub) )
#### New-AzEventHubAuthorizationRule
Creates a new Event Hubs authorization rule for namespace or eventhub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHubAuthorizationRule) )
#### New-AzEventHubAuthorizationRuleSASToken
Generates a SAS tolen for Azure eventhub authorization rule of namespace/eventhub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHubAuthorizationRuleSASToken) )
#### New-AzEventHubConsumerGroup
Creates a new consumer group for the specified Event Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHubConsumerGroup) )
#### New-AzEventHubGeoDRConfiguration
Creates an new Alias(Disaster Recovery configuration)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHubGeoDRConfiguration) )
#### New-AzEventHubKey
Creates a new primary or secondary key for the specified Event Hubs authorization rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHubKey) )
#### New-AzEventHubNamespace
Creates an Event Hubs namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/New-AzEventHubNamespace) )
#### New-AzExpressRouteCircuit
Creates an Azure express route circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzExpressRouteCircuit) )
#### New-AzExpressRouteCircuitAuthorization
Creates an ExpressRoute circuit authorization.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzExpressRouteCircuitAuthorization) )
#### New-AzExpressRouteCircuitPeeringConfig
Creates a new peering configuration to be added to an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzExpressRouteCircuitPeeringConfig) )
#### New-AzExpressRouteConnection
Creates an ExpressRoute connection that connects an ExpressRoute gateway to an on premise ExpressRoute circuit(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzExpressRouteConnection) )
#### New-AzExpressRouteGateway
Creates a Scalable ExpressRoute Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzExpressRouteGateway) )
#### New-AzExpressRoutePort
Creates an Azure ExpressRoutePort.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzExpressRoutePort) )
#### New-AzFirewall
Creates a new Firewall in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewall) )
#### New-AzFirewallApplicationRule
Creates a Firewall Application Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewallApplicationRule) )
#### New-AzFirewallApplicationRuleCollection
Creates a collection of Firewall application rules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewallApplicationRuleCollection) )
#### New-AzFirewallNatRule
Creates a Firewall NAT Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewallNatRule) )
#### New-AzFirewallNatRuleCollection
Creates a collection of Firewall NAT rules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewallNatRuleCollection) )
#### New-AzFirewallNetworkRule
Creates a Firewall Network Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewallNetworkRule) )
#### New-AzFirewallNetworkRuleCollection
Creates a Azure Firewall Network Collection of Network rules.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzFirewallNetworkRuleCollection) )
#### New-AzFrontDoor
Create a new Azure Front Door load balancer(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoor) )
#### New-AzFrontDoorBackendObject
Create a PSBackend object(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorBackendObject) )
#### New-AzFrontDoorBackendPoolObject
Create a PSBackendPool object for Front Door creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorBackendPoolObject) )
#### New-AzFrontDoorFrontendEndpointObject
Create a PSFrontendEndpoint Object for Front Door creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorFrontendEndpointObject) )
#### New-AzFrontDoorHealthProbeSettingObject
Create a PSHealthProbeSetting object for Front Door creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorHealthProbeSettingObject) )
#### New-AzFrontDoorLoadBalancingSettingObject
Create a PSLoadBalancingSetting object for Front Door creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorLoadBalancingSettingObject) )
#### New-AzFrontDoorRoutingRuleObject
Create a PSRoutingRuleObject for Front Door creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorRoutingRuleObject) )
#### New-AzFrontDoorWafCustomRuleObject
Create CustomRule Object for WAF policy creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorWafCustomRuleObject) )
#### New-AzFrontDoorWafManagedRuleObject
Create ManagedRule Object for WAF policy creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorWafManagedRuleObject) )
#### New-AzFrontDoorWafManagedRuleOverrideObject
Create managed rule override object(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorWafManagedRuleOverrideObject) )
#### New-AzFrontDoorWafMatchConditionObject
Create MatchCondition Object for WAF policy creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorWafMatchConditionObject) )
#### New-AzFrontDoorWafPolicy
Create WAF policy(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorWafPolicy) )
#### New-AzFrontDoorWafRuleGroupOverrideObject
Create RuleGroupOverride Object for WAF policy creation(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/New-AzFrontDoorWafRuleGroupOverrideObject) )
#### New-AzGallery
Create a gallery.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzGallery) )
#### New-AzGalleryImageDefinition
Create a gallery image definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzGalleryImageDefinition) )
#### New-AzGalleryImageVersion
Create a gallery image version.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzGalleryImageVersion) )
#### New-AzHDInsightCluster
Creates an Azure HDInsight cluster in the specified resource group for the current subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightCluster) )
#### New-AzHDInsightClusterConfig
Creates a non-persisted cluster configuration object that describes an Azure HDInsight cluster configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightClusterConfig) )
#### New-AzHDInsightHiveJobDefinition
Creates a Hive job object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightHiveJobDefinition) )
#### New-AzHDInsightMapReduceJobDefinition
Creates a MapReduce job object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightMapReduceJobDefinition) )
#### New-AzHDInsightPigJobDefinition
Creates a Pig job object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightPigJobDefinition) )
#### New-AzHDInsightSqoopJobDefinition
Creates a Sqoop job object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightSqoopJobDefinition) )
#### New-AzHDInsightStreamingMapReduceJobDefinition
Creates a Streaming MapReduce job object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/New-AzHDInsightStreamingMapReduceJobDefinition) )
#### New-AzImage
Creats an image.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzImage) [3.1a.05](#31a05))
#### New-AzImageConfig
Creates a configurable image object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzImageConfig) [3.1a.05](#31a05))
#### New-AzIntegrationAccount
Creates an integration account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccount) )
#### New-AzIntegrationAccountAgreement
Creates an integration account agreement.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountAgreement) )
#### New-AzIntegrationAccountAssembly
Creates an integration account assembly.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountAssembly) )
#### New-AzIntegrationAccountBatchConfiguration
Creates an integration account batch configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountBatchConfiguration) )
#### New-AzIntegrationAccountCertificate
Creates an integration account certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountCertificate) )
#### New-AzIntegrationAccountMap
Creates an integration account map.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountMap) )
#### New-AzIntegrationAccountPartner
Creates an integration account partner.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountPartner) )
#### New-AzIntegrationAccountSchema
Creates an integration account schema.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzIntegrationAccountSchema) )
#### New-AzIoTDeviceProvisioningService
Create an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/New-AzIoTDeviceProvisioningService) )
#### New-AzIoTDeviceProvisioningServiceCertificateVerificationCode
Generate a verification code for an Azure IoT Hub Device Provisioning Service certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/New-AzIoTDeviceProvisioningServiceCertificateVerificationCode) )
#### New-AzIotHub
Creates a new IotHub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/New-AzIotHub) )
#### New-AzIotHubExportDevice
Creates a new export devices job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/New-AzIotHubExportDevice) )
#### New-AzIotHubImportDevice
Creates a new import devices job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/New-AzIotHubImportDevice) )
#### New-AzIotHubKey
Generate an Azure IoT Hub key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/New-AzIotHubKey) )
#### New-AzIpsecPolicy
Creates an IPSec Policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzIpsecPolicy) )
#### New-AzKeyVault
Creates a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/New-AzKeyVault) [2.1c.02](#21c02))
#### New-AzKeyVaultCertificateAdministratorDetail
Creates an in-memory certificate administrator details object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/New-AzKeyVaultCertificateAdministratorDetail) )
#### New-AzKeyVaultCertificateOrganizationDetail
Creates an in-memory certificate organization details object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/New-AzKeyVaultCertificateOrganizationDetail) )
#### New-AzKeyVaultCertificatePolicy
Creates an in-memory certificate policy object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/New-AzKeyVaultCertificatePolicy) )
#### New-AzKustoCluster
Creates a new Kusto cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/New-AzKustoCluster) )
#### New-AzKustoDatabase
Creates a new Kusto database in an existing cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/New-AzKustoDatabase) )
#### New-AzLoadBalancer
Creates a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancer) [3.1h.02](#31h02) [4.5a.02](#45a02))
#### New-AzLoadBalancerBackendAddressPoolConfig
Creates a backend address pool configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerBackendAddressPoolConfig) [3.1h.02](#31h02) [4.5a.02](#45a02))
#### New-AzLoadBalancerFrontendIpConfig
Creates a front-end IP configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerFrontendIpConfig) [3.1h.02](#31h02) [4.5a.02](#45a02))
#### New-AzLoadBalancerInboundNatPoolConfig
Creates an inbound NAT pool configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerInboundNatPoolConfig) )
#### New-AzLoadBalancerInboundNatRuleConfig
Creates an inbound NAT rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerInboundNatRuleConfig) )
#### New-AzLoadBalancerOutboundRuleConfig
Creates an outbound rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerOutboundRuleConfig) )
#### New-AzLoadBalancerProbeConfig
Creates a probe configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerProbeConfig) [4.5a.02](#45a02))
#### New-AzLoadBalancerRuleConfig
Creates a rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLoadBalancerRuleConfig) [4.5a.02](#45a02))
#### New-AzLocalNetworkGateway
Creates a Local Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzLocalNetworkGateway) [4.7b.02](#47b02))
#### New-AzLogicApp
Creates a logic app in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/New-AzLogicApp) )
#### New-AzManagedApplication
Creates an Azure managed application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzManagedApplication) )
#### New-AzManagedApplicationDefinition
Creates a managed application definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzManagedApplicationDefinition) )
#### New-AzManagedServicesAssignment
Creates a registration assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedservices/New-AzManagedServicesAssignment) )
#### New-AzManagedServicesDefinition
Creates a registration definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedservices/New-AzManagedServicesDefinition) )
#### New-AzManagementGroup
Creates a Management Group(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzManagementGroup) )
#### New-AzManagementGroupSubscription
Adds a Subscription to a Management Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzManagementGroupSubscription) )
#### New-AzManagementPartner
Associates a Microsoft Partner Network(MPN) ID to the current authenticated user or service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managementpartner/New-AzManagementPartner) )
#### New-AzMapsAccount
Creates an Azure Maps account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.maps/New-AzMapsAccount) )
#### New-AzMapsAccountKey
Regenerates an account key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.maps/New-AzMapsAccountKey) )
#### New-AzMediaService
Creates a media service if the media service already exists, all its properties are updated with the input provided.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/New-AzMediaService) )
#### New-AzMediaServiceStorageConfig
Create a storage account configuration for the media service cmdlets.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/New-AzMediaServiceStorageConfig) )
#### New-AzMlCommitmentPlan
Creates a new commitment plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/New-AzMlCommitmentPlan) )
#### New-AzMlOpCluster
Creates a new operationalization cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/New-AzMlOpCluster) )
#### New-AzMlWebService
Creates a new web service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/New-AzMlWebService) )
#### New-AzNatGateway
Create new Nat Gateway resource with properties Public Ip Address/Public Ip Prefix, IdleTimeoutInMinutes and Sku.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNatGateway) )
#### New-AzNetAppFilesAccount
Creates a new Azure NetApp Files (ANF) account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/New-AzNetAppFilesAccount) )
#### New-AzNetAppFilesPool
Creates a new Azure NetApp Files (ANF) pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/New-AzNetAppFilesPool) )
#### New-AzNetAppFilesSnapshot
Creates a new Azure NetApp Files (ANF) snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/New-AzNetAppFilesSnapshot) )
#### New-AzNetAppFilesVolume
Creates a new Azure NetApp Files (ANF) volume.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/New-AzNetAppFilesVolume) )
#### New-AzNetworkInterface
Creates a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkInterface) [3.1a.02](#31a02) [3.3b.02](#33b02))
#### New-AzNetworkInterfaceIpConfig
Creates a network interface IP configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkInterfaceIpConfig) )
#### New-AzNetworkProfile
Creates a new network profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkProfile) )
#### New-AzNetworkSecurityGroup
Creates a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkSecurityGroup) [3.1a.02](#31a02))
#### New-AzNetworkSecurityRuleConfig
Creates a network security rule configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkSecurityRuleConfig) [3.1a.02](#31a02))
#### New-AzNetworkWatcher
Creates a new Network Watcher resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkWatcher) )
#### New-AzNetworkWatcherConnectionMonitor
Creates a connection monitor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkWatcherConnectionMonitor) )
#### New-AzNetworkWatcherNetworkConfigurationDiagnosticProfile
Creates a new network configuration diagnostic profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkWatcherNetworkConfigurationDiagnosticProfile) )
#### New-AzNetworkWatcherPacketCapture
Creates a new packet capture resource and starts a packet capture session on a VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkWatcherPacketCapture) [4.6c.10](#46c10))
#### New-AzNetworkWatcherProtocolConfiguration
Creates a new protocol configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzNetworkWatcherProtocolConfiguration) )
#### New-AzNotificationHub
Creates a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/New-AzNotificationHub) )
#### New-AzNotificationHubAuthorizationRule
Creates an authorization rule and assigns the rule to a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/New-AzNotificationHubAuthorizationRule) )
#### New-AzNotificationHubKey
Regenerate the Authorization Rule Key for a NotificationHub .(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/New-AzNotificationHubKey) )
#### New-AzNotificationHubsNamespace
Creates a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/New-AzNotificationHubsNamespace) )
#### New-AzNotificationHubsNamespaceAuthorizationRule
Creates an authorization rule and assigns that rule to a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/New-AzNotificationHubsNamespaceAuthorizationRule) )
#### New-AzNotificationHubsNamespaceKey
Regenerate the Authorization Rule Key for a Namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/New-AzNotificationHubsNamespaceKey) )
#### New-AzOperationalInsightsApplicationInsightsDataSource
Collect logs from given Application-Insights application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsApplicationInsightsDataSource) )
#### New-AzOperationalInsightsAzureActivityLogDataSource
Collect Azure Activity log from given subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsAzureActivityLogDataSource) )
#### New-AzOperationalInsightsComputerGroup
Creates a computer group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsComputerGroup) )
#### New-AzOperationalInsightsCustomLogDataSource
Defines a custom log collection policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsCustomLogDataSource) )
#### New-AzOperationalInsightsLinuxPerformanceObjectDataSource
Adds performance counters to all Linux computers in a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsLinuxPerformanceObjectDataSource) )
#### New-AzOperationalInsightsLinuxSyslogDataSource
Adds a data source to Linux computers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsLinuxSyslogDataSource) )
#### New-AzOperationalInsightsSavedSearch
Creates a new saved search with the specified parameters.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsSavedSearch) )
#### New-AzOperationalInsightsStorageInsight
Creates a Storage Insight inside a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsStorageInsight) )
#### New-AzOperationalInsightsWindowsEventDataSource
Collects event logs from computers that run the Windows operating system.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsWindowsEventDataSource) )
#### New-AzOperationalInsightsWindowsPerformanceCounterDataSource
Adds Windows performance counter data source for connected computers that run the Windows operating system.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsWindowsPerformanceCounterDataSource) )
#### New-AzOperationalInsightsWorkspace
Creates a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/New-AzOperationalInsightsWorkspace) )
#### New-AzPacketCaptureFilterConfig
Creates a new packet capture filter object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPacketCaptureFilterConfig) [4.6c.10](#46c10))
#### New-AzPeerAsn
Creates a new Peer ASN(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/New-AzPeerAsn) )
#### New-AzPeering
Creates a new Peering ARM Resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/New-AzPeering) )
#### New-AzPeeringDirectConnectionObject
Creates a in memory PSObject to be used for creating or modifying a Peering.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/New-AzPeeringDirectConnectionObject) )
#### New-AzPeeringExchangeConnectionObject
Creates a in memory PSObject to be used for creating or modifying a Peering.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/New-AzPeeringExchangeConnectionObject) )
#### New-AzPolicyAssignment
Creates a policy assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzPolicyAssignment) )
#### New-AzPolicyDefinition
Creates a policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzPolicyDefinition) )
#### New-AzPolicySetDefinition
Creates a policy set definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzPolicySetDefinition) )
#### New-AzPowerBIEmbeddedCapacity
Creates a new PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/New-AzPowerBIEmbeddedCapacity) )
#### New-AzPowerBIWorkspaceCollection
Creates a Power BI workspace collection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/New-AzPowerBIWorkspaceCollection) )
#### New-AzPrivateDnsRecordConfig
Creates a new Private DNS record local object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/New-AzPrivateDnsRecordConfig) )
#### New-AzPrivateDnsRecordSet
Creates a record set in a Private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/New-AzPrivateDnsRecordSet) )
#### New-AzPrivateDnsVirtualNetworkLink
Creates a new private DNS virtual network link.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/New-AzPrivateDnsVirtualNetworkLink) )
#### New-AzPrivateDnsZone
Creates a new private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/New-AzPrivateDnsZone) )
#### New-AzPrivateEndpoint
Creates a private endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPrivateEndpoint) )
#### New-AzPrivateLinkService
Creates a private link service(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPrivateLinkService) )
#### New-AzPrivateLinkServiceConnection
Creates a private link service connection configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPrivateLinkServiceConnection) )
#### New-AzPrivateLinkServiceIpConfig
Create a private link service ip configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPrivateLinkServiceIpConfig) )
#### New-AzProximityPlacementGroup
Create Proximity Placement Group resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzProximityPlacementGroup) )
#### New-AzPublicIpAddress
Creates a public IP address.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPublicIpAddress) [3.1a.02](#31a02) [3.1h.02](#31h02) [4.2b.02](#42b02) [4.5a.02](#45a02) [4.7a.02](#47a02))
#### New-AzPublicIpPrefix
Creates a Public IP Prefix(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPublicIpPrefix) )
#### New-AzPublicIpTag
Creates an IP Tag.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzPublicIpTag) )
#### New-AzRecoveryServicesAsrAzureToAzureDiskReplicationConfig
Creates a disk mapping object for Azure virtual machine disks to be replicated.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrAzureToAzureDiskReplicationConfig) )
#### New-AzRecoveryServicesAsrFabric
Creates an Azure Site Recovery Fabric.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrFabric) )
#### New-AzRecoveryServicesAsrNetworkMapping
Creates an ASR network mapping between two networks.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrNetworkMapping) )
#### New-AzRecoveryServicesAsrPolicy
Creates an Azure Site Recovery replication policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrPolicy) )
#### New-AzRecoveryServicesAsrProtectableItem
Add(Discover) a physical server to the list of protectable items.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrProtectableItem) )
#### New-AzRecoveryServicesAsrProtectionContainer
Creates an Azure Site Recovery Protection Container within the specified fabric.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrProtectionContainer) )
#### New-AzRecoveryServicesAsrProtectionContainerMapping
Creates an Azure Site Recovery Protection Container mapping by associating the specified replication policy to the specified ASR protection container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrProtectionContainerMapping) )
#### New-AzRecoveryServicesAsrRecoveryPlan
Creates an ASR recovery plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrRecoveryPlan) )
#### New-AzRecoveryServicesAsrReplicationProtectedItem
Enables replication for an ASR protectable item by creating a replication protected item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrReplicationProtectedItem) )
#### New-AzRecoveryServicesAsrStorageClassificationMapping
Creates an ASR storage classification mapping in the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrStorageClassificationMapping) )
#### New-AzRecoveryServicesAsrvCenter
Adds a vCenter server to discover protectable items from.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesAsrvCenter) )
#### New-AzRecoveryServicesBackupProtectionPolicy
Creates a Backup protection policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesBackupProtectionPolicy) )
#### New-AzRecoveryServicesVault
Creates a new Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/New-AzRecoveryServicesVault) )
#### New-AzRedisCache
Creates a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/New-AzRedisCache) )
#### New-AzRedisCacheFirewallRule
Create a firewall rule on a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/New-AzRedisCacheFirewallRule) )
#### New-AzRedisCacheKey
Regenerates the access key of a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/New-AzRedisCacheKey) )
#### New-AzRedisCacheLink
Create a geo replication link between two Redis Caches.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/New-AzRedisCacheLink) )
#### New-AzRedisCachePatchSchedule
Adds a patch schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/New-AzRedisCachePatchSchedule) )
#### New-AzRedisCacheScheduleEntry
Creates a schedule entry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/New-AzRedisCacheScheduleEntry) )
#### New-AzRelayAuthorizationRule
Creates a new authorization rule for the specified Relay entities (Namespace/WcfRelay/HybridConnection).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/New-AzRelayAuthorizationRule) )
#### New-AzRelayHybridConnection
Creates a HybridConnection in the specified Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/New-AzRelayHybridConnection) )
#### New-AzRelayKey
Regenerates the primary or secondary connection strings for the given Relay entities (Namespace/WcfRelay/HybridConnection)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/New-AzRelayKey) )
#### New-AzRelayNamespace
Creates a new Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/New-AzRelayNamespace) )
#### New-AzResource
Creates a resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzResource) )
#### New-AzResourceGroup
Creates an Azure resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzResourceGroup) [2.1a.02](#21a02) [3.1a.02](#31a02) [3.1a.02](#31a02) [3.1a.02](#31a02) [3.1h.02](#31h02))
#### New-AzResourceGroupDeployment
Adds an Azure deployment to a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzResourceGroupDeployment) [3.2c.02](#32c02) [3.2d.01](#32d01) [3.2e.05](#32e05))
#### New-AzResourceLock
Creates a resource lock.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzResourceLock) )
#### New-AzRmStorageContainer
Creates a Storage blob container(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzRmStorageContainer) )
#### New-AzRoleAssignment
Assigns the specified RBAC role to the specified principal, at the specified scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzRoleAssignment) [1.4c.06](#14c06) [1.4c.08](#14c08))
#### New-AzRoleDefinition
Creates a custom role in Azure RBAC.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzRoleDefinition) )
#### New-AzRouteConfig
Creates a route for a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzRouteConfig) )
#### New-AzRouteFilter
Creates a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzRouteFilter) )
#### New-AzRouteFilterRuleConfig
Creates a route filter rule for a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzRouteFilterRuleConfig) )
#### New-AzRouteTable
Creates a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzRouteTable) [4.1d.02](#41d02))
#### New-AzSearchAdminKey
Regenerates an admin key of the Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/New-AzSearchAdminKey) )
#### New-AzSearchQueryKey
Create a new query key for the Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/New-AzSearchQueryKey) )
#### New-AzSearchService
Creates an Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/New-AzSearchService) )
#### New-AzServiceBusAuthorizationRule
Creates a new authorization rule for the specified Service Bus given Namespace or Queue or Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusAuthorizationRule) )
#### New-AzServiceBusAuthorizationRuleSASToken
Generates a SAS tolen for Azure serviucebus authorization rule of namespace/queue/topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusAuthorizationRuleSASToken) )
#### New-AzServiceBusGeoDRConfiguration
Creates an new Alias(Disaster Recovery configuration)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusGeoDRConfiguration) )
#### New-AzServiceBusKey
Regenerates the primary or secondary connection strings for the Service Bus namespace or queue or topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusKey) )
#### New-AzServiceBusNamespace
Creates a new Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusNamespace) )
#### New-AzServiceBusQueue
Creates a Service Bus queue in the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusQueue) )
#### New-AzServiceBusRule
Creates a new rule for a given Subscription of Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusRule) )
#### New-AzServiceBusSubscription
Creates a subscription to the specified Service Bus topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusSubscription) )
#### New-AzServiceBusTopic
Creates a new Service Bus topic in the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/New-AzServiceBusTopic) )
#### New-AzServiceEndpointPolicy
Creates a service endpoint policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzServiceEndpointPolicy) )
#### New-AzServiceEndpointPolicyDefinition
Creates a service endpoint policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzServiceEndpointPolicyDefinition) )
#### New-AzServiceFabricCluster
This command uses certificates that you provide or system generated self-signed certificates to set up a new service fabric cluster. It can use a default template or a custom template that you provide. You have the option of specifying a folder to export the self-signed certificates to or fetching them later from the key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/New-AzServiceFabricCluster) )
#### New-AzSignalR
Create a SignalR service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.signalr/New-AzSignalR) )
#### New-AzSignalRKey
Regenerate an access key for a SignalR service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.signalr/New-AzSignalRKey) )
#### New-AzSnapshot
Creates a snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzSnapshot) )
#### New-AzSnapshotConfig
Creates a configurable snapshot object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzSnapshotConfig) )
#### New-AzSnapshotUpdateConfig
Creates a configurable snapshot update object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzSnapshotUpdateConfig) )
#### New-AzSpatialAnchorsAccount
Create a new Spatial Inelligence Account in certain Subscription, Resource Group and Region.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.mixedreality/New-AzSpatialAnchorsAccount) )
#### New-AzSpatialAnchorsAccountKey
Regenerate specified developer key of Spatial Anchors Account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.mixedreality/New-AzSpatialAnchorsAccountKey) )
#### New-AzSqlDatabase
Creates a database or an elastic database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabase) )
#### New-AzSqlDatabaseCopy
Creates a copy of a SQL Database that uses the snapshot at the current time.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseCopy) )
#### New-AzSqlDatabaseDataMaskingRule
Creates a data masking rule for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseDataMaskingRule) )
#### New-AzSqlDatabaseExport
Exports an Azure SQL Database as a .bacpac file to a storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseExport) )
#### New-AzSqlDatabaseFailoverGroup
This command creates a new Azure SQL Database Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseFailoverGroup) )
#### New-AzSqlDatabaseImport
Imports a .bacpac file and create a new database on the server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseImport) )
#### New-AzSqlDatabaseInstanceFailoverGroup
This command creates a new Azure SQL Database Instance Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseInstanceFailoverGroup) )
#### New-AzSqlDatabaseRestorePoint
Creates a new restore point from which a SQL Database can be restored.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseRestorePoint) )
#### New-AzSqlDatabaseSecondary
Creates a secondary database for an existing database and starts data replication.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlDatabaseSecondary) )
#### New-AzSqlElasticPool
Creates an elastic database pool for a SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlElasticPool) )
#### New-AzSqlInstance
Creates an Azure SQL Database Managed Instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlInstance) )
#### New-AzSqlInstanceDatabase
Creates an Azure SQL Managed Instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlInstanceDatabase) )
#### New-AzSqlServer
Creates a SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlServer) )
#### New-AzSqlServerCommunicationLink
Creates a communication link for elastic database transactions between two SQL Database servers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlServerCommunicationLink) )
#### New-AzSqlServerDisasterRecoveryConfiguration
Creates a database server system recovery configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlServerDisasterRecoveryConfiguration) )
#### New-AzSqlServerDnsAlias
This command creates a new Azure SQL Server DNS Alias.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlServerDnsAlias) )
#### New-AzSqlServerFirewallRule
Creates a firewall rule for a SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlServerFirewallRule) )
#### New-AzSqlServerVirtualNetworkRule
Creates an Azure SQL Server Virtual Network Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlServerVirtualNetworkRule) )
#### New-AzSqlSyncAgent
Creates an Azure SQL Sync Agent.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlSyncAgent) )
#### New-AzSqlSyncAgentKey
Creates an Azure SQL Sync Agent Key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlSyncAgentKey) )
#### New-AzSqlSyncGroup
Creates an Azure SQL Database Sync Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlSyncGroup) )
#### New-AzSqlSyncMember
Creates an Azure SQL Database Sync Member.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/New-AzSqlSyncMember) )
#### New-AzStorageAccount
Creates a Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageAccount) [2.1a.02](#21a02) [4.6d.02](#46d02))
#### New-AzStorageAccountKey
Regenerates a storage key for an Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageAccountKey) )
#### New-AzStorageAccountManagementPolicyFilter
Creates a ManagementPolicy rule filter object, which can be used in New-AzStorageAccountManagementPolicyRule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageAccountManagementPolicyFilter) )
#### New-AzStorageAccountManagementPolicyRule
Creates a ManagementPolicy rule object, which can be used in Set-AzStorageAccountManagementPolicy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageAccountManagementPolicyRule) )
#### New-AzStorageAccountSASToken
Creates an account-level SAS token.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageAccountSASToken) )
#### New-AzStorageBlobSASToken
Generates a SAS token for an Azure storage blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageBlobSASToken) [2.1d.01](#21d01))
#### New-AzStorageContainer
Creates an Azure storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageContainer) [2.1f.02](#21f02) [2.2a.01](#22a01) [4.6d.02](#46d02))
#### New-AzStorageContainerSASToken
Generates an SAS token for an Azure storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageContainerSASToken) )
#### New-AzStorageContainerStoredAccessPolicy
Creates a stored access policy for an Azure storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageContainerStoredAccessPolicy) )
#### New-AzStorageContext
Creates an Azure Storage context.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageContext) [2.1d.01](#21d01) [2.1f.02](#21f02) [2.2a.01](#22a01) [2.3a.02](#23a02))
#### New-AzStorageDirectory
Creates a directory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageDirectory) )
#### New-AzStorageFileSASToken
Generates a shared access signature token for a Storage file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageFileSASToken) )
#### New-AzStorageQueue
Creates a storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageQueue) )
#### New-AzStorageQueueSASToken
Generates a shared access signature token for an Azure storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageQueueSASToken) )
#### New-AzStorageQueueStoredAccessPolicy
Creates a stored access policy for an Azure storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageQueueStoredAccessPolicy) )
#### New-AzStorageShare
Creates a file share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageShare) [2.3a.02](#23a02))
#### New-AzStorageShareSASToken
Generate Shared Access Signature token for Azure Storage share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageShareSASToken) )
#### New-AzStorageShareStoredAccessPolicy
Creates a stored access policy on a Storage share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageShareStoredAccessPolicy) )
#### New-AzStorageSyncCloudEndpoint
This command creates an Azure File Sync cloud endpoint in a sync group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/New-AzStorageSyncCloudEndpoint) )
#### New-AzStorageSyncGroup
This command creates a new sync group within a specified storage sync service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/New-AzStorageSyncGroup) )
#### New-AzStorageSyncServerEndpoint
This command creates a new server endpoint on a registered server. This enables the specified path on the server to start syncing the files with other endpoints in the sync group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/New-AzStorageSyncServerEndpoint) )
#### New-AzStorageSyncService
This command creates a new storage sync service in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/New-AzStorageSyncService) )
#### New-AzStorageTable
Creates a storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageTable) )
#### New-AzStorageTableSASToken
Generates an SAS token for an Azure Storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageTableSASToken) )
#### New-AzStorageTableStoredAccessPolicy
Creates a stored access policy for an Azure storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/New-AzStorageTableStoredAccessPolicy) )
#### New-AzStreamAnalyticsFunction
Creates or replaces a function in a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/New-AzStreamAnalyticsFunction) )
#### New-AzStreamAnalyticsInput
Creates or updates a job input.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/New-AzStreamAnalyticsInput) )
#### New-AzStreamAnalyticsJob
Creates or updates a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/New-AzStreamAnalyticsJob) )
#### New-AzStreamAnalyticsOutput
Creates or updates outputs for a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/New-AzStreamAnalyticsOutput) )
#### New-AzStreamAnalyticsTransformation
Creates or updates a transformation within a job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/New-AzStreamAnalyticsTransformation) )
#### New-AzSubscription
Creates an Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.subscription/New-AzSubscription) )
#### New-AzTag
Creates a predefined Azure tag or adds values to an existing tag.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/New-AzTag) )
#### New-AzTrafficManagerEndpoint
Creates an endpoint in a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/New-AzTrafficManagerEndpoint) )
#### New-AzTrafficManagerProfile
Creates a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/New-AzTrafficManagerProfile) )
#### New-AzUserAssignedIdentity
Creates a new User Assigned Identity or updates an existing User Assigned Identity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedserviceidentity/New-AzUserAssignedIdentity) )
#### New-AzVirtualHub
Creates an Azure VirtualHub resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualHub) )
#### New-AzVirtualHubRoute
Creates an Azure Virtual Hub Route object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualHubRoute) )
#### New-AzVirtualHubRouteTable
Creates an Azure Virtual Hub Route Table object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualHubRouteTable) )
#### New-AzVirtualHubVnetConnection
The New-AzVirtualHubVnetConnection cmdlet creates a HubVirtualNetworkConnection resource that peers a Virtual Network to the Azure Virtual Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualHubVnetConnection) )
#### New-AzVirtualNetwork
Creates a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualNetwork) [3.1a.02](#31a02) [3.1h.02](#31h02) [4.3b.02](#43b02))
#### New-AzVirtualNetworkGateway
Creates a Virtual Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualNetworkGateway) [4.2b.02](#42b02) [4.7a.02](#47a02))
#### New-AzVirtualNetworkGatewayConnection
Creates the Site-to-Site VPN connection between the virtual network gateway and the on-prem VPN device.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualNetworkGatewayConnection) [4.2b.02](#42b02) [4.7b.02](#47b02))
#### New-AzVirtualNetworkGatewayIpConfig
Creates an IP Configuration for a Virtual Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualNetworkGatewayIpConfig) [4.2b.02](#42b02) [4.7a.02](#47a02))
#### New-AzVirtualNetworkSubnetConfig
Creates a virtual network subnet configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualNetworkSubnetConfig) [3.1a.02](#31a02) [3.1h.02](#31h02) [4.2b.02](#42b02) [4.7a.02](#47a02))
#### New-AzVirtualNetworkTap
Creates a VirtualNetworkTap resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualNetworkTap) )
#### New-AzVirtualWan
Creates an Azure Virtual WAN.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVirtualWan) )
#### New-AzVM
Creates a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVM) )
#### New-AzVMConfig
Creates a configurable virtual machine object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVMConfig) [3.1a.02](#31a02))
#### New-AzVMDataDisk
Creates a local data disk object for a virtual machine or a Vmss VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVMDataDisk) )
#### New-AzVMSqlServerAutoBackupConfig
Creates a configuration object for SQL Server automatic backup.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVMSqlServerAutoBackupConfig) )
#### New-AzVMSqlServerAutoPatchingConfig
Creates a configuration object for automatic patching on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVMSqlServerAutoPatchingConfig) )
#### New-AzVMSqlServerKeyVaultCredentialConfig
Creates a configuration object for SQL server key vault credential on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVMSqlServerKeyVaultCredentialConfig) )
#### New-AzVmss
Creates a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVmss) [3.1h.02](#31h02))
#### New-AzVmssConfig
Creates a VMSS configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVmssConfig) )
#### New-AzVmssIpConfig
Creates an IP configuration for a network interface of a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVmssIpConfig) [3.1h.02](#31h02))
#### New-AzVmssIpTagConfig
Creates an IP Tag object for a network interface of a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVmssIpTagConfig) )
#### New-AzVmssVaultCertificateConfig
Creates a Key Vault certificate configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/New-AzVmssVaultCertificateConfig) )
#### New-AzVpnClientConfiguration
This command allows the users to create the Vpn profile package based on pre-configured vpn settings on the VPN gateway, in addition to some additional settings that users may need to configure, for e.g. some root certificates.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnClientConfiguration) )
#### New-AzVpnClientIpsecParameter
This command allows the users to create the Vpn ipsec parameters object specifying one or all values such as IpsecEncryption,IpsecIntegrity,IkeEncryption,IkeIntegrity,DhGroup,PfsGroup to set on the existing VPN gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnClientIpsecParameter) )
#### New-AzVpnClientIpsecPolicy
This command allows the users to create the Vpn ipsec policy object specifying one or all values such as IpsecEncryption,IpsecIntegrity,IkeEncryption,IkeIntegrity,DhGroup,PfsGroup to set on the VPN gateway. This command let output object is used to set vpn ipsec policy for both new / exisitng gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnClientIpsecPolicy) )
#### New-AzVpnClientRevokedCertificate
Creates a new VPN client-revocation certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnClientRevokedCertificate) )
#### New-AzVpnClientRootCertificate
Creates a new VPN client root certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnClientRootCertificate) )
#### New-AzVpnConnection
Creates a IPSec connection that connects a VpnGateway to a remote customer branch represented in RM as a VpnSite.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnConnection) )
#### New-AzVpnGateway
Creates a Scalable VPN Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnGateway) )
#### New-AzVpnSite
Creates a new Azure VpnSite resource. This is an RM representation of customer branches that are uploaded to Azure(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/New-AzVpnSite) )
#### New-AzWcfRelay
Creates a WcfRelay in the specified Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/New-AzWcfRelay) )
#### New-AzWebApp
Creates an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebApp) )
#### New-AzWebAppAzureStoragePath
Creates an object that represents an Azure Storage path to be mounted in a Web App. It is meant to be used as a parameter (-AzureStoragePath) to Set-AzWebApp and Set-AzWebAppSlot(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebAppAzureStoragePath) )
#### New-AzWebAppBackup
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebAppBackup) )
#### New-AzWebAppContainerPSSession
New-AzWebAppContainerPSSession will create new remote PowerShell Session into the windows container specified in a given site or slot and given resource group(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebAppContainerPSSession) )
#### New-AzWebAppDatabaseBackupSetting
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebAppDatabaseBackupSetting) )
#### New-AzWebAppSlot
Creates an Azure Web App slot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebAppSlot) )
#### New-AzWebAppSSLBinding
Creates an SSL certificate binding for an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/New-AzWebAppSSLBinding) )
#### Publish-AzApiManagementTenantGitConfiguration
Publishes changes from a Git branch to the configuration database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Publish-AzApiManagementTenantGitConfiguration) )
#### Publish-AzAutomationRunbook
Publishes a runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Publish-AzAutomationRunbook) )
#### Publish-AzBlueprint
Publish a new version of a blueprint definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Publish-AzBlueprint) )
#### Publish-AzCdnEndpointContent
Loads content to an endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Publish-AzCdnEndpointContent) )
#### Publish-AzVMDscConfiguration
Uploads a DSC script to Azure blob storage.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Publish-AzVMDscConfiguration) [3.3f.01](#33f01) [3.3f.03](#33f03))
#### Publish-AzWebApp
Deploys an Azure Web App from a ZIP, JAR, or WAR file using zipdeploy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Publish-AzWebApp) )
#### Register-AzAutomationDscNode
Registers an Azure virtual machine as a DSC node for an Automation account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Register-AzAutomationDscNode) )
#### Register-AzAutomationScheduledRunbook
Associates a runbook to a schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Register-AzAutomationScheduledRunbook) )
#### Register-AzModule
FOR INTERNAL USE ONLY - Provide RUntime Support for AutoRest Generated cmdlets.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Register-AzModule) )
#### Register-AzProviderFeature
Registers an Azure provider feature in your account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Register-AzProviderFeature) )
#### Register-AzRecoveryServicesBackupContainer
Registers a protectable container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Register-AzRecoveryServicesBackupContainer) )
#### Register-AzResourceProvider
Registers a resource provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Register-AzResourceProvider) [4.4c.03](#44c03))
#### Register-AzStorageSyncServer
This command registers a server to a storage sync service which creates a trust relationship. PowerShell or the Azure portal can then be used to configure sync on this server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Register-AzStorageSyncServer) )
#### Remove-AzActionRule
Deletes a action group(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Remove-AzActionRule) )
#### Remove-AzADAppCredential
Removes a credential from an application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADAppCredential) )
#### Remove-AzADApplication
Deletes the azure active directory application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADApplication) )
#### Remove-AzADGroup
Deletes an active directory group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADGroup) )
#### Remove-AzADGroupMember
Removes a user from an AD group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADGroupMember) )
#### Remove-AzADServicePrincipal
Deletes the azure active directory service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADServicePrincipal) )
#### Remove-AzADSpCredential
Removes a credential from a service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADSpCredential) )
#### Remove-AzADUser
Deletes an active directory user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzADUser) )
#### Remove-AzAks
Delete a managed Kubernetes cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/Remove-AzAks) )
#### Remove-AzAnalysisServicesServer
Deletes an instance of Analysis Services server(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Remove-AzAnalysisServicesServer) )
#### Remove-AzApiManagement
Removes an API Management service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagement) )
#### Remove-AzApiManagementApi
Removes an API.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementApi) )
#### Remove-AzApiManagementApiFromProduct
Removes an API from a product.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementApiFromProduct) )
#### Remove-AzApiManagementApiRelease
Removes a particular API Release(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementApiRelease) )
#### Remove-AzApiManagementApiRevision
Removed a particular API Revision(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementApiRevision) )
#### Remove-AzApiManagementApiSchema
Removes the API Schema from the API.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementApiSchema) )
#### Remove-AzApiManagementApiVersionSet
Removes a particular Api Version Set(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementApiVersionSet) )
#### Remove-AzApiManagementAuthorizationServer
Removes an authorization server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementAuthorizationServer) )
#### Remove-AzApiManagementBackend
Removes a Backend.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementBackend) )
#### Remove-AzApiManagementCache
Removes the cache entity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementCache) )
#### Remove-AzApiManagementCertificate
Removes an API Management certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementCertificate) )
#### Remove-AzApiManagementDiagnostic
Remove the Diagnostic entity from Global or API level scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementDiagnostic) )
#### Remove-AzApiManagementGroup
Removes an existing API management group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementGroup) )
#### Remove-AzApiManagementIdentityProvider
Removes an existing Identity Provider Configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementIdentityProvider) )
#### Remove-AzApiManagementLogger
Removes an API Management Logger.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementLogger) )
#### Remove-AzApiManagementOpenIdConnectProvider
Removes an OpenID Connect provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementOpenIdConnectProvider) )
#### Remove-AzApiManagementOperation
Removes an existing operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementOperation) )
#### Remove-AzApiManagementPolicy
Removes the API Management policy from a specified scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementPolicy) )
#### Remove-AzApiManagementProduct
Removes an existing API Management product.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementProduct) )
#### Remove-AzApiManagementProductFromGroup
Removes a product from a group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementProductFromGroup) )
#### Remove-AzApiManagementProperty
Removes an API Management Property.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementProperty) )
#### Remove-AzApiManagementRegion
Removes an existing deployment region from PsApiManagement instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementRegion) )
#### Remove-AzApiManagementSubscription
Deletes an existing subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementSubscription) )
#### Remove-AzApiManagementUser
Deletes an existing user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementUser) )
#### Remove-AzApiManagementUserFromGroup
Removes a user from a group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Remove-AzApiManagementUserFromGroup) )
#### Remove-AzApplicationGateway
Removes an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGateway) )
#### Remove-AzApplicationGatewayAuthenticationCertificate
Removes an authentication certificate from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayAuthenticationCertificate) )
#### Remove-AzApplicationGatewayAutoscaleConfiguration
Removes Autoscale Configuration from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayAutoscaleConfiguration) )
#### Remove-AzApplicationGatewayBackendAddressPool
Removes a back-end address pool from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayBackendAddressPool) )
#### Remove-AzApplicationGatewayBackendHttpSetting
Removes back-end HTTP settings from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayBackendHttpSetting) )
#### Remove-AzApplicationGatewayConnectionDraining
Removes the connection draining configuration of a back-end HTTP settings object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayConnectionDraining) )
#### Remove-AzApplicationGatewayCustomError
Removes a custom error from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayCustomError) )
#### Remove-AzApplicationGatewayFirewallPolicy
Removes an application gateway firewall policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayFirewallPolicy) )
#### Remove-AzApplicationGatewayFrontendIPConfig
Removes a front-end IP configuration from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayFrontendIPConfig) )
#### Remove-AzApplicationGatewayFrontendPort
Removes a front-end port from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayFrontendPort) )
#### Remove-AzApplicationGatewayHttpListener
Removes an HTTP listener from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayHttpListener) )
#### Remove-AzApplicationGatewayHttpListenerCustomError
Removes a custom error from a http listener of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayHttpListenerCustomError) )
#### Remove-AzApplicationGatewayIdentity
Removes a identity from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayIdentity) )
#### Remove-AzApplicationGatewayIPConfiguration
Removes an IP configuration from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayIPConfiguration) )
#### Remove-AzApplicationGatewayProbeConfig
Removes a health probe from an existing application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayProbeConfig) )
#### Remove-AzApplicationGatewayRedirectConfiguration
Removes a redirect configuration from an existing Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayRedirectConfiguration) )
#### Remove-AzApplicationGatewayRequestRoutingRule
Removes a request routing rule from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayRequestRoutingRule) )
#### Remove-AzApplicationGatewayRewriteRuleSet
Removes a rewrite rule set from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayRewriteRuleSet) )
#### Remove-AzApplicationGatewaySslCertificate
Removes an SSL certificate from an Azure application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewaySslCertificate) )
#### Remove-AzApplicationGatewaySslPolicy
Removes an SSL policy from an Azure application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewaySslPolicy) )
#### Remove-AzApplicationGatewayTrustedRootCertificate
Removes a Trusted Root Certificate from an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayTrustedRootCertificate) )
#### Remove-AzApplicationGatewayUrlPathMapConfig
Removes URL path mappings to a backend server pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationGatewayUrlPathMapConfig) )
#### Remove-AzApplicationInsights
Remove an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Remove-AzApplicationInsights) )
#### Remove-AzApplicationInsightsApiKey
Remove an application insights api key for an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Remove-AzApplicationInsightsApiKey) )
#### Remove-AzApplicationInsightsContinuousExport
Remove a cotinuous export configuration in an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Remove-AzApplicationInsightsContinuousExport) )
#### Remove-AzApplicationSecurityGroup
Removes an application security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzApplicationSecurityGroup) )
#### Remove-AzAppServicePlan
Removes an Azure App Service plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Remove-AzAppServicePlan) )
#### Remove-AzAttestation
Deletes an attestation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.attestation/Remove-AzAttestation) )
#### Remove-AzAutomationAccount
Removes an Automation account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationAccount) )
#### Remove-AzAutomationCertificate
Removes an Automation certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationCertificate) )
#### Remove-AzAutomationConnection
Removes an Automation connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationConnection) )
#### Remove-AzAutomationConnectionType
Removes an Automation connection type.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationConnectionType) )
#### Remove-AzAutomationCredential
Removes an Automation credential.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationCredential) )
#### Remove-AzAutomationDscConfiguration
Removes DSC configurations from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationDscConfiguration) )
#### Remove-AzAutomationDscNodeConfiguration
Removes metadata from DSC node configurations in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationDscNodeConfiguration) )
#### Remove-AzAutomationHybridWorkerGroup
Removes hybrid worker group from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationHybridWorkerGroup) )
#### Remove-AzAutomationModule
Removes a module from Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationModule) )
#### Remove-AzAutomationRunbook
Removes a runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationRunbook) )
#### Remove-AzAutomationSchedule
Deletes an Automation schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationSchedule) )
#### Remove-AzAutomationSoftwareUpdateConfiguration
Removes an azure automation software update configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationSoftwareUpdateConfiguration) )
#### Remove-AzAutomationSourceControl
Removes an Azure Automation source control.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationSourceControl) )
#### Remove-AzAutomationVariable
Removes an Automation variable.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationVariable) )
#### Remove-AzAutomationWebhook
Removes a webhook from an Automation runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Remove-AzAutomationWebhook) )
#### Remove-AzAvailabilitySet
Removes an availability set from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzAvailabilitySet) )
#### Remove-AzBatchAccount
Removes a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchAccount) )
#### Remove-AzBatchApplication
Deletes an application from a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchApplication) )
#### Remove-AzBatchApplicationPackage
Deletes an application package record and the binary file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchApplicationPackage) )
#### Remove-AzBatchCertificate
Deletes a certificate from an account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchCertificate) )
#### Remove-AzBatchComputeNode
Removes compute nodes from a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchComputeNode) )
#### Remove-AzBatchComputeNodeUser
Deletes a user account from a Batch compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchComputeNodeUser) )
#### Remove-AzBatchJob
Deletes a Batch job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchJob) )
#### Remove-AzBatchJobSchedule
Removes a Batch job schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchJobSchedule) )
#### Remove-AzBatchNodeFile
Deletes a node file for a task or compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchNodeFile) )
#### Remove-AzBatchPool
Deletes the specified Batch pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchPool) )
#### Remove-AzBatchTask
Deletes a Batch task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Remove-AzBatchTask) )
#### Remove-AzBlueprintAssignment
Remove a blueprint assignment from a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Remove-AzBlueprintAssignment) )
#### Remove-AzCdnCustomDomain
Removes a custom domain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Remove-AzCdnCustomDomain) )
#### Remove-AzCdnEndpoint
Removes a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Remove-AzCdnEndpoint) )
#### Remove-AzCdnProfile
Removes a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Remove-AzCdnProfile) )
#### Remove-AzCognitiveServicesAccount
Deletes a Cognitive Services account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Remove-AzCognitiveServicesAccount) )
#### Remove-AzCognitiveServicesAccountNetworkRule
Remove IpRules or VirtualNetworkRules from the NetWorkRule property of a Cognitive Services account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Remove-AzCognitiveServicesAccountNetworkRule) )
#### Remove-AzConsumptionBudget
Remove a budget in either a subscription or a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Remove-AzConsumptionBudget) )
#### Remove-AzContainerGroup
Removes a container group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Remove-AzContainerGroup) )
#### Remove-AzContainerRegistry
Removes a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Remove-AzContainerRegistry) )
#### Remove-AzContainerRegistryReplication
Removes a container registry replication.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Remove-AzContainerRegistryReplication) )
#### Remove-AzContainerRegistryWebhook
Removes a container registry webhook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Remove-AzContainerRegistryWebhook) )
#### Remove-AzContainerService
Removes a container service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzContainerService) )
#### Remove-AzContainerServiceAgentPoolProfile
Removes an agent pool profile from a container service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzContainerServiceAgentPoolProfile) )
#### Remove-AzContext
Remove a context from the set of available contexts(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Remove-AzContext) )
#### Remove-AzDataBoxJob
Deletes the databox job(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.databox/Remove-AzDataBoxJob) )
#### Remove-AzDataFactory
Removes a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactory) )
#### Remove-AzDataFactoryDataset
Removes a dataset from Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryDataset) )
#### Remove-AzDataFactoryGateway
Removes a gateway from Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryGateway) )
#### Remove-AzDataFactoryHub
Removes a hub from Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryHub) )
#### Remove-AzDataFactoryLinkedService
Removes a linked service from Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryLinkedService) )
#### Remove-AzDataFactoryPipeline
Removes a pipeline from Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryPipeline) )
#### Remove-AzDataFactoryV2
Removes a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2) )
#### Remove-AzDataFactoryV2Dataset
Removes a dataset from Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2Dataset) )
#### Remove-AzDataFactoryV2IntegrationRuntime
Removes an integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2IntegrationRuntime) )
#### Remove-AzDataFactoryV2IntegrationRuntimeNode
Remove a node with the given name on an integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2IntegrationRuntimeNode) )
#### Remove-AzDataFactoryV2LinkedService
Removes a linked service from Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2LinkedService) )
#### Remove-AzDataFactoryV2Pipeline
Removes a pipeline from Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2Pipeline) )
#### Remove-AzDataFactoryV2Trigger
Removes a trigger from a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Remove-AzDataFactoryV2Trigger) )
#### Remove-AzDataLakeAnalyticsAccount
Deletes a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Remove-AzDataLakeAnalyticsAccount) )
#### Remove-AzDataLakeAnalyticsCatalogCredential
Deletes an Azure Data Lake Analytics credential.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Remove-AzDataLakeAnalyticsCatalogCredential) )
#### Remove-AzDataLakeAnalyticsCatalogItemAclEntry
Deletes an entry from the ACL of a catalog or catalog item in Data Lake Analytics.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Remove-AzDataLakeAnalyticsCatalogItemAclEntry) )
#### Remove-AzDataLakeAnalyticsComputePolicy
Removes a specified Azure Data Lake Analytics compute policy(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Remove-AzDataLakeAnalyticsComputePolicy) )
#### Remove-AzDataLakeAnalyticsDataSource
Removes a data source from a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Remove-AzDataLakeAnalyticsDataSource) )
#### Remove-AzDataLakeAnalyticsFirewallRule
Removes a firewall rule from a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Remove-AzDataLakeAnalyticsFirewallRule) )
#### Remove-AzDataLakeStoreAccount
Deletes a Data Lake Store account permanently.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreAccount) )
#### Remove-AzDataLakeStoreFirewallRule
Removes the specified firewall rule in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreFirewallRule) )
#### Remove-AzDataLakeStoreItem
Deletes a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreItem) )
#### Remove-AzDataLakeStoreItemAcl
Clears the ACL of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreItemAcl) )
#### Remove-AzDataLakeStoreItemAclEntry
Removes an entry from the ACL of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreItemAclEntry) )
#### Remove-AzDataLakeStoreTrustedIdProvider
Removes the specified trusted identity provider in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreTrustedIdProvider) )
#### Remove-AzDataLakeStoreVirtualNetworkRule
Removes the specified virtual network rule in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Remove-AzDataLakeStoreVirtualNetworkRule) )
#### Remove-AzDataMigrationProject
Removes an Azure Database Migration Service project from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Remove-AzDataMigrationProject) )
#### Remove-AzDataMigrationService
Removes an instance of the Azure Database Migration Service from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Remove-AzDataMigrationService) )
#### Remove-AzDataMigrationTask
Removes an Azure Database Migration Service task from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Remove-AzDataMigrationTask) )
#### Remove-AzDdosProtectionPlan
Removes a DDoS protection plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzDdosProtectionPlan) )
#### Remove-AzDelegation
Removes a service delegation from the provided subnet.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzDelegation) )
#### Remove-AzDeployment
Removes a deployment and any associated operations(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzDeployment) )
#### Remove-AzDeploymentManagerArtifactSource
Deletes the specified artifact source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Remove-AzDeploymentManagerArtifactSource) )
#### Remove-AzDeploymentManagerRollout
Deletes the rollout.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Remove-AzDeploymentManagerRollout) )
#### Remove-AzDeploymentManagerService
Deletes the service.. All service units created under a service need to be deleted before deleting the service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Remove-AzDeploymentManagerService) )
#### Remove-AzDeploymentManagerServiceTopology
Deletes the service topology. All services created under a service topology need to be deleted before deleting the service topology.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Remove-AzDeploymentManagerServiceTopology) )
#### Remove-AzDeploymentManagerServiceUnit
Deletes the service unit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Remove-AzDeploymentManagerServiceUnit) )
#### Remove-AzDeploymentManagerStep
Deletes the step.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Remove-AzDeploymentManagerStep) )
#### Remove-AzDevSpacesController
Delete a DevSpaces controller.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devspaces/Remove-AzDevSpacesController) )
#### Remove-AzDisk
Removes a disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzDisk) )
#### Remove-AzEnvironment
Removes endpoints and metadata for connecting to a given Azure instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Remove-AzEnvironment) )
#### Remove-AzEventGridDomain
Removes an Azure Event Grid Domain.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Remove-AzEventGridDomain) )
#### Remove-AzEventGridDomainTopic
Removes an Azure Event Grid Domain Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Remove-AzEventGridDomainTopic) )
#### Remove-AzEventGridSubscription
Removes an Azure Event Grid event subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Remove-AzEventGridSubscription) )
#### Remove-AzEventGridTopic
Removes an Azure Event Grid Topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Remove-AzEventGridTopic) )
#### Remove-AzEventHub
Removes the specified Event Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHub) )
#### Remove-AzEventHubAuthorizationRule
Removes the specified Event Hub authorization rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubAuthorizationRule) )
#### Remove-AzEventHubConsumerGroup
Deletes the specified Event Hubs consumer group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubConsumerGroup) )
#### Remove-AzEventHubGeoDRConfiguration
Deletes an Alias(Disaster Recovery configuration)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubGeoDRConfiguration) )
#### Remove-AzEventHubIPRule
Remove a single IPrule to the NetworkRuleSet of the given Namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubIPRule) )
#### Remove-AzEventHubNamespace
Removes the specified Event Hubs namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubNamespace) )
#### Remove-AzEventHubNetworkRuleSet
Removes the NetwrokRuleSet for the Given Namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubNetworkRuleSet) )
#### Remove-AzEventHubVirtualNetworkRule
Removes the single given VirtualNetworkRule for the NetworkRuleSet of the Namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Remove-AzEventHubVirtualNetworkRule) )
#### Remove-AzExpressRouteCircuit
Removes an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteCircuit) )
#### Remove-AzExpressRouteCircuitAuthorization
Removes an existing ExpressRoute configuration authorization.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteCircuitAuthorization) )
#### Remove-AzExpressRouteCircuitConnectionConfig
Removes an ExpressRoute circuit connection configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteCircuitConnectionConfig) )
#### Remove-AzExpressRouteCircuitPeeringConfig
Removes an ExpressRoute circuit peering configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteCircuitPeeringConfig) )
#### Remove-AzExpressRouteConnection
Removes a ExpressRouteConnection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteConnection) )
#### Remove-AzExpressRouteCrossConnectionPeering
Removes an ExpressRoute cross connection peering configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteCrossConnectionPeering) )
#### Remove-AzExpressRouteGateway
The Remove-AzExpressRouteGateway cmdlet removes an Azure ExpressRoute gateway. This is a gateway specific to Azure Virtual WAN's software defined connectivity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRouteGateway) )
#### Remove-AzExpressRoutePort
Removes an ExpressRoutePort.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzExpressRoutePort) )
#### Remove-AzFirewall
Remove a Firewall.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzFirewall) )
#### Remove-AzFrontDoor
Remove Front Door load balancer(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Remove-AzFrontDoor) )
#### Remove-AzFrontDoorContent
Remove contents in Front Door(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Remove-AzFrontDoorContent) )
#### Remove-AzFrontDoorWafPolicy
Remove WAF policy(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Remove-AzFrontDoorWafPolicy) )
#### Remove-AzGallery
Delete a gallery.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzGallery) )
#### Remove-AzGalleryImageDefinition
Delete a gallery image definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzGalleryImageDefinition) )
#### Remove-AzGalleryImageVersion
Delete a gallery image version.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzGalleryImageVersion) )
#### Remove-AzHDInsightCluster
Removes the specified HDInsight cluster from the current subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Remove-AzHDInsightCluster) )
#### Remove-AzHDInsightPersistedScriptAction
Removes an persisted script action from an HDInsight cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Remove-AzHDInsightPersistedScriptAction) )
#### Remove-AzImage
Removes an image.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzImage) )
#### Remove-AzImageDataDisk
Removes a data disk from an image object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzImageDataDisk) )
#### Remove-AzIntegrationAccount
Removes an integration account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccount) )
#### Remove-AzIntegrationAccountAgreement
Removes an integration account agreement.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountAgreement) )
#### Remove-AzIntegrationAccountAssembly
Removes an integration account assembly.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountAssembly) )
#### Remove-AzIntegrationAccountBatchConfiguration
Removes an integration account batch configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountBatchConfiguration) )
#### Remove-AzIntegrationAccountCertificate
Removes an integration account certificate from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountCertificate) )
#### Remove-AzIntegrationAccountMap
Removes an integration account map.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountMap) )
#### Remove-AzIntegrationAccountPartner
Removes an integration account partner.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountPartner) )
#### Remove-AzIntegrationAccountReceivedIcn
This cmdlet removes a specific received interchange control number per agreement and control number value.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountReceivedIcn) )
#### Remove-AzIntegrationAccountSchema
Removes an integration account schema.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzIntegrationAccountSchema) )
#### Remove-AzIoTDeviceProvisioningService
Delete an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Remove-AzIoTDeviceProvisioningService) )
#### Remove-AzIoTDeviceProvisioningServiceAccessPolicy
Delete a shared access policies in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Remove-AzIoTDeviceProvisioningServiceAccessPolicy) )
#### Remove-AzIoTDeviceProvisioningServiceCertificate
Delete an Azure IoT Hub Device Provisioning Service certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Remove-AzIoTDeviceProvisioningServiceCertificate) )
#### Remove-AzIoTDeviceProvisioningServiceLinkedHub
Delete a linked IoT hub in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Remove-AzIoTDeviceProvisioningServiceLinkedHub) )
#### Remove-AzIotHub
Deletes an IotHub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Remove-AzIotHub) )
#### Remove-AzIotHubCertificate
Deletes an Azure IoT Hub certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Remove-AzIotHubCertificate) )
#### Remove-AzIotHubEventHubConsumerGroup
Deletes an eventhub consumergroup.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Remove-AzIotHubEventHubConsumerGroup) )
#### Remove-AzIotHubKey
Removes an IotHub Key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Remove-AzIotHubKey) )
#### Remove-AzIotHubRoute
Delete a route in IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Remove-AzIotHubRoute) )
#### Remove-AzIotHubRoutingEndpoint
Delete an endpoint for your IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Remove-AzIotHubRoutingEndpoint) )
#### Remove-AzJitNetworkAccessPolicy
Deletes a JIT network access policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Remove-AzJitNetworkAccessPolicy) )
#### Remove-AzKeyVault
Deletes a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVault) )
#### Remove-AzKeyVaultAccessPolicy
Removes all permissions for a user or application from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultAccessPolicy) )
#### Remove-AzKeyVaultCertificate
Removes a certificate from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultCertificate) )
#### Remove-AzKeyVaultCertificateContact
Deletes a contact that is registered for certificate notifications from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultCertificateContact) )
#### Remove-AzKeyVaultCertificateIssuer
Deletes a certificate issuer from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultCertificateIssuer) )
#### Remove-AzKeyVaultCertificateOperation
Deletes a certificate operation from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultCertificateOperation) )
#### Remove-AzKeyVaultKey
Deletes a key in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultKey) )
#### Remove-AzKeyVaultManagedStorageAccount
Removes a Key Vault managed Azure Storage Account and all associated SAS definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultManagedStorageAccount) )
#### Remove-AzKeyVaultManagedStorageSasDefinition
Removes a Key Vault managed Azure Storage SAS definitions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultManagedStorageSasDefinition) )
#### Remove-AzKeyVaultNetworkRule
Removes a network rule from a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultNetworkRule) )
#### Remove-AzKeyVaultSecret
Deletes a secret in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Remove-AzKeyVaultSecret) )
#### Remove-AzKustoCluster
Deletes an existing Kusto cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Remove-AzKustoCluster) )
#### Remove-AzKustoDatabase
Deletes an existing Kusto database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Remove-AzKustoDatabase) )
#### Remove-AzLoadBalancer
Removes a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancer) )
#### Remove-AzLoadBalancerBackendAddressPoolConfig
Removes a backend address pool configuration from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerBackendAddressPoolConfig) )
#### Remove-AzLoadBalancerFrontendIpConfig
Removes a front-end IP configuration from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerFrontendIpConfig) )
#### Remove-AzLoadBalancerInboundNatPoolConfig
Removes an inbound NAT pool configuration from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerInboundNatPoolConfig) )
#### Remove-AzLoadBalancerInboundNatRuleConfig
Removes an inbound NAT rule configuration from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerInboundNatRuleConfig) )
#### Remove-AzLoadBalancerOutboundRuleConfig
Removes an outbound rule configuration from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerOutboundRuleConfig) )
#### Remove-AzLoadBalancerProbeConfig
Removes a probe configuration from a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerProbeConfig) )
#### Remove-AzLoadBalancerRuleConfig
Removes a rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLoadBalancerRuleConfig) )
#### Remove-AzLocalNetworkGateway
Deletes a Local Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzLocalNetworkGateway) )
#### Remove-AzLogicApp
Removes a logic app from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Remove-AzLogicApp) )
#### Remove-AzManagedApplication
Removes a managed application(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzManagedApplication) )
#### Remove-AzManagedApplicationDefinition
Removes a managed application definition(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzManagedApplicationDefinition) )
#### Remove-AzManagedServicesAssignment
Deletes the registration assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedservices/Remove-AzManagedServicesAssignment) )
#### Remove-AzManagedServicesDefinition
Deletes the registration definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedservices/Remove-AzManagedServicesDefinition) )
#### Remove-AzManagementGroup
Removes a Management Group(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzManagementGroup) )
#### Remove-AzManagementGroupSubscription
Removes a Subscription from a Management Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzManagementGroupSubscription) )
#### Remove-AzManagementPartner
Delete the Microsoft Partner Network(MPN) ID of the current authenticated user or service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managementpartner/Remove-AzManagementPartner) )
#### Remove-AzMapsAccount
Deletes an Azure Maps account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.maps/Remove-AzMapsAccount) )
#### Remove-AzMediaService
Removes a media service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Remove-AzMediaService) )
#### Remove-AzMlCommitmentPlan
Deletes a commitment plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Remove-AzMlCommitmentPlan) )
#### Remove-AzMlOpCluster
Removes an operationalization cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Remove-AzMlOpCluster) )
#### Remove-AzMlWebService
Deletes a web service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Remove-AzMlWebService) )
#### Remove-AzNatGateway
Remove Nat Gateway resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNatGateway) )
#### Remove-AzNetAppFilesAccount
Deletes an Azure NetApp Files (ANF) account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Remove-AzNetAppFilesAccount) )
#### Remove-AzNetAppFilesPool
Deletes an Azure NetApp Files (ANF) pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Remove-AzNetAppFilesPool) )
#### Remove-AzNetAppFilesSnapshot
Deletes an Azure NetApp Files (ANF) snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Remove-AzNetAppFilesSnapshot) )
#### Remove-AzNetAppFilesVolume
Deletes an Azure NetApp Files (ANF) volume.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Remove-AzNetAppFilesVolume) )
#### Remove-AzNetworkInterface
Removes a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkInterface) )
#### Remove-AzNetworkInterfaceIpConfig
Removes a network interface IP configuration from a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkInterfaceIpConfig) )
#### Remove-AzNetworkInterfaceTapConfig
Removes a tap configuration from given network interface(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkInterfaceTapConfig) )
#### Remove-AzNetworkProfile
Removes a network profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkProfile) )
#### Remove-AzNetworkSecurityGroup
Removes a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkSecurityGroup) )
#### Remove-AzNetworkSecurityRuleConfig
Removes a network security rule from a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkSecurityRuleConfig) )
#### Remove-AzNetworkWatcher
Removes a Network Watcher.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkWatcher) )
#### Remove-AzNetworkWatcherConnectionMonitor
Remove connection monitor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkWatcherConnectionMonitor) )
#### Remove-AzNetworkWatcherPacketCapture
Removes a packet capture resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzNetworkWatcherPacketCapture) )
#### Remove-AzNotificationHub
Removes an existing notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Remove-AzNotificationHub) )
#### Remove-AzNotificationHubAuthorizationRule
Removes an authorization rule from a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Remove-AzNotificationHubAuthorizationRule) )
#### Remove-AzNotificationHubsNamespace
Removes a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Remove-AzNotificationHubsNamespace) )
#### Remove-AzNotificationHubsNamespaceAuthorizationRule
Removes an authorization rule from a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Remove-AzNotificationHubsNamespaceAuthorizationRule) )
#### Remove-AzOperationalInsightsDataSource
Deletes a data source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Remove-AzOperationalInsightsDataSource) )
#### Remove-AzOperationalInsightsSavedSearch
Removes a saved search from the workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Remove-AzOperationalInsightsSavedSearch) )
#### Remove-AzOperationalInsightsStorageInsight
Removes a Storage Insight.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Remove-AzOperationalInsightsStorageInsight) )
#### Remove-AzOperationalInsightsWorkspace
Removes a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Remove-AzOperationalInsightsWorkspace) )
#### Remove-AzPeerAsn
Remove Peer Asn(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Remove-AzPeerAsn) )
#### Remove-AzPolicyAssignment
Removes a policy assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzPolicyAssignment) )
#### Remove-AzPolicyDefinition
Removes a policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzPolicyDefinition) )
#### Remove-AzPolicyRemediation
Deletes a policy remediation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Remove-AzPolicyRemediation) )
#### Remove-AzPolicySetDefinition
Removes a policy set definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzPolicySetDefinition) )
#### Remove-AzPowerBIEmbeddedCapacity
Deletes an instance of PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Remove-AzPowerBIEmbeddedCapacity) )
#### Remove-AzPowerBIWorkspaceCollection
Removes a Power BI workspace collection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Remove-AzPowerBIWorkspaceCollection) )
#### Remove-AzPrivateDnsRecordConfig
Removes a Private DNS record from a local record set object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Remove-AzPrivateDnsRecordConfig) )
#### Remove-AzPrivateDnsRecordSet
Deletes a record set from a Private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Remove-AzPrivateDnsRecordSet) )
#### Remove-AzPrivateDnsVirtualNetworkLink
Removes a virtual network link from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Remove-AzPrivateDnsVirtualNetworkLink) )
#### Remove-AzPrivateDnsZone
Removes a private DNS zone from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Remove-AzPrivateDnsZone) )
#### Remove-AzPrivateEndpoint
Removes a private endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzPrivateEndpoint) )
#### Remove-AzPrivateEndpointConnection
Removes a private endpoint connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzPrivateEndpointConnection) )
#### Remove-AzPrivateLinkService
Removes a private link service(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzPrivateLinkService) )
#### Remove-AzProximityPlacementGroup
Delete Proximity Placement Group resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzProximityPlacementGroup) )
#### Remove-AzPublicIpAddress
Removes a public IP address.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzPublicIpAddress) )
#### Remove-AzPublicIpPrefix
Removes a public IP prefix(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzPublicIpPrefix) )
#### Remove-AzRecoveryServicesAsrFabric
Deletes the specified Azure Site Recovery Fabric from the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrFabric) )
#### Remove-AzRecoveryServicesAsrNetworkMapping
Deletes the specified ASR network mapping from the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrNetworkMapping) )
#### Remove-AzRecoveryServicesAsrPolicy
Deletes the specified ASR replication policy from the Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrPolicy) )
#### Remove-AzRecoveryServicesAsrProtectionContainer
Deletes the specified Protection Container from its Fabric.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrProtectionContainer) )
#### Remove-AzRecoveryServicesAsrProtectionContainerMapping
Deletes the specified Azure Site Recovery protection container mapping.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrProtectionContainerMapping) )
#### Remove-AzRecoveryServicesAsrRecoveryPlan
Deletes the specified ASR recovery plan from Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrRecoveryPlan) )
#### Remove-AzRecoveryServicesAsrReplicationProtectedItem
Stops/Disables replication for an Azure Site Recovery replication protected item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrReplicationProtectedItem) )
#### Remove-AzRecoveryServicesAsrServicesProvider
Deletes/unregister the specified Azure Site Recovery recovery services provider from the recovery services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrServicesProvider) )
#### Remove-AzRecoveryServicesAsrStorageClassificationMapping
Deletes the specified ASR storage classification mapping.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrStorageClassificationMapping) )
#### Remove-AzRecoveryServicesAsrvCenter
Removes the vCenter server from the ASR fabric and stops discovery of virtual machines from the vCenter server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesAsrvCenter) )
#### Remove-AzRecoveryServicesBackupProtectionPolicy
Deletes a Backup protection policy from a vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesBackupProtectionPolicy) )
#### Remove-AzRecoveryServicesVault
Deletes a Recovery Services vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Remove-AzRecoveryServicesVault) )
#### Remove-AzRedisCache
Removes a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Remove-AzRedisCache) )
#### Remove-AzRedisCacheDiagnostic
Disables diagnostics on an Azure Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Remove-AzRedisCacheDiagnostic) )
#### Remove-AzRedisCacheFirewallRule
Remove a firewall rule from a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Remove-AzRedisCacheFirewallRule) )
#### Remove-AzRedisCacheLink
Remove a geo replication link between two Redis Caches.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Remove-AzRedisCacheLink) )
#### Remove-AzRedisCachePatchSchedule
Removes the patch schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Remove-AzRedisCachePatchSchedule) )
#### Remove-AzRelayAuthorizationRule
Removes the authorization rule of a HybridConnection from the given Relay entities (Namespace/WcfRelay/HybridConnection).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Remove-AzRelayAuthorizationRule) )
#### Remove-AzRelayHybridConnection
Removes the HybridConnection from the specified HybridConnection namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Remove-AzRelayHybridConnection) )
#### Remove-AzRelayNamespace
Removes the namespace from the specified resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Remove-AzRelayNamespace) )
#### Remove-AzResource
Removes a resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzResource) )
#### Remove-AzResourceGroup
Removes a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzResourceGroup) [1.3.01](#1301) [1.3.02](#1302))
#### Remove-AzResourceGroupDeployment
Removes a resource group deployment and any associated operations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzResourceGroupDeployment) )
#### Remove-AzResourceLock
Removes a resource lock.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzResourceLock) )
#### Remove-AzRmStorageContainer
Removes a Storage blob container(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzRmStorageContainer) )
#### Remove-AzRmStorageContainerImmutabilityPolicy
Removes ImmutabilityPolicy of a Storage blob containers(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzRmStorageContainerImmutabilityPolicy) )
#### Remove-AzRmStorageContainerLegalHold
Removes legal hold tags from a Storage blob container(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzRmStorageContainerLegalHold) )
#### Remove-AzRoleAssignment
Removes a role assignment to the specified principal who is assigned to a particular role at a particular scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzRoleAssignment) [1.4c.10](#14c10) [1.4c.11](#14c11))
#### Remove-AzRoleDefinition
Deletes a custom role in Azure RBAC.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzRoleDefinition) )
#### Remove-AzRouteConfig
Removes a route from a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzRouteConfig) )
#### Remove-AzRouteFilter
Removes a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzRouteFilter) )
#### Remove-AzRouteFilterRuleConfig
Removes a route filter rule from a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzRouteFilterRuleConfig) )
#### Remove-AzRouteTable
Removes a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzRouteTable) )
#### Remove-AzSearchQueryKey
Remove the query key from the Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/Remove-AzSearchQueryKey) )
#### Remove-AzSearchService
Remove an Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/Remove-AzSearchService) )
#### Remove-AzSecurityContact
Deletes a security contact.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Remove-AzSecurityContact) )
#### Remove-AzSecurityWorkspaceSetting
Deletes the security workspace setting for this subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Remove-AzSecurityWorkspaceSetting) )
#### Remove-AzServiceBusAuthorizationRule
Removes the authorization rule of a Service Bus namespace or queue or topic from the specified resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusAuthorizationRule) )
#### Remove-AzServiceBusGeoDRConfiguration
Deletes an Alias(Disaster Recovery configuration)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusGeoDRConfiguration) )
#### Remove-AzServiceBusMigration
Cmdlet deletes the Migration configuration for Standard to Premium namespaces(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusMigration) )
#### Remove-AzServiceBusNamespace
Removes the namespace from the specified resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusNamespace) )
#### Remove-AzServiceBusQueue
Removes the queue from the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusQueue) )
#### Remove-AzServiceBusRule
Removes the speficied rule of a given subscription .(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusRule) )
#### Remove-AzServiceBusSubscription
Removes the subscription to a topic from the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusSubscription) )
#### Remove-AzServiceBusTopic
Removes the topic from the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Remove-AzServiceBusTopic) )
#### Remove-AzServiceEndpointPolicy
Removes a service endpoint policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzServiceEndpointPolicy) )
#### Remove-AzServiceEndpointPolicyDefinition
Removes a service endpoint policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzServiceEndpointPolicyDefinition) )
#### Remove-AzServiceFabricClientCertificate
Remove a client certificate(s) or certificate subject(s) name(s) from being used for client authentication to the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Remove-AzServiceFabricClientCertificate) )
#### Remove-AzServiceFabricClusterCertificate
Remove a cluster certificate from being used for cluster security.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Remove-AzServiceFabricClusterCertificate) )
#### Remove-AzServiceFabricNode
Remove nodes from the specific node type from a cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Remove-AzServiceFabricNode) )
#### Remove-AzServiceFabricNodeType
Remove a complete node type from a cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Remove-AzServiceFabricNodeType) )
#### Remove-AzServiceFabricSetting
Remove one or multiple Service Fabric setting from the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Remove-AzServiceFabricSetting) )
#### Remove-AzSignalR
Remove a SignalR service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.signalr/Remove-AzSignalR) )
#### Remove-AzSnapshot
Removes a snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzSnapshot) )
#### Remove-AzSpatialAnchorsAccount
Delete specified Spatial Anchors Account from certain Subscription and Resource Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.mixedreality/Remove-AzSpatialAnchorsAccount) )
#### Remove-AzSqlDatabase
Removes an Azure SQL database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabase) )
#### Remove-AzSqlDatabaseAudit
Removes the audit policy of a SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseAudit) )
#### Remove-AzSqlDatabaseDataMaskingRule
Removes a data masking rule from a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseDataMaskingRule) )
#### Remove-AzSqlDatabaseFailoverGroup
Removes an Azure SQL Database Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseFailoverGroup) )
#### Remove-AzSqlDatabaseFromFailoverGroup
Removes one or more databases from an Azure SQL Database Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseFromFailoverGroup) )
#### Remove-AzSqlDatabaseInstanceFailoverGroup
Removes an Azure SQL Database Instance Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseInstanceFailoverGroup) )
#### Remove-AzSqlDatabaseLongTermRetentionBackup
Deletes a long term retention backup.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseLongTermRetentionBackup) )
#### Remove-AzSqlDatabaseRestorePoint
Removes given restore point from a SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseRestorePoint) )
#### Remove-AzSqlDatabaseSecondary
Terminates data replication between a SQL Database and the specified secondary database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseSecondary) )
#### Remove-AzSqlDatabaseSensitivityClassification
Removes the information types and sensitivity labels of columns in the database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlDatabaseSensitivityClassification) )
#### Remove-AzSqlElasticPool
Deletes an elastic database pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlElasticPool) )
#### Remove-AzSqlInstance
Removes an Azure SQL Managed Database Instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlInstance) )
#### Remove-AzSqlInstanceDatabase
Removes an Azure SQL Managed Instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlInstanceDatabase) )
#### Remove-AzSqlInstanceDatabaseSensitivityClassification
Removes the information types and sensitivity labels of columns in the Azure SQL managed instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlInstanceDatabaseSensitivityClassification) )
#### Remove-AzSqlInstanceKeyVaultKey
Removes a Key Vault key from a SQL managed instance(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlInstanceKeyVaultKey) )
#### Remove-AzSqlServer
Removes an Azure SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServer) )
#### Remove-AzSqlServerActiveDirectoryAdministrator
Removes an Azure AD administrator for SQL Server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerActiveDirectoryAdministrator) )
#### Remove-AzSqlServerAudit
Removes the audit policy of a SQL Server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerAudit) )
#### Remove-AzSqlServerCommunicationLink
Deletes a communication link for elastic database transactions between two servers.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerCommunicationLink) )
#### Remove-AzSqlServerDisasterRecoveryConfiguration
Removes a SQL database server system recovery configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerDisasterRecoveryConfiguration) )
#### Remove-AzSqlServerDnsAlias
Removes Azure SQL Server DNS Alias.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerDnsAlias) )
#### Remove-AzSqlServerFirewallRule
Deletes a firewall rule from a SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerFirewallRule) )
#### Remove-AzSqlServerKeyVaultKey
Removes a Key Vault key from a SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerKeyVaultKey) )
#### Remove-AzSqlServerVirtualNetworkRule
Deletes an Azure SQL Server Virtual Network Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlServerVirtualNetworkRule) )
#### Remove-AzSqlSyncAgent
Removes an Azure SQL Sync Agent.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlSyncAgent) )
#### Remove-AzSqlSyncGroup
Removes an Azure SQL Database Sync Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlSyncGroup) )
#### Remove-AzSqlSyncMember
Removes an Azure SQL Database Sync Member.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlSyncMember) )
#### Remove-AzSqlVirtualCluster
Removes an Azure SQL Virtual Cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Remove-AzSqlVirtualCluster) )
#### Remove-AzStorageAccount
Removes a Storage account from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageAccount) )
#### Remove-AzStorageAccountManagementPolicy
Removes the management policy of an Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageAccountManagementPolicy) )
#### Remove-AzStorageAccountNetworkRule
Remove IpRules or VirtualNetworkRules from the NetWorkRule property of a Storage account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageAccountNetworkRule) )
#### Remove-AzStorageBlob
Removes the specified storage blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageBlob) )
#### Remove-AzStorageContainer
Removes the specified storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageContainer) )
#### Remove-AzStorageContainerStoredAccessPolicy
Removes a stored access policy from an Azure storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageContainerStoredAccessPolicy) )
#### Remove-AzStorageCORSRule
Removes CORS for a Storage service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageCORSRule) )
#### Remove-AzStorageDirectory
Deletes a directory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageDirectory) )
#### Remove-AzStorageFile
Deletes a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageFile) )
#### Remove-AzStorageQueue
Removes a storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageQueue) )
#### Remove-AzStorageQueueStoredAccessPolicy
Removes a stored access policy from an Azure storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageQueueStoredAccessPolicy) )
#### Remove-AzStorageShare
Deletes a file share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageShare) )
#### Remove-AzStorageShareStoredAccessPolicy
Removes a stored access policy from a Storage share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageShareStoredAccessPolicy) )
#### Remove-AzStorageSyncCloudEndpoint
This command will delete the specified cloud endpoint from a sync group. Without at least one cloud endpoint, no other server endpoints in this sync group can sync.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Remove-AzStorageSyncCloudEndpoint) )
#### Remove-AzStorageSyncGroup
This command will delete the specified sync group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Remove-AzStorageSyncGroup) )
#### Remove-AzStorageSyncServerEndpoint
This command will delete the specified server endpoint. Sync to this location will stop immediately.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Remove-AzStorageSyncServerEndpoint) )
#### Remove-AzStorageSyncService
This command will delete the specified storage sync service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Remove-AzStorageSyncService) )
#### Remove-AzStorageTable
Removes a storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageTable) )
#### Remove-AzStorageTableStoredAccessPolicy
Removes a stored access policy from an Azure storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Remove-AzStorageTableStoredAccessPolicy) )
#### Remove-AzStreamAnalyticsFunction
Deletes a function from a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Remove-AzStreamAnalyticsFunction) )
#### Remove-AzStreamAnalyticsInput
Deletes an input from a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Remove-AzStreamAnalyticsInput) )
#### Remove-AzStreamAnalyticsJob
Removes a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Remove-AzStreamAnalyticsJob) )
#### Remove-AzStreamAnalyticsOutput
Deletes an output from a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Remove-AzStreamAnalyticsOutput) )
#### Remove-AzTag
Deletes predefined Azure tags or values.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Remove-AzTag) )
#### Remove-AzTrafficManagerCustomHeaderFromEndpoint
Removes custom header information from a local Traffic Manager endpoint object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerCustomHeaderFromEndpoint) )
#### Remove-AzTrafficManagerCustomHeaderFromProfile
Removes custom header information from a local Traffic Manager profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerCustomHeaderFromProfile) )
#### Remove-AzTrafficManagerEndpoint
Removes an endpoint from Traffic Manager.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerEndpoint) )
#### Remove-AzTrafficManagerEndpointConfig
Removes an endpoint from a local Traffic Manager profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerEndpointConfig) )
#### Remove-AzTrafficManagerExpectedStatusCodeRange
Removes an expected status code range from a local Traffic Manager profile object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerExpectedStatusCodeRange) )
#### Remove-AzTrafficManagerIpAddressRange
Removes an address range or subnet from a local Traffic Manager endpoint object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerIpAddressRange) )
#### Remove-AzTrafficManagerProfile
Deletes a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Remove-AzTrafficManagerProfile) )
#### Remove-AzUserAssignedIdentity
Removes a User Assigned Identity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managedserviceidentity/Remove-AzUserAssignedIdentity) )
#### Remove-AzVirtualHub
Removes an Azure VirtualHub resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualHub) )
#### Remove-AzVirtualHubVnetConnection
The Remove-AzVirtualHubVnetConnection cmdlet removes an Azure Virtual Network Connection which peers a remote VNET to the hub VNET.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualHubVnetConnection) )
#### Remove-AzVirtualNetwork
Removes a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetwork) )
#### Remove-AzVirtualNetworkGateway
Deletes a Virtual Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkGateway) )
#### Remove-AzVirtualNetworkGatewayConnection
Deletes a Virtual Network Gateway Connection(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkGatewayConnection) )
#### Remove-AzVirtualNetworkGatewayDefaultSite
Removes the default site from a virtual network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkGatewayDefaultSite) )
#### Remove-AzVirtualNetworkGatewayIpConfig
Removes an IP Configuration from a Virtual Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkGatewayIpConfig) )
#### Remove-AzVirtualNetworkPeering
Removes a virtual network peering.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkPeering) )
#### Remove-AzVirtualNetworkSubnetConfig
Removes a subnet configuration from a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkSubnetConfig) )
#### Remove-AzVirtualNetworkTap
Removes a virtual network tap.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualNetworkTap) )
#### Remove-AzVirtualWan
Removes an Azure Virtual WAN.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVirtualWan) )
#### Remove-AzVM
Removes a virtual machine from Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVM) )
#### Remove-AzVMAccessExtension
Removes the VMAccess extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMAccessExtension) )
#### Remove-AzVMAEMExtension
Removes the AEM extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMAEMExtension) )
#### Remove-AzVMBackup
Removes the backup from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMBackup) )
#### Remove-AzVMChefExtension
Removes the Chef extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMChefExtension) )
#### Remove-AzVMCustomScriptExtension
Removes a custom script extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMCustomScriptExtension) )
#### Remove-AzVMDataDisk
Removes a data disk from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMDataDisk) )
#### Remove-AzVMDiagnosticsExtension
Removes the Diagnostics extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMDiagnosticsExtension) )
#### Remove-AzVMDiskEncryptionExtension
Removes the disk encryption extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMDiskEncryptionExtension) )
#### Remove-AzVMDscExtension
Removes a DSC extension handler from a virtual machine in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMDscExtension) )
#### Remove-AzVMExtension
Removes an extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMExtension) )
#### Remove-AzVMNetworkInterface
Removes a network interface from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMNetworkInterface) )
#### Remove-AzVMSecret
Removes (a) secret(s) from a virtual machine object(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMSecret) )
#### Remove-AzVMSqlServerExtension
Removes a SQL Server extension from a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVMSqlServerExtension) )
#### Remove-AzVmss
Removes the VMSS or a virtual machine that is within the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVmss) )
#### Remove-AzVmssDataDisk
Removes a data disk from the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVmssDataDisk) )
#### Remove-AzVmssDiagnosticsExtension
Removes a diagnostics extension from the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVmssDiagnosticsExtension) )
#### Remove-AzVmssExtension
Removes an extension from the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVmssExtension) )
#### Remove-AzVmssNetworkInterfaceConfiguration
Removes a network interface configuration from a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVmssNetworkInterfaceConfiguration) )
#### Remove-AzVmssVMDataDisk
Removes a data disk from a virtual machine scale set VM(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Remove-AzVmssVMDataDisk) )
#### Remove-AzVpnClientIpsecParameter
Removes Vpn custom ipsec policy set on Virtual Network Gateway resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVpnClientIpsecParameter) )
#### Remove-AzVpnClientRevokedCertificate
Removes a VPN client-revocation certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVpnClientRevokedCertificate) )
#### Remove-AzVpnClientRootCertificate
Removes an existing VPN client root certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVpnClientRootCertificate) )
#### Remove-AzVpnConnection
Removes a VpnConnection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVpnConnection) )
#### Remove-AzVpnGateway
The Remove-AzVpnGateway cmdlet removes an Azure VPN gateway. This is a gateway specific to Azure Virtual WAN's software defined connectivity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVpnGateway) )
#### Remove-AzVpnSite
Removes an Azure VpnSite resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Remove-AzVpnSite) )
#### Remove-AzWcfRelay
Removes the WcfRelay from the specified Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Remove-AzWcfRelay) )
#### Remove-AzWebApp
Removes an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Remove-AzWebApp) )
#### Remove-AzWebAppBackup
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Remove-AzWebAppBackup) )
#### Remove-AzWebAppSlot
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Remove-AzWebAppSlot) )
#### Remove-AzWebAppSSLBinding
Removes an SSL binding from an uploaded certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Remove-AzWebAppSSLBinding) )
#### Rename-AzContext
Rename an Azure context. By default contexts are named by user account and subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Rename-AzContext) )
#### Repair-AzVmssServiceFabricUpdateDomain
Manual platform update domain walk to update virtual machines in a service fabric virtual machine scale set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Repair-AzVmssServiceFabricUpdateDomain) )
#### Reset-AzBatchComputeNode
Reinstalls the operating system on the specified compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Reset-AzBatchComputeNode) )
#### Reset-AzPowerBIWorkspaceCollectionAccessKey
Resets the specified access key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Reset-AzPowerBIWorkspaceCollectionAccessKey) )
#### Reset-AzRedisCache
Restarts nodes of a cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Reset-AzRedisCache) )
#### Reset-AzStorageSyncServerCertificate
Use for troubleshooting only. This command will roll the storage sync server certificate used to describe the server identity to the storage sync service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Reset-AzStorageSyncServerCertificate) )
#### Reset-AzVirtualNetworkGateway
Resets the Virtual Network Gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Reset-AzVirtualNetworkGateway) )
#### Reset-AzVirtualNetworkGatewayConnectionSharedKey
Resets the shared key of the virtual network gateway connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Reset-AzVirtualNetworkGatewayConnectionSharedKey) )
#### Reset-AzWebAppPublishingProfile
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Reset-AzWebAppPublishingProfile) )
#### Reset-AzWebAppSlotPublishingProfile
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Reset-AzWebAppSlotPublishingProfile) )
#### Resize-AzVirtualNetworkGateway
Resizes an existing virtual network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Resize-AzVirtualNetworkGateway) )
#### Resolve-AzError
Display detailed information about PowerShell errors, with extended details for Azure PowerShell errors.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Resolve-AzError) )
#### Restart-AzAnalysisServicesInstance
Restarts an instance of Analysis Services server in the currently logged in Environment as specified in Add-AzAnalysisServicesAccount command(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Restart-AzAnalysisServicesInstance) )
#### Restart-AzBatchComputeNode
Reboots the specified compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Restart-AzBatchComputeNode) )
#### Restart-AzDeploymentManagerRollout
Restarts a failed rollout.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Restart-AzDeploymentManagerRollout) )
#### Restart-AzRecoveryServicesAsrJob
Restarts an Azure Site Recovery job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Restart-AzRecoveryServicesAsrJob) )
#### Restart-AzVM
Restarts an Azure virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Restart-AzVM) [4.3b.02](#43b02))
#### Restart-AzVmss
Restarts the VMSS or a virtual machine within the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Restart-AzVmss) )
#### Restart-AzWebApp
Restarts an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Restart-AzWebApp) )
#### Restart-AzWebAppSlot
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Restart-AzWebAppSlot) )
#### Restore-AzApiManagement
Restores an API Management Service from the specified Azure storage blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Restore-AzApiManagement) )
#### Restore-AzDeletedWebApp
Restores a deleted web app to a new or existing web app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Restore-AzDeletedWebApp) )
#### Restore-AzKeyVaultCertificate
Restores a certificate in a key vault from a backup file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Restore-AzKeyVaultCertificate) )
#### Restore-AzKeyVaultKey
Creates a key in a key vault from a backed-up key.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Restore-AzKeyVaultKey) )
#### Restore-AzKeyVaultManagedStorageAccount
Restores a managed storage account in a key vault from a backup file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Restore-AzKeyVaultManagedStorageAccount) )
#### Restore-AzKeyVaultSecret
Creates a secret in a key vault from a backed-up secret.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Restore-AzKeyVaultSecret) )
#### Restore-AzRecoveryServicesBackupItem
Restores the data and configuration for a Backup item to a recovery point.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Restore-AzRecoveryServicesBackupItem) )
#### Restore-AzSqlDatabase
Restores a SQL database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Restore-AzSqlDatabase) )
#### Restore-AzSqlInstanceDatabase
Restores an Azure SQL Managed Instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Restore-AzSqlInstanceDatabase) )
#### Restore-AzWebAppBackup
(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Restore-AzWebAppBackup) )
#### Restore-AzWebAppSnapshot
Restores a web app snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Restore-AzWebAppSnapshot) )
#### Resume-AzAnalysisServicesServer
Resumes an instance of Analysis Services server(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Resume-AzAnalysisServicesServer) )
#### Resume-AzAutomationJob
Resumes a suspended Automation job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Resume-AzAutomationJob) )
#### Resume-AzDataFactoryPipeline
Resumes a suspended pipeline in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Resume-AzDataFactoryPipeline) )
#### Resume-AzKustoCluster
Resume a suspeneded Kusto cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Resume-AzKustoCluster) )
#### Resume-AzPowerBIEmbeddedCapacity
Resumes an instance of PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Resume-AzPowerBIEmbeddedCapacity) )
#### Resume-AzRecoveryServicesAsrJob
Resumes a suspended Azure Site Recovery job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Resume-AzRecoveryServicesAsrJob) )
#### Resume-AzSqlDatabase
Resumes a SQL Data Warehouse database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Resume-AzSqlDatabase) )
#### Revoke-AzDiskAccess
Revokes an access to a disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Revoke-AzDiskAccess) )
#### Revoke-AzHDInsightRdpServicesAccess
Disables RDP access to a Windows cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Revoke-AzHDInsightRdpServicesAccess) )
#### Revoke-AzSnapshotAccess
Revokes an access to a snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Revoke-AzSnapshotAccess) )
#### Save-AzApiManagementTenantGitConfiguration
Saves changes by creating a commit for current configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Save-AzApiManagementTenantGitConfiguration) )
#### Save-AzContext
Saves the current authentication information for use in other PowerShell sessions.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Save-AzContext) )
#### Save-AzDataFactoryLog
Downloads log files from Azure HDInsight processing.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Save-AzDataFactoryLog) )
#### Save-AzDeploymentTemplate
Saves a deployment template to a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Save-AzDeploymentTemplate) )
#### Save-AzResourceGroupDeploymentTemplate
Saves a resource group deployment template to a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Save-AzResourceGroupDeploymentTemplate) [3.2e.03](#32e03))
#### Save-AzVhd
Saves downloaded .vhd images locally.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Save-AzVhd) )
#### Save-AzVMImage
Saves a virtual machine as a VMImage.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Save-AzVMImage) )
#### Search-AzGraph
Queries the resources managed by Azure Resource Manager.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resourcegraph/Search-AzGraph) )
#### Select-AzContext
Select a subscription and account to target in Azure PowerShell cmdlets(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Select-AzContext) )
#### Select-AzProfile
For modules that support multiple service profiles - load the cmdlets corresponding with the given service profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Select-AzProfile) )
#### Send-Feedback
Sends feedback to the Azure PowerShell team via a set of guided prompts.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Send-Feedback) )
#### Set-AzActionRule
Create or update an action rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Set-AzActionRule) )
#### Set-AzAdvisorConfiguration
Updates or creates the Azure Advisor Configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.advisor/Set-AzAdvisorConfiguration) )
#### Set-AzAks
Update or create a managed Kubernetes cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/Set-AzAks) )
#### Set-AzAnalysisServicesServer
Modifies an instance of Analysis Services server(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Set-AzAnalysisServicesServer) )
#### Set-AzApiManagement
Updates an Azure Api Management service(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagement) )
#### Set-AzApiManagementApi
Modifies an API.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementApi) )
#### Set-AzApiManagementApiRevision
Modifies an API Revision(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementApiRevision) )
#### Set-AzApiManagementApiSchema
Modifies an API Schema(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementApiSchema) )
#### Set-AzApiManagementApiVersionSet
Updates an API Version Set in the API Management Context.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementApiVersionSet) )
#### Set-AzApiManagementAuthorizationServer
Modifies an authorization server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementAuthorizationServer) )
#### Set-AzApiManagementBackend
Updates a Backend.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementBackend) )
#### Set-AzApiManagementCertificate
Modifies an API Management certificate which is configured for mutual authentication with backend.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementCertificate) )
#### Set-AzApiManagementDiagnostic
Modifies an API Management diagnostic at the Global or Api scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementDiagnostic) )
#### Set-AzApiManagementGroup
Configures an API management group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementGroup) )
#### Set-AzApiManagementIdentityProvider
Updates the Configuration of an existing Identity Provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementIdentityProvider) )
#### Set-AzApiManagementLogger
Modifies an API Management Logger.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementLogger) )
#### Set-AzApiManagementOpenIdConnectProvider
Modifies an OpenID Connect provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementOpenIdConnectProvider) )
#### Set-AzApiManagementOperation
Sets API operation details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementOperation) )
#### Set-AzApiManagementPolicy
Sets the specified scope policy for API Management.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementPolicy) )
#### Set-AzApiManagementProduct
Sets the API Management product details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementProduct) )
#### Set-AzApiManagementProperty
Modifies an API Management Property.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementProperty) )
#### Set-AzApiManagementSubscription
Sets existing subscription details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementSubscription) )
#### Set-AzApiManagementTenantAccess
Enables or disables tenant access.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementTenantAccess) )
#### Set-AzApiManagementUser
Sets user details.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Set-AzApiManagementUser) )
#### Set-AzApplicationGateway
Updates an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGateway) )
#### Set-AzApplicationGatewayAuthenticationCertificate
Updates an authentication certificate for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayAuthenticationCertificate) )
#### Set-AzApplicationGatewayAutoscaleConfiguration
Updates Autoscale Configuration of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayAutoscaleConfiguration) )
#### Set-AzApplicationGatewayBackendAddressPool
Updates a back-end address pool for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayBackendAddressPool) )
#### Set-AzApplicationGatewayBackendHttpSetting
Updates back-end HTTP settings for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayBackendHttpSetting) )
#### Set-AzApplicationGatewayConnectionDraining
Modifies the connection draining configuration of a back-end HTTP settings object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayConnectionDraining) )
#### Set-AzApplicationGatewayCustomError
Updates a custom error in an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayCustomError) )
#### Set-AzApplicationGatewayFirewallPolicy
Updates an application gateway firewall policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayFirewallPolicy) )
#### Set-AzApplicationGatewayFrontendIPConfig
Modifies a front-end IP address configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayFrontendIPConfig) )
#### Set-AzApplicationGatewayFrontendPort
Modifies a front-end port for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayFrontendPort) )
#### Set-AzApplicationGatewayHttpListener
Modifies an HTTP listener for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayHttpListener) )
#### Set-AzApplicationGatewayHttpListenerCustomError
Updates a custom error in a http listener of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayHttpListenerCustomError) )
#### Set-AzApplicationGatewayIdentity
Updates a identity assigned to the application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayIdentity) )
#### Set-AzApplicationGatewayIPConfiguration
Modifies an IP configuration for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayIPConfiguration) )
#### Set-AzApplicationGatewayProbeConfig
Sets the health probe configuration on an existing Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayProbeConfig) )
#### Set-AzApplicationGatewayRedirectConfiguration
Sets the redirect configuration on an existing Application Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayRedirectConfiguration) )
#### Set-AzApplicationGatewayRequestRoutingRule
Modifies a request routing rule for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayRequestRoutingRule) )
#### Set-AzApplicationGatewayRewriteRuleSet
Modifies a rewrite rule set for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayRewriteRuleSet) )
#### Set-AzApplicationGatewaySku
Modifies the SKU of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewaySku) )
#### Set-AzApplicationGatewaySslCertificate
Updates an SSL certificate for an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewaySslCertificate) )
#### Set-AzApplicationGatewaySslPolicy
Modifies the SSL policy of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewaySslPolicy) )
#### Set-AzApplicationGatewayTrustedRootCertificate
Updates a Trusted Root Certificate of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayTrustedRootCertificate) )
#### Set-AzApplicationGatewayUrlPathMapConfig
Sets configuration for an array of URL path mappings to a backend server pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayUrlPathMapConfig) )
#### Set-AzApplicationGatewayWebApplicationFirewallConfiguration
Modifies the WAF configuration of an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzApplicationGatewayWebApplicationFirewallConfiguration) )
#### Set-AzApplicationInsightsContinuousExport
Update a continuous export configuration in an applciation insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Set-AzApplicationInsightsContinuousExport) )
#### Set-AzApplicationInsightsDailyCap
Set daily data volume cap for an application insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Set-AzApplicationInsightsDailyCap) )
#### Set-AzApplicationInsightsPricingPlan
Set pricing plan and daily data volume information for an applicaiton insights resource(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.applicationinsights/Set-AzApplicationInsightsPricingPlan) )
#### Set-AzAppServicePlan
Sets an Azure App Service plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Set-AzAppServicePlan) )
#### Set-AzAutomationAccount
Modifies an Automation account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationAccount) )
#### Set-AzAutomationCertificate
Modifies the configuration of an Automation certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationCertificate) )
#### Set-AzAutomationConnectionFieldValue
Modifies the value of a field in an Automation connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationConnectionFieldValue) )
#### Set-AzAutomationCredential
Modifies an Automation credential.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationCredential) )
#### Set-AzAutomationDscNode
Modifies the node configuration that a DSC node is mapped to.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationDscNode) )
#### Set-AzAutomationModule
Updates a module in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationModule) )
#### Set-AzAutomationRunbook
Modifies a runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationRunbook) )
#### Set-AzAutomationSchedule
Modifies an Automation schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationSchedule) )
#### Set-AzAutomationVariable
Modifies an Automation variable.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationVariable) )
#### Set-AzAutomationWebhook
Modifies a webhook for an Automation runbook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Set-AzAutomationWebhook) )
#### Set-AzBatchAccount
Updates a Batch account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchAccount) )
#### Set-AzBatchApplication
Updates settings for the specified application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchApplication) )
#### Set-AzBatchComputeNodeUser
Modifies properties of an account on a Batch compute node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchComputeNodeUser) )
#### Set-AzBatchJob
Updates a Batch job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchJob) )
#### Set-AzBatchJobSchedule
Sets a job schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchJobSchedule) )
#### Set-AzBatchPool
Updates the properties of a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchPool) )
#### Set-AzBatchPoolOSVersion
Changes the operating system version of the specified pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchPoolOSVersion) )
#### Set-AzBatchTask
Updates the properties of a task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Set-AzBatchTask) )
#### Set-AzBlueprint
Update a blueprint and save it within the specified subscription or management group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Set-AzBlueprint) )
#### Set-AzBlueprintArtifact
Update an artifact in a blueprint definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Set-AzBlueprintArtifact) )
#### Set-AzBlueprintAssignment
Update an existing blueprint assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.blueprint/Set-AzBlueprintAssignment) )
#### Set-AzCdnEndpoint
Updates a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Set-AzCdnEndpoint) )
#### Set-AzCdnOrigin
Updates a CDN origin server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Set-AzCdnOrigin) )
#### Set-AzCdnProfile
Updates a CDN profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Set-AzCdnProfile) )
#### Set-AzCognitiveServicesAccount
Modifies an account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Set-AzCognitiveServicesAccount) )
#### Set-AzConsumptionBudget
Update a budget in either a subscription or a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.billing/Set-AzConsumptionBudget) )
#### Set-AzContext
Sets the tenant, subscription, and environment for cmdlets to use in the current session.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Set-AzContext) )
#### Set-AzCurrentStorageAccount
Modifies the current Storage account of the specified subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzCurrentStorageAccount) [2.2a.01](#22a01) [4.6d.02](#46d02))
#### Set-AzDataFactoryGateway
Sets the description for a gateway in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryGateway) )
#### Set-AzDataFactoryPipelineActivePeriod
Configures the active period for data slices.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryPipelineActivePeriod) )
#### Set-AzDataFactorySliceStatus
Sets the status of slices for a dataset in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactorySliceStatus) )
#### Set-AzDataFactoryV2
Creates a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryV2) )
#### Set-AzDataFactoryV2Dataset
Creates a dataset in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryV2Dataset) )
#### Set-AzDataFactoryV2IntegrationRuntime
Updates an integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryV2IntegrationRuntime) )
#### Set-AzDataFactoryV2LinkedService
Links a data store or a cloud service to Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryV2LinkedService) )
#### Set-AzDataFactoryV2Pipeline
Creates a pipeline in Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryV2Pipeline) )
#### Set-AzDataFactoryV2Trigger
Creates a trigger in a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Set-AzDataFactoryV2Trigger) )
#### Set-AzDataLakeAnalyticsAccount
Modifies a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Set-AzDataLakeAnalyticsAccount) )
#### Set-AzDataLakeAnalyticsCatalogCredential
Modifies an Azure Data Lake Analytics catalog credential password.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Set-AzDataLakeAnalyticsCatalogCredential) )
#### Set-AzDataLakeAnalyticsCatalogItemAclEntry
Modifies an entry in the ACL of a catalog or catalog item in Data Lake Analytics.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Set-AzDataLakeAnalyticsCatalogItemAclEntry) )
#### Set-AzDataLakeAnalyticsDataSource
Modifies the details of a data source of a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Set-AzDataLakeAnalyticsDataSource) )
#### Set-AzDataLakeAnalyticsFirewallRule
Updates a firewall rule in a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Set-AzDataLakeAnalyticsFirewallRule) )
#### Set-AzDataLakeStoreAccount
Modifies a Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreAccount) )
#### Set-AzDataLakeStoreFirewallRule
Modifies the specified firewall rule in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreFirewallRule) )
#### Set-AzDataLakeStoreItemAcl
Modifies the ACL of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreItemAcl) )
#### Set-AzDataLakeStoreItemAclEntry
Modifies an entry in the ACL of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreItemAclEntry) )
#### Set-AzDataLakeStoreItemExpiry
Sets or removes the expire time for a file in an Azure Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreItemExpiry) )
#### Set-AzDataLakeStoreItemOwner
Modifies the owner of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreItemOwner) )
#### Set-AzDataLakeStoreItemPermission
Modifies the permission octal of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreItemPermission) )
#### Set-AzDataLakeStoreTrustedIdProvider
Modifies the specified trusted identity provider in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreTrustedIdProvider) )
#### Set-AzDataLakeStoreVirtualNetworkRule
Modifies the specified virtual network rule in the specified Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Set-AzDataLakeStoreVirtualNetworkRule) )
#### Set-AzDefault
Sets a default in the current context(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Set-AzDefault) )
#### Set-AzDeploymentManagerArtifactSource
Updates the artifacts source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Set-AzDeploymentManagerArtifactSource) )
#### Set-AzDeploymentManagerService
Updates the service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Set-AzDeploymentManagerService) )
#### Set-AzDeploymentManagerServiceTopology
Updates the service topology.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Set-AzDeploymentManagerServiceTopology) )
#### Set-AzDeploymentManagerServiceUnit
Updates the service unit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Set-AzDeploymentManagerServiceUnit) )
#### Set-AzDeploymentManagerStep
Updates the step.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Set-AzDeploymentManagerStep) )
#### Set-AzDiskDiskEncryptionKey
Sets the disk encryption key properties on a disk object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzDiskDiskEncryptionKey) )
#### Set-AzDiskImageReference
Sets the image reference properties on a disk object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzDiskImageReference) )
#### Set-AzDiskKeyEncryptionKey
Sets the key encryption key properties on a disk object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzDiskKeyEncryptionKey) )
#### Set-AzDiskUpdateDiskEncryptionKey
Sets the disk encryption key properties on on a disk update object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzDiskUpdateDiskEncryptionKey) )
#### Set-AzDiskUpdateKeyEncryptionKey
Sets the key encryption key properties on a disk update object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzDiskUpdateKeyEncryptionKey) )
#### Set-AzDtlAllowedVMSizesPolicy
Sets the allowed virtual machine sizes policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Set-AzDtlAllowedVMSizesPolicy) )
#### Set-AzDtlAutoShutdownPolicy
Sets the auto shutdown policy of a lab DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Set-AzDtlAutoShutdownPolicy) )
#### Set-AzDtlAutoStartPolicy
Sets the auto start policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Set-AzDtlAutoStartPolicy) )
#### Set-AzDtlVMsPerLabPolicy
Sets the virtual machines per lab policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Set-AzDtlVMsPerLabPolicy) )
#### Set-AzDtlVMsPerUserPolicy
Sets the virtual machines per user policy of a lab in DevTest Labs.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devtestlabs/Set-AzDtlVMsPerUserPolicy) )
#### Set-AzEnvironment
Sets properties for an Azure environment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Set-AzEnvironment) )
#### Set-AzEventGridTopic
Sets the properties of an Event Grid topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Set-AzEventGridTopic) )
#### Set-AzEventHub
Updates the specified Event Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHub) )
#### Set-AzEventHubAuthorizationRule
Updates the specified authorization rule on an Event Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHubAuthorizationRule) )
#### Set-AzEventHubConsumerGroup
Updates the specified Event Hubs consumer group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHubConsumerGroup) )
#### Set-AzEventHubGeoDRConfigurationBreakPair
This operation disables the Disaster Recovery and stops replicating changes from primary to secondary namespaces(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHubGeoDRConfigurationBreakPair) )
#### Set-AzEventHubGeoDRConfigurationFailOver
Invokes GEO DR failover and reconfigure the alias to point to the secondary namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHubGeoDRConfigurationFailOver) )
#### Set-AzEventHubNamespace
Updates the specified Event Hubs namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHubNamespace) )
#### Set-AzEventHubNetworkRuleSet
Update the NetwrokruleSet of the given Namepsace in the current Azure subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Set-AzEventHubNetworkRuleSet) )
#### Set-AzExpressRouteCircuit
Modifies an ExpressRoute circuit.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzExpressRouteCircuit) )
#### Set-AzExpressRouteCircuitPeeringConfig
Saves a modified ExpressRoute peering configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzExpressRouteCircuitPeeringConfig) )
#### Set-AzExpressRouteConnection
Updates an express route connection created between an express route gateway and on-premise express route circuit peering.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzExpressRouteConnection) )
#### Set-AzExpressRouteCrossConnection
Modifies an ExpressRoute cross connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzExpressRouteCrossConnection) )
#### Set-AzExpressRouteGateway
Updates a Scalable ExpressRoute Gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzExpressRouteGateway) )
#### Set-AzExpressRoutePort
Modifies an ExpressRoutePort.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzExpressRoutePort) )
#### Set-AzFirewall
Saves a modified Firewall.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzFirewall) )
#### Set-AzFrontDoor
Update a Front Door load balancer(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Set-AzFrontDoor) )
#### Set-AzHDInsightClusterSize
Sets the number of Worker nodes in a specified cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Set-AzHDInsightClusterSize) )
#### Set-AzHDInsightDefaultStorage
Sets the default Storage account setting in a cluster configuration object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Set-AzHDInsightDefaultStorage) )
#### Set-AzHDInsightGatewayCredential
Sets the gateway HTTP credentials of an Azure HDInsight cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Set-AzHDInsightGatewayCredential) )
#### Set-AzHDInsightPersistedScriptAction
Sets a previously executed script action to be a persisted script action.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Set-AzHDInsightPersistedScriptAction) )
#### Set-AzImageOsDisk
Sets the operating system disk properties on an image object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzImageOsDisk) )
#### Set-AzIntegrationAccount
Modifies an integration account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccount) )
#### Set-AzIntegrationAccountAgreement
Modifies an integration account agreement.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountAgreement) )
#### Set-AzIntegrationAccountAssembly
Modifies an integration account assembly.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountAssembly) )
#### Set-AzIntegrationAccountBatchConfiguration
Modifies an integration account batch configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountBatchConfiguration) )
#### Set-AzIntegrationAccountCertificate
Modifies an integration account certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountCertificate) )
#### Set-AzIntegrationAccountGeneratedIcn
Updates the integration account generated interchange control number (ICN) in the Azure resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountGeneratedIcn) )
#### Set-AzIntegrationAccountMap
Modifies an integration account map.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountMap) )
#### Set-AzIntegrationAccountPartner
Modifies an integration account partner.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountPartner) )
#### Set-AzIntegrationAccountReceivedIcn
Updates the integration account received interchange control number (ICN) in the Azure resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountReceivedIcn) )
#### Set-AzIntegrationAccountSchema
Modifies an integration account schema.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzIntegrationAccountSchema) )
#### Set-AzIoTDeviceProvisioningServiceCertificate
Verify an Azure IoT Hub Device Provisioning Service certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Set-AzIoTDeviceProvisioningServiceCertificate) )
#### Set-AzIotHub
Updates the properties of an IotHub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Set-AzIotHub) )
#### Set-AzIotHubRoute
Update a route in IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Set-AzIotHubRoute) )
#### Set-AzIotHubVerifiedCertificate
Verifies an Azure IoT Hub certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Set-AzIotHubVerifiedCertificate) )
#### Set-AzJitNetworkAccessPolicy
Updates JIT network access policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Set-AzJitNetworkAccessPolicy) )
#### Set-AzKeyVaultAccessPolicy
Grants or modifies existing permissions for a user, application, or security group to perform operations with a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Set-AzKeyVaultAccessPolicy) )
#### Set-AzKeyVaultCertificateIssuer
Sets a certificate issuer in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Set-AzKeyVaultCertificateIssuer) )
#### Set-AzKeyVaultCertificatePolicy
Creates or updates the policy for a certificate in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Set-AzKeyVaultCertificatePolicy) )
#### Set-AzKeyVaultManagedStorageSasDefinition
Sets a Shared Access Signature (SAS) definition with Key Vault for a given Key Vault managed Azure Storage Account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Set-AzKeyVaultManagedStorageSasDefinition) )
#### Set-AzKeyVaultSecret
Creates or updates a secret in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Set-AzKeyVaultSecret) [2.1c.02](#21c02))
#### Set-AzLoadBalancer
Updates a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancer) [3.1h.02](#31h02))
#### Set-AzLoadBalancerFrontendIpConfig
Updates a front-end IP configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancerFrontendIpConfig) )
#### Set-AzLoadBalancerInboundNatPoolConfig
Sets an inbound NAT pool configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancerInboundNatPoolConfig) )
#### Set-AzLoadBalancerInboundNatRuleConfig
Sets an inbound NAT rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancerInboundNatRuleConfig) )
#### Set-AzLoadBalancerOutboundRuleConfig
Sets an outbound rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancerOutboundRuleConfig) )
#### Set-AzLoadBalancerProbeConfig
Updates a probe configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancerProbeConfig) )
#### Set-AzLoadBalancerRuleConfig
Updates a rule configuration for a load balancer.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLoadBalancerRuleConfig) )
#### Set-AzLocalNetworkGateway
Modifies a local network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzLocalNetworkGateway) )
#### Set-AzLogicApp
Modifies a logic app in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Set-AzLogicApp) )
#### Set-AzManagedApplication
Updates managed application(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzManagedApplication) )
#### Set-AzManagedApplicationDefinition
Updates managed application definition(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzManagedApplicationDefinition) )
#### Set-AzMarketplaceTerms
Accept or reject terms for a given publisher id(Publisher), offer id(Product) and plan id(Name). Please use Get-AzMarketplaceTerms to get the agreement terms.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.marketplaceordering/Set-AzMarketplaceTerms) )
#### Set-AzMediaService
Modifies specified properties of an existing media service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Set-AzMediaService) )
#### Set-AzMediaServiceKey
Regenerates a key used for accessing the REST endpoint associated with the media service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Set-AzMediaServiceKey) )
#### Set-AzMlOpCluster
Sets the properties of an operationalization cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Set-AzMlOpCluster) )
#### Set-AzNatGateway
Update Nat Gateway Resource with Public Ip Address, Public Ip Prefix and IdleTimeoutInMinutes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNatGateway) )
#### Set-AzNetAppFilesAccount
Provide a full new dataset for an Azure NetApp Files (ANF) account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Set-AzNetAppFilesAccount) )
#### Set-AzNetworkInterface
Updates a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkInterface) [4.3b.02](#43b02) [4.5a.02](#45a02))
#### Set-AzNetworkInterfaceIpConfig
Updates an IP configuration for a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkInterfaceIpConfig) [4.5a.02](#45a02))
#### Set-AzNetworkInterfaceTapConfig
Updates a tap configuration for a network interface.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkInterfaceTapConfig) )
#### Set-AzNetworkProfile
Updates a network profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkProfile) )
#### Set-AzNetworkSecurityGroup
Updates a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkSecurityGroup) )
#### Set-AzNetworkSecurityRuleConfig
Updates a network security rule configuration for a network security group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkSecurityRuleConfig) )
#### Set-AzNetworkWatcherConfigFlowLog
Configures flow logging for a target resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkWatcherConfigFlowLog) )
#### Set-AzNetworkWatcherConnectionMonitor
Update a connection monitor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzNetworkWatcherConnectionMonitor) )
#### Set-AzNotificationHub
Sets property values for a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Set-AzNotificationHub) )
#### Set-AzNotificationHubAuthorizationRule
Sets authorization rules for a notification hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Set-AzNotificationHubAuthorizationRule) )
#### Set-AzNotificationHubsNamespace
Sets property values for a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Set-AzNotificationHubsNamespace) )
#### Set-AzNotificationHubsNamespaceAuthorizationRule
Sets authorization rules for a notification hub namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.notificationhubs/Set-AzNotificationHubsNamespaceAuthorizationRule) )
#### Set-AzOperationalInsightsDataSource
Updates a data source.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Set-AzOperationalInsightsDataSource) )
#### Set-AzOperationalInsightsIntelligencePack
Enables or disables the specified Intelligence Pack.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Set-AzOperationalInsightsIntelligencePack) )
#### Set-AzOperationalInsightsSavedSearch
Updates a saved search that already exists.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Set-AzOperationalInsightsSavedSearch) )
#### Set-AzOperationalInsightsStorageInsight
Updates a Storage Insight.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Set-AzOperationalInsightsStorageInsight) )
#### Set-AzOperationalInsightsWorkspace
Updates a workspace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.operationalinsights/Set-AzOperationalInsightsWorkspace) )
#### Set-AzPeerAsn
Update Contact Information(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Set-AzPeerAsn) )
#### Set-AzPeeringDirectConnectionObject
Sets or updates the Direct Connection information.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Set-AzPeeringDirectConnectionObject) )
#### Set-AzPeeringExchangeConnectionObject
Sets or updates the Exchange Connection information.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Set-AzPeeringExchangeConnectionObject) )
#### Set-AzPolicyAssignment
Modifies a policy assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzPolicyAssignment) )
#### Set-AzPolicyDefinition
Modifies a policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzPolicyDefinition) )
#### Set-AzPolicySetDefinition
Modifies a policy set definition(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzPolicySetDefinition) )
#### Set-AzPrivateDnsRecordSet
Updates/Sets a record set in a Private DNS zone.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Set-AzPrivateDnsRecordSet) )
#### Set-AzPrivateDnsVirtualNetworkLink
Updates/Sets a virtual network link associated with a private zone and a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Set-AzPrivateDnsVirtualNetworkLink) )
#### Set-AzPrivateDnsZone
Updates a Private DNS zone from a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.privatedns/Set-AzPrivateDnsZone) )
#### Set-AzPrivateEndpoint
Updates a private endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzPrivateEndpoint) )
#### Set-AzPrivateEndpointConnection
Updates a private endpoint connection state on private link service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzPrivateEndpointConnection) )
#### Set-AzPrivateLinkService
Updates a private link service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzPrivateLinkService) )
#### Set-AzPublicIpAddress
Updates a public IP address.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzPublicIpAddress) )
#### Set-AzPublicIpPrefix
Sets the Tags for an existing PublicIpPrefix(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzPublicIpPrefix) )
#### Set-AzRecoveryServicesAsrAlertSetting
Configure Azure Site Recovery notification settings (email notification) for the vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Set-AzRecoveryServicesAsrAlertSetting) )
#### Set-AzRecoveryServicesAsrReplicationProtectedItem
Sets recovery properties such as target network and virtual machine size for the specified replication protected item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Set-AzRecoveryServicesAsrReplicationProtectedItem) )
#### Set-AzRecoveryServicesAsrVaultContext
Sets the Recovery Services vault context to be used for subsequent Azure Site Recovery operations in the current PowerShell session.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Set-AzRecoveryServicesAsrVaultContext) )
#### Set-AzRecoveryServicesBackupProperty
Sets the properties for backup management.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Set-AzRecoveryServicesBackupProperty) )
#### Set-AzRecoveryServicesBackupProtectionPolicy
Modifies a Backup protection policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Set-AzRecoveryServicesBackupProtectionPolicy) )
#### Set-AzRecoveryServicesVaultContext
Sets vault context.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Set-AzRecoveryServicesVaultContext) )
#### Set-AzRedisCache
Modifies a Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Set-AzRedisCache) )
#### Set-AzRedisCacheDiagnostic
Enables diagnostics on an Azure Redis Cache.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.rediscache/Set-AzRedisCacheDiagnostic) )
#### Set-AzRelayAuthorizationRule
Updates the specified authorization rule description for the given Relay entities (Namespace/WcfRelay/HybridConnection).(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Set-AzRelayAuthorizationRule) )
#### Set-AzRelayHybridConnection
Updates the description of a HybridConnection in the specified Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Set-AzRelayHybridConnection) )
#### Set-AzRelayNamespace
Updates the description of an existing Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Set-AzRelayNamespace) )
#### Set-AzResource
Modifies a resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzResource) )
#### Set-AzResourceGroup
Modifies a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzResourceGroup) [1.1b.03](#11b03) [1.1b.04](#11b04))
#### Set-AzResourceLock
Modifies a resource lock.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzResourceLock) )
#### Set-AzRmStorageContainerImmutabilityPolicy
Creates or updates ImmutabilityPolicy of a Storage blob containers(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzRmStorageContainerImmutabilityPolicy) )
#### Set-AzRoleDefinition
Modifies a custom role in Azure RBAC.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Set-AzRoleDefinition) )
#### Set-AzRouteConfig
Updates a route configuration for a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzRouteConfig) )
#### Set-AzRouteFilter
Updates a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzRouteFilter) )
#### Set-AzRouteFilterRuleConfig
Modifies the route filter rule of a route filter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzRouteFilterRuleConfig) )
#### Set-AzRouteTable
Updates a route table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzRouteTable) [4.1d.02](#41d02))
#### Set-AzSearchService
Update an Azure Search service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.search/Set-AzSearchService) )
#### Set-AzSecurityAlert
Updates a security alert state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Set-AzSecurityAlert) )
#### Set-AzSecurityAutoProvisioningSetting
Updates automatic provisioning setting(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Set-AzSecurityAutoProvisioningSetting) )
#### Set-AzSecurityContact
Updates a security contact for a subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Set-AzSecurityContact) )
#### Set-AzSecurityPricing
Sets the pricing of Azure Security Center tier for a scope.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Set-AzSecurityPricing) )
#### Set-AzSecurityWorkspaceSetting
Updates the workspace settings for the subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Set-AzSecurityWorkspaceSetting) )
#### Set-AzServiceBusAuthorizationRule
Updates the specified authorization rule description for the given Service Bus namespace or queue or topic.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusAuthorizationRule) )
#### Set-AzServiceBusGeoDRConfigurationBreakPair
This operation disables the Disaster Recovery and stops replicating changes from primary to secondary namespaces(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusGeoDRConfigurationBreakPair) )
#### Set-AzServiceBusGeoDRConfigurationFailOver
Invokes GEO DR failover and reconfigure the alias to point to the secondary namespace(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusGeoDRConfigurationFailOver) )
#### Set-AzServiceBusNamespace
Updates the description of an existing Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusNamespace) )
#### Set-AzServiceBusQueue
Updates the description of a Service Bus queue in the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusQueue) )
#### Set-AzServiceBusRule
Updates the specified rule description for the given subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusRule) )
#### Set-AzServiceBusSubscription
Updates a subscription description for a Service Bus topic in the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusSubscription) )
#### Set-AzServiceBusTopic
Updates the description of a Service Bus topic in the specified Service Bus namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Set-AzServiceBusTopic) )
#### Set-AzServiceEndpointPolicy
Updates a service endpoint policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzServiceEndpointPolicy) )
#### Set-AzServiceEndpointPolicyDefinition
Updates a service endpoint policy definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzServiceEndpointPolicyDefinition) )
#### Set-AzServiceFabricSetting
Add or update one or multiple Service Fabric settings to the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Set-AzServiceFabricSetting) )
#### Set-AzServiceFabricUpgradeType
Change the Service Fabric upgrade type of the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Set-AzServiceFabricUpgradeType) )
#### Set-AzSnapshotDiskEncryptionKey
Sets the disk encryption key properties on a snapshot object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzSnapshotDiskEncryptionKey) )
#### Set-AzSnapshotImageReference
Sets the image reference properties on a snapshot object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzSnapshotImageReference) )
#### Set-AzSnapshotKeyEncryptionKey
Sets the key encryption key properties on a snapshot object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzSnapshotKeyEncryptionKey) )
#### Set-AzSnapshotUpdateDiskEncryptionKey
Sets the disk encryption key properties on a snapshot update object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzSnapshotUpdateDiskEncryptionKey) )
#### Set-AzSnapshotUpdateKeyEncryptionKey
Sets the key encryption key properties on a snapshot update object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzSnapshotUpdateKeyEncryptionKey) )
#### Set-AzSqlDatabase
Sets properties for a database, or moves an existing database into an elastic pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabase) )
#### Set-AzSqlDatabaseAdvisorAutoExecuteStatus
Modifies auto execute status of an Azure SQL Database Advisor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseAdvisorAutoExecuteStatus) )
#### Set-AzSqlDatabaseAudit
Changes the auditing settings for an Azure SQL database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseAudit) )
#### Set-AzSqlDatabaseAuditing
Changes the auditing settings for an Azure SQL database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseAuditing) )
#### Set-AzSqlDatabaseBackupLongTermRetentionPolicy
Sets a server long term retention policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseBackupLongTermRetentionPolicy) )
#### Set-AzSqlDatabaseBackupShortTermRetentionPolicy
Sets a backup short term retention policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseBackupShortTermRetentionPolicy) )
#### Set-AzSqlDatabaseDataMaskingPolicy
Sets data masking for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseDataMaskingPolicy) )
#### Set-AzSqlDatabaseDataMaskingRule
Sets the properties of a data masking rule for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseDataMaskingRule) )
#### Set-AzSqlDatabaseFailoverGroup
Modifies the configuration of an Azure SQL Database Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseFailoverGroup) )
#### Set-AzSqlDatabaseGeoBackupPolicy
Sets a database geo backup policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseGeoBackupPolicy) )
#### Set-AzSqlDatabaseInstanceFailoverGroup
Modifies the configuration of an Azure SQL Database Instance Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseInstanceFailoverGroup) )
#### Set-AzSqlDatabaseRecommendedActionState
Updates the state of an Azure SQL Database recommended action.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseRecommendedActionState) )
#### Set-AzSqlDatabaseSecondary
Switches a secondary database to be primary in order to initiate failover.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseSecondary) )
#### Set-AzSqlDatabaseSensitivityClassification
Sets the information types and sensitivity labels of columns in the database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseSensitivityClassification) )
#### Set-AzSqlDatabaseTransparentDataEncryption
Modifies TDE property for a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseTransparentDataEncryption) )
#### Set-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline
Sets the vulnerability assessment rule baseline.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlDatabaseVulnerabilityAssessmentRuleBaseline) )
#### Set-AzSqlElasticPool
Modifies properties of an elastic database pool in Azure SQL Database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlElasticPool) )
#### Set-AzSqlElasticPoolAdvisorAutoExecuteStatus
Updates auto execute status of an Azure SQL Elastic Pool Advisor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlElasticPoolAdvisorAutoExecuteStatus) )
#### Set-AzSqlElasticPoolRecommendedActionState
Updates the state of an Azure SQL Elastic Pool recommended action.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlElasticPoolRecommendedActionState) )
#### Set-AzSqlInstance
Sets properties for an Azure SQL Database Managed Instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlInstance) )
#### Set-AzSqlInstanceDatabaseBackupShortTermRetentionPolicy
Sets a backup short term retention policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlInstanceDatabaseBackupShortTermRetentionPolicy) )
#### Set-AzSqlInstanceDatabaseSensitivityClassification
Sets the information types and sensitivity labels of columns in the Azure SQL managed instance database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlInstanceDatabaseSensitivityClassification) )
#### Set-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline
Sets the vulnerability assessment rule baseline.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlInstanceDatabaseVulnerabilityAssessmentRuleBaseline) )
#### Set-AzSqlInstanceTransparentDataEncryptionProtector
Sets the Transparent Data Encryption (TDE) protector for a SQL managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlInstanceTransparentDataEncryptionProtector) )
#### Set-AzSqlServer
Modifies properties of a SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServer) )
#### Set-AzSqlServerActiveDirectoryAdministrator
Provisions an Azure AD administrator for SQL Server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerActiveDirectoryAdministrator) )
#### Set-AzSqlServerAdvisorAutoExecuteStatus
Updates the auto execute status of an Azure SQL Server Advisor.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerAdvisorAutoExecuteStatus) )
#### Set-AzSqlServerAudit
Changes the auditing settings of an Azure SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerAudit) )
#### Set-AzSqlServerAuditing
Changes the auditing settings of an Azure SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerAuditing) )
#### Set-AzSqlServerDisasterRecoveryConfiguration
Modifies a database server recovery configuration.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerDisasterRecoveryConfiguration) )
#### Set-AzSqlServerDnsAlias
Modifies the server to which Azure SQL Server DNS Alias is pointing(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerDnsAlias) )
#### Set-AzSqlServerFirewallRule
Modifies a firewall rule in Azure SQL Database server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerFirewallRule) )
#### Set-AzSqlServerRecommendedActionState
Updates the state of an Azure SQL Server recommended action.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerRecommendedActionState) )
#### Set-AzSqlServerTransparentDataEncryptionProtector
Sets the Transparent Data Encryption (TDE) protector for a SQL server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerTransparentDataEncryptionProtector) )
#### Set-AzSqlServerVirtualNetworkRule
Modifies the configuration of an Azure SQL Server Virtual Network Rule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Set-AzSqlServerVirtualNetworkRule) )
#### Set-AzStorageAccount
Modifies a Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageAccount) [2.1a.04](#21a04) [2.1e.01](#21e01))
#### Set-AzStorageAccountManagementPolicy
Creates or modifies the management policy of an Azure Storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageAccountManagementPolicy) )
#### Set-AzStorageBlobContent
Uploads a local file to an Azure Storage blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageBlobContent) [2.2a.01](#22a01))
#### Set-AzStorageContainerAcl
Sets the public access permission to a storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageContainerAcl) )
#### Set-AzStorageContainerStoredAccessPolicy
Sets a stored access policy for an Azure storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageContainerStoredAccessPolicy) )
#### Set-AzStorageCORSRule
Sets the CORS rules for a type of Storage service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageCORSRule) )
#### Set-AzStorageFileContent
Uploads the contents of a file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageFileContent) )
#### Set-AzStorageQueueStoredAccessPolicy
Sets a stored access policy for an Azure storage queue.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageQueueStoredAccessPolicy) )
#### Set-AzStorageServiceLoggingProperty
Modifies logging for Azure Storage services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageServiceLoggingProperty) )
#### Set-AzStorageServiceMetricsProperty
Modifies metrics properties for the Azure Storage service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageServiceMetricsProperty) )
#### Set-AzStorageShareQuota
Sets the storage capacity for a share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageShareQuota) )
#### Set-AzStorageShareStoredAccessPolicy
Updates a stored access policy on a Storage share.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageShareStoredAccessPolicy) )
#### Set-AzStorageSyncServerEndpoint
This command allows for changes on the adjustable parameters of a server endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Set-AzStorageSyncServerEndpoint) )
#### Set-AzStorageTableStoredAccessPolicy
Sets the stored access policy for an Azure storage table.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Set-AzStorageTableStoredAccessPolicy) )
#### Set-AzTrafficManagerEndpoint
Updates a Traffic Manager endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Set-AzTrafficManagerEndpoint) )
#### Set-AzTrafficManagerProfile
Updates a Traffic Manager profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.trafficmanager/Set-AzTrafficManagerProfile) )
#### Set-AzVirtualNetwork
Updates a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetwork) [4.1d.02](#41d02) [4.2b.02](#42b02) [4.3b.02](#43b02) [4.7a.02](#47a02))
#### Set-AzVirtualNetworkGateway
Updates a virtual network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkGateway) )
#### Set-AzVirtualNetworkGatewayConnection
Configures a virtual network gateway connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkGatewayConnection) )
#### Set-AzVirtualNetworkGatewayConnectionSharedKey
Configures the shared key of the virtual network gateway connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkGatewayConnectionSharedKey) )
#### Set-AzVirtualNetworkGatewayDefaultSite
Sets the default site for a virtual network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkGatewayDefaultSite) )
#### Set-AzVirtualNetworkPeering
Configures a virtual network peering.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkPeering) )
#### Set-AzVirtualNetworkSubnetConfig
Updates a subnet configuration for a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkSubnetConfig) [4.1d.02](#41d02))
#### Set-AzVirtualNetworkTap
Updates a virtual network tap.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVirtualNetworkTap) )
#### Set-AzVM
Marks a virtual machine as generalized.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVM) [3.1a.02](#31a02) [3.3e.01](#33e01))
#### Set-AzVMAccessExtension
Adds the VMAccess extension to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMAccessExtension) )
#### Set-AzVMADDomainExtension
Adds an AD domain extension to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMADDomainExtension) )
#### Set-AzVMAEMExtension
Enables support for monitoring for SAP systems.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMAEMExtension) )
#### Set-AzVMBackupExtension
Sets the backup extension properties on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMBackupExtension) )
#### Set-AzVMBginfoExtension
Adds the BGInfo extension to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMBginfoExtension) )
#### Set-AzVMBootDiagnostic
Modifies boot diagnostics properties of a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMBootDiagnostic) )
#### Set-AzVMChefExtension
Adds a Chef extension to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMChefExtension) )
#### Set-AzVMCustomScriptExtension
Adds a custom script extension to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMCustomScriptExtension) [3.3f.04](#33f04))
#### Set-AzVMDataDisk
Modifies properties of a virtual machine data disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMDataDisk) [3.1e.02](#31e02))
#### Set-AzVMDiagnosticsExtension
Configures the Azure diagnostics extension on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMDiagnosticsExtension) )
#### Set-AzVMDiskEncryptionExtension
Enables encryption on a running IaaS virtual machine in Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMDiskEncryptionExtension) )
#### Set-AzVMDscExtension
Configures the DSC extension on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMDscExtension) [3.3f.03](#33f03))
#### Set-AzVMExtension
Updates extension properties or adds an extension to a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMExtension) [4.4c.02](#44c02) [4.6c.01](#46c01))
#### Set-AzVMOperatingSystem
Sets operating system properties for a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMOperatingSystem) [3.1a.02](#31a02))
#### Set-AzVMOSDisk
Sets the operating system disk properties on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMOSDisk) [3.1a.02](#31a02) [3.1a.34](#31a34))
#### Set-AzVMPlan
Sets the Marketplace plan information on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMPlan) )
#### Set-AzVMSourceImage
Specifies the image for a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMSourceImage) [3.1a.02](#31a02) [3.1a.36](#31a36))
#### Set-AzVMSqlServerExtension
Sets the Azure SQL Server extension on a virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVMSqlServerExtension) )
#### Set-AzVmss
Sets specific actions on a specified VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmss) )
#### Set-AzVmssBootDiagnostic
Sets the virtual machine scale set boot diagnostics profile.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmssBootDiagnostic) )
#### Set-AzVmssDiskEncryptionExtension
Enables disk encryption on a VM scale set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmssDiskEncryptionExtension) )
#### Set-AzVmssOsProfile
Sets the VMSS operating system profile properties.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmssOsProfile) [3.1h.02](#31h02))
#### Set-AzVmssRollingUpgradePolicy
Sets the VMSS rolling upgrade policy properties.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmssRollingUpgradePolicy) )
#### Set-AzVmssStorageProfile
Sets the storage profile properties for the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmssStorageProfile) [3.1h.02](#31h02))
#### Set-AzVmssVM
Modifies the state of a VMSS instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Set-AzVmssVM) )
#### Set-AzVpnClientIpsecParameter
Sets the vpn ipsec parameters for existing virtual network gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Set-AzVpnClientIpsecParameter) )
#### Set-AzWcfRelay
Updates the description of a WcfRelay in the specified Relay namespace.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Set-AzWcfRelay) )
#### Set-AzWebApp
Modifies an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Set-AzWebApp) )
#### Set-AzWebAppSlot
Modifies an Azure Web App slot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Set-AzWebAppSlot) )
#### Set-AzWebAppSlotConfigName
Set Web App Slot Config names(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Set-AzWebAppSlotConfigName) )
#### Split-AzReservation
Split a Reservation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Split-AzReservation) )
#### Start-AzAksDashboard
Create a Kubectl SSH tunnel to the managed cluster's dashboard.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/Start-AzAksDashboard) )
#### Start-AzApplicationGateway
Starts an application gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Start-AzApplicationGateway) )
#### Start-AzAutomationDscCompilationJob
Compiles a DSC configuration in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Start-AzAutomationDscCompilationJob) )
#### Start-AzAutomationDscNodeConfigurationDeployment
Deploys a DSC Node configuration in Automation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Start-AzAutomationDscNodeConfigurationDeployment) )
#### Start-AzAutomationRunbook
Starts a runbook job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Start-AzAutomationRunbook) )
#### Start-AzAutomationSourceControlSyncJob
Starts an Azure Automation source control sync job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Start-AzAutomationSourceControlSyncJob) )
#### Start-AzBatchComputeNodeServiceLogUpload
Upload compute node service log files to an Azure Storage container.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Start-AzBatchComputeNodeServiceLogUpload) )
#### Start-AzBatchPoolResize
Starts to resize a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Start-AzBatchPoolResize) )
#### Start-AzCdnEndpoint
Starts a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Start-AzCdnEndpoint) )
#### Start-AzDataFactoryV2IntegrationRuntime
Starts a managed dedicated integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Start-AzDataFactoryV2IntegrationRuntime) )
#### Start-AzDataFactoryV2Trigger
Starts a trigger in a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Start-AzDataFactoryV2Trigger) )
#### Start-AzDataMigrationService
Starts an instance of the Azure Database Migration Service in a stopped state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Start-AzDataMigrationService) )
#### Start-AzHDInsightJob
Starts a defined Azure HDInsight job on a specified cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Start-AzHDInsightJob) )
#### Start-AzJitNetworkAccessPolicy
Invokes a temporary network access request.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.security/Start-AzJitNetworkAccessPolicy) )
#### Start-AzLogicApp
Runs a logic app in a resource group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Start-AzLogicApp) )
#### Start-AzNetworkWatcherConnectionMonitor
Start a connection monitor(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Start-AzNetworkWatcherConnectionMonitor) )
#### Start-AzNetworkWatcherResourceTroubleshooting
Starts troubleshooting on a Networking resource in Azure.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Start-AzNetworkWatcherResourceTroubleshooting) [4.6d.02](#46d02))
#### Start-AzPolicyRemediation
Creates and starts a policy remediation for a policy assignment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Start-AzPolicyRemediation) )
#### Start-AzRecoveryServicesAsrApplyRecoveryPoint
Changes a recovery point for a failed over protected item before commiting the failover operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrApplyRecoveryPoint) )
#### Start-AzRecoveryServicesAsrCommitFailoverJob
Starts the commit failover action for a Site Recovery object.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrCommitFailoverJob) )
#### Start-AzRecoveryServicesAsrPlannedFailoverJob
Starts a planned failover operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrPlannedFailoverJob) )
#### Start-AzRecoveryServicesAsrResynchronizeReplicationJob
Starts replication resynchronization.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrResynchronizeReplicationJob) )
#### Start-AzRecoveryServicesAsrSwitchProcessServerJob
Switch replication from one Process server to another for load balancing.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrSwitchProcessServerJob) )
#### Start-AzRecoveryServicesAsrTestFailoverCleanupJob
Starts the test failover cleanup operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrTestFailoverCleanupJob) )
#### Start-AzRecoveryServicesAsrTestFailoverJob
Starts a test failover operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrTestFailoverJob) )
#### Start-AzRecoveryServicesAsrUnplannedFailoverJob
Starts a unplanned failover operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Start-AzRecoveryServicesAsrUnplannedFailoverJob) )
#### Start-AzServiceBusMigration
Creates a new Migration configuration and starts migrating entities from Standard to Premium namespaces(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Start-AzServiceBusMigration) )
#### Start-AzSqlDatabaseExecuteIndexRecommendation
Starts the workflow that runs a recommended index operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Start-AzSqlDatabaseExecuteIndexRecommendation) )
#### Start-AzSqlDatabaseVulnerabilityAssessmentScan
Starts a vulnerability assessment scan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Start-AzSqlDatabaseVulnerabilityAssessmentScan) )
#### Start-AzSqlInstanceDatabaseVulnerabilityAssessmentScan
Starts a vulnerability assessment scan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Start-AzSqlInstanceDatabaseVulnerabilityAssessmentScan) )
#### Start-AzSqlSyncGroupSync
Starts a sync group synchronization.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Start-AzSqlSyncGroupSync) )
#### Start-AzStorageBlobCopy
Starts to copy a blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Start-AzStorageBlobCopy) [2.1f.02](#21f02))
#### Start-AzStorageBlobIncrementalCopy
Start an Incremental copy operation from a Page blob snapshot to the specified destination Page blob.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Start-AzStorageBlobIncrementalCopy) )
#### Start-AzStorageFileCopy
Starts to copy a source file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Start-AzStorageFileCopy) )
#### Start-AzStreamAnalyticsJob
Starts a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Start-AzStreamAnalyticsJob) )
#### Start-AzVM
Starts an Azure virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Start-AzVM) )
#### Start-AzVmss
Starts the VMSS or a set of virtual machines within the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Start-AzVmss) )
#### Start-AzVmssRollingOSUpgrade
Starts a rolling upgrade to move all virtual machine scale set instances to the latest available Platform Image OS version.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Start-AzVmssRollingOSUpgrade) )
#### Start-AzWebApp
Starts an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Start-AzWebApp) )
#### Start-AzWebAppSlot
Starts an Azure Web App slot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Start-AzWebAppSlot) )
#### Stop-AzAksDashboard
Stop the Kubectl SSH tunnel created in Start-AzKubernetesDashboard.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.aks/Stop-AzAksDashboard) )
#### Stop-AzApplicationGateway
Stops an application gateway(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Stop-AzApplicationGateway) )
#### Stop-AzAutomationDscNodeConfigurationDeployment
Stops a DSC Node configuration deployment in Automation. It only stops the current deployment job but does not unassign already assigned node configurations.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Stop-AzAutomationDscNodeConfigurationDeployment) )
#### Stop-AzAutomationJob
Stops an Automation job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Stop-AzAutomationJob) )
#### Stop-AzBatchCertificateDeletion
Cancels a failed deletion of a certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Stop-AzBatchCertificateDeletion) )
#### Stop-AzBatchJob
Stops a Batch job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Stop-AzBatchJob) )
#### Stop-AzBatchJobSchedule
Stops a Batch job schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Stop-AzBatchJobSchedule) )
#### Stop-AzBatchPoolResize
Stops a pool resize operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Stop-AzBatchPoolResize) )
#### Stop-AzBatchTask
Stops a Batch task.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Stop-AzBatchTask) )
#### Stop-AzCdnEndpoint
Stops the CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Stop-AzCdnEndpoint) )
#### Stop-AzDataBoxJob
Cancels an ongoing databox job if the job is in cancellable state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.databox/Stop-AzDataBoxJob) )
#### Stop-AzDataFactoryV2IntegrationRuntime
Stops a managed dedicated integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Stop-AzDataFactoryV2IntegrationRuntime) )
#### Stop-AzDataFactoryV2PipelineRun
Stops a pieline run in a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Stop-AzDataFactoryV2PipelineRun) )
#### Stop-AzDataFactoryV2Trigger
Stops a trigger in a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Stop-AzDataFactoryV2Trigger) )
#### Stop-AzDataLakeAnalyticsJob
Cancels a job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Stop-AzDataLakeAnalyticsJob) )
#### Stop-AzDataMigrationService
Stops an instance of the Azure Database Migration Service that is in a running state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Stop-AzDataMigrationService) )
#### Stop-AzDataMigrationTask
Stops an Azure Database Migration Service task that is in a running state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datamigration/Stop-AzDataMigrationTask) )
#### Stop-AzDeployment
Cancal a running deployment(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Stop-AzDeployment) )
#### Stop-AzDeploymentManagerRollout
Stops the rollout.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deploymentmanager/Stop-AzDeploymentManagerRollout) )
#### Stop-AzHDInsightJob
Stops a specified running job on a cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Stop-AzHDInsightJob) )
#### Stop-AzKeyVaultCertificateOperation
Cancels a certificate operation in key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Stop-AzKeyVaultCertificateOperation) )
#### Stop-AzLogicAppRun
Cancels a run of a logic app.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Stop-AzLogicAppRun) )
#### Stop-AzNetworkWatcherConnectionMonitor
Stop a connection monitor(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Stop-AzNetworkWatcherConnectionMonitor) )
#### Stop-AzNetworkWatcherPacketCapture
Stops a running packet capture session(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Stop-AzNetworkWatcherPacketCapture) [4.6c.10](#46c10))
#### Stop-AzPolicyRemediation
Cancels an in-progress policy remediation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.policyinsights/Stop-AzPolicyRemediation) )
#### Stop-AzRecoveryServicesAsrJob
Stops an Azure Site Recovery job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Stop-AzRecoveryServicesAsrJob) )
#### Stop-AzRecoveryServicesBackupJob
Cancels a running job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Stop-AzRecoveryServicesBackupJob) )
#### Stop-AzResourceGroupDeployment
Cancels a resource group deployment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Stop-AzResourceGroupDeployment) )
#### Stop-AzServiceBusMigration
{{Fill in the Synopsis}}(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Stop-AzServiceBusMigration) )
#### Stop-AzSqlDatabaseActivity
Cancels the asynchronous updates operation on the database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Stop-AzSqlDatabaseActivity) )
#### Stop-AzSqlDatabaseExecuteIndexRecommendation
Stops the workflow that runs a recommended index operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Stop-AzSqlDatabaseExecuteIndexRecommendation) )
#### Stop-AzSqlElasticPoolActivity
Cancels the asynchronous update operation on an elastic pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Stop-AzSqlElasticPoolActivity) )
#### Stop-AzSqlSyncGroupSync
Stops a sync group synchronization.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Stop-AzSqlSyncGroupSync) )
#### Stop-AzStorageBlobCopy
Stops a copy operation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Stop-AzStorageBlobCopy) )
#### Stop-AzStorageFileCopy
Stops a copy operation to the specified destination file.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Stop-AzStorageFileCopy) )
#### Stop-AzStreamAnalyticsJob
Stops a Stream Analytics job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Stop-AzStreamAnalyticsJob) )
#### Stop-AzVM
Stops an Azure virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Stop-AzVM) [3.3b.02](#33b02))
#### Stop-AzVmss
Stops the VMSS or a set of virtual machines within the VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Stop-AzVmss) )
#### Stop-AzVmssRollingUpgrade
Cancels the current virtual machine scale set rolling upgrade.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Stop-AzVmssRollingUpgrade) )
#### Stop-AzWebApp
Stops an Azure Web App.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Stop-AzWebApp) )
#### Stop-AzWebAppSlot
Stops an Azure Web App slot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Stop-AzWebAppSlot) )
#### Submit-AzDataLakeAnalyticsJob
Submits a job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Submit-AzDataLakeAnalyticsJob) )
#### Submit-AzHDInsightScriptAction
Submits a new script action to an Azure HDInsight cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Submit-AzHDInsightScriptAction) )
#### Suspend-AzAnalysisServicesServer
Suspends an instance of Analysis Services server(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Suspend-AzAnalysisServicesServer) )
#### Suspend-AzAutomationJob
Suspends an Automation job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Suspend-AzAutomationJob) )
#### Suspend-AzDataFactoryPipeline
Suspends a pipeline in Azure Data Factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Suspend-AzDataFactoryPipeline) )
#### Suspend-AzKustoCluster
Suspend an existing Kusto cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Suspend-AzKustoCluster) )
#### Suspend-AzPowerBIEmbeddedCapacity
Suspends an instance of PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Suspend-AzPowerBIEmbeddedCapacity) )
#### Suspend-AzSqlDatabase
Suspends a SQL Data Warehouse database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Suspend-AzSqlDatabase) )
#### Switch-AzSqlDatabaseFailoverGroup
Executes a failover of an Azure SQL Database Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Switch-AzSqlDatabaseFailoverGroup) )
#### Switch-AzSqlDatabaseInstanceFailoverGroup
Executes a failover of an Azure SQL Database Instance Failover Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Switch-AzSqlDatabaseInstanceFailoverGroup) )
#### Switch-AzWebAppSlot
Swap two slots with a Web App(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.websites/Switch-AzWebAppSlot) )
#### Sync-AzAnalysisServicesInstance
Synchronizes a specified database on the specified instance of Analysis Services server to all the query scaleout instances in the currently logged in Environment as specified in Add-AzAnalysisServicesAccount command(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Sync-AzAnalysisServicesInstance) )
#### Sync-AzDataFactoryV2IntegrationRuntimeCredential
Synchronizes credentials among integration runtime nodes.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Sync-AzDataFactoryV2IntegrationRuntimeCredential) )
#### Sync-AzMediaServiceStorageKey
Synchronizes storage account keys for a storage account associated with the media service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.media/Sync-AzMediaServiceStorageKey) )
#### Test-AzAnalysisServicesServer
Tests the existence of an instance of Analysis Services server(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.analysisservices/Test-AzAnalysisServicesServer) )
#### Test-AzBatchAutoScale
Gets the result of an automatic scaling formula on a pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.batch/Test-AzBatchAutoScale) )
#### Test-AzCdnCustomDomain
Checks whether a custom domain can be added to an endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Test-AzCdnCustomDomain) )
#### Test-AzContainerRegistryNameAvailability
Checks the availability of a container registry name.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Test-AzContainerRegistryNameAvailability) )
#### Test-AzContainerRegistryWebhook
Triggers a webhook ping event.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Test-AzContainerRegistryWebhook) )
#### Test-AzDataLakeAnalyticsAccount
Checks for the existence of a Data Lake Analytics account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Test-AzDataLakeAnalyticsAccount) )
#### Test-AzDataLakeAnalyticsCatalogItem
Checks for the existence of a catalog item.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Test-AzDataLakeAnalyticsCatalogItem) )
#### Test-AzDataLakeStoreAccount
Tests the existence of a Data Lake Store account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Test-AzDataLakeStoreAccount) )
#### Test-AzDataLakeStoreItem
Tests the existence of a file or folder in Data Lake Store.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakestore/Test-AzDataLakeStoreItem) )
#### Test-AzDeployment
Validates a deployment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Test-AzDeployment) )
#### Test-AzDnsAvailability
Checks whether a domain name in the cloudapp.azure.com zone is available for use.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Test-AzDnsAvailability) )
#### Test-AzEventHubName
Checks the Availability of the given NameSpace Name or Alias (DR Configuration Name)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventhub/Test-AzEventHubName) )
#### Test-AzIotHubRoute
Test routes in IoT Hub(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Test-AzIotHubRoute) )
#### Test-AzKustoClusterName
Check if a given Kusto cluster name is available.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Test-AzKustoClusterName) )
#### Test-AzLogicApp
Validates a logic app definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.logicapp/Test-AzLogicApp) )
#### Test-AzMlOpClusterSystemServicesUpdateAvailability
Checks if there are updates available for the system services associated with an operationalization cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Test-AzMlOpClusterSystemServicesUpdateAvailability) )
#### Test-AzNetworkWatcherConnectivity
Returns connectivity information for a specified source VM and a destination.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Test-AzNetworkWatcherConnectivity) [4.6e.02](#46e02))
#### Test-AzNetworkWatcherIPFlow
Returns whether the packet is allowed or denied to or from a particular destination.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Test-AzNetworkWatcherIPFlow) [4.6c.04](#46c04))
#### Test-AzPowerBIEmbeddedCapacity
Tests the existence of an instance of PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Test-AzPowerBIEmbeddedCapacity) )
#### Test-AzPrivateIPAddressAvailability
Test availability of a private IP address in a virtual network.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Test-AzPrivateIPAddressAvailability) )
#### Test-AzPrivateLinkServiceVisibility
Checks whether a private link service is visible for current use.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Test-AzPrivateLinkServiceVisibility) )
#### Test-AzRelayName
Checks the Availability of the given NameSpace Name(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.relay/Test-AzRelayName) )
#### Test-AzResourceGroupDeployment
Validates a resource group deployment.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Test-AzResourceGroupDeployment) )
#### Test-AzServiceBusName
Checks the Availability of the given NameSpace Name or Alias (DR Configuration Name)(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicebus/Test-AzServiceBusName) )
#### Test-AzStreamAnalyticsFunction
Tests whether Stream Analytics can connect to a function.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Test-AzStreamAnalyticsFunction) )
#### Test-AzStreamAnalyticsInput
Tests the connection status of an input.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Test-AzStreamAnalyticsInput) )
#### Test-AzStreamAnalyticsOutput
Tests the connection status of an output.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.streamanalytics/Test-AzStreamAnalyticsOutput) )
#### Test-AzVMAEMExtension
Checks the configuration of the AEM extension.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Test-AzVMAEMExtension) )
#### Undo-AzKeyVaultCertificateRemoval
Recovers a deleted certificate in a key vault into an active state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Undo-AzKeyVaultCertificateRemoval) )
#### Undo-AzKeyVaultKeyRemoval
Recovers a deleted key in a key vault into an active state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Undo-AzKeyVaultKeyRemoval) )
#### Undo-AzKeyVaultManagedStorageAccountRemoval
Recovers a previously deleted KeyVault-managed storage account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Undo-AzKeyVaultManagedStorageAccountRemoval) )
#### Undo-AzKeyVaultManagedStorageSasDefinitionRemoval
Recovers a previously deleted KeyVault-managed storage SAS definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Undo-AzKeyVaultManagedStorageSasDefinitionRemoval) )
#### Undo-AzKeyVaultRemoval
Recovers a deleted key vault into an active state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Undo-AzKeyVaultRemoval) )
#### Undo-AzKeyVaultSecretRemoval
Recovers a deleted secret in a key vault into an active state.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Undo-AzKeyVaultSecretRemoval) )
#### Uninstall-AzureRm
Removes all AzureRm modules from a machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.accounts/Uninstall-AzureRm) )
#### Unpublish-AzCdnEndpointContent
Purges a CDN endpoint.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cdn/Unpublish-AzCdnEndpointContent) )
#### Unregister-AzAutomationDscNode
Removes a DSC node from management by an Automation account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Unregister-AzAutomationDscNode) )
#### Unregister-AzAutomationScheduledRunbook
Removes an association between a runbook and a schedule.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Unregister-AzAutomationScheduledRunbook) )
#### Unregister-AzRecoveryServicesBackupContainer
Unregisters a Windows Server or other container from the vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Unregister-AzRecoveryServicesBackupContainer) )
#### Unregister-AzRecoveryServicesBackupManagementServer
Unregisters a SCDPM server or Backup server from the vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Unregister-AzRecoveryServicesBackupManagementServer) )
#### Unregister-AzResourceProvider
Unregisters a resource provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Unregister-AzResourceProvider) )
#### Unregister-AzStorageSyncServer
Warning: Unregistering a server will result in cascading deletes of all server endpoints on this server. This command will unregister a server from it's storage sync service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storagesync/Unregister-AzStorageSyncServer) )
#### Update-AzActionRule
Updates action rule properties.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Update-AzActionRule) )
#### Update-AzADApplication
Updates an existing azure active directory application.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Update-AzADApplication) )
#### Update-AzADServicePrincipal
Updates an existing azure active directory service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Update-AzADServicePrincipal) )
#### Update-AzADUser
Updates an existing active directory user.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Update-AzADUser) )
#### Update-AzAlertState
Updates alert state(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Update-AzAlertState) )
#### Update-AzApiManagementApiRelease
Updates a particular Api Release.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Update-AzApiManagementApiRelease) )
#### Update-AzApiManagementCache
updates a cache in Api Management service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Update-AzApiManagementCache) )
#### Update-AzApiManagementRegion
Updates existing deployment region in PsApiManagement instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.apimanagement/Update-AzApiManagementRegion) )
#### Update-AzAutomationSourceControl
Updates an Azure Automation source control.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.automation/Update-AzAutomationSourceControl) )
#### Update-AzAvailabilitySet
Updates an availability set.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzAvailabilitySet) )
#### Update-AzCognitiveServicesAccountNetworkRuleSet
Update the NetworkRule property of a Cognitive Services account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.cognitiveservices/Update-AzCognitiveServicesAccountNetworkRuleSet) )
#### Update-AzContainerRegistry
Updates a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Update-AzContainerRegistry) )
#### Update-AzContainerRegistryCredential
Regenerates a login credential for a container registry.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Update-AzContainerRegistryCredential) )
#### Update-AzContainerRegistryWebhook
Updates a container registry webhook.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.containerregistry/Update-AzContainerRegistryWebhook) )
#### Update-AzContainerService
Updates the state of a container service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzContainerService) )
#### Update-AzDataFactoryV2
Updates the properties of a data factory.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Update-AzDataFactoryV2) )
#### Update-AzDataFactoryV2IntegrationRuntime
Updates an integration runtime.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Update-AzDataFactoryV2IntegrationRuntime) )
#### Update-AzDataFactoryV2IntegrationRuntimeNode
Updates self-hosted integration runtime node.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datafactory/Update-AzDataFactoryV2IntegrationRuntimeNode) )
#### Update-AzDataLakeAnalyticsComputePolicy
Updates a Data Lake Analytics compute policy rule for a specific AAD entity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Update-AzDataLakeAnalyticsComputePolicy) )
#### Update-AzDevSpacesController
Update the DevSpaces controller to add tags.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.devspaces/Update-AzDevSpacesController) )
#### Update-AzDisk
Updates a disk.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzDisk) )
#### Update-AzEventGridSubscription
Update the properties of an Event Grid event subscription.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.eventgrid/Update-AzEventGridSubscription) )
#### Update-AzFrontDoorWafPolicy
Update WAF policy(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.frontdoor/Update-AzFrontDoorWafPolicy) )
#### Update-AzGallery
Update a gallery.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzGallery) )
#### Update-AzGalleryImageDefinition
Update a gallery image definition.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzGalleryImageDefinition) )
#### Update-AzGalleryImageVersion
Update a gallery image version.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzGalleryImageVersion) )
#### Update-AzImage
Updates an image.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzImage) )
#### Update-AzIoTDeviceProvisioningService
Update an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Update-AzIoTDeviceProvisioningService) )
#### Update-AzIoTDeviceProvisioningServiceAccessPolicy
Update a shared access policy in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Update-AzIoTDeviceProvisioningServiceAccessPolicy) )
#### Update-AzIoTDeviceProvisioningServiceLinkedHub
Update a linked IoT hub in an Azure IoT Hub device provisioning service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.deviceprovisioningservices/Update-AzIoTDeviceProvisioningServiceLinkedHub) )
#### Update-AzIotHub
Update an Azure IoT Hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.iothub/Update-AzIotHub) )
#### Update-AzKeyVaultCertificate
Modifies editable attributes of a certificate.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Update-AzKeyVaultCertificate) )
#### Update-AzKeyVaultKey
Updates the attributes of a key in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Update-AzKeyVaultKey) )
#### Update-AzKeyVaultManagedStorageAccount
Update editable attributes of a Key Vault managed Azure Storage Account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Update-AzKeyVaultManagedStorageAccount) )
#### Update-AzKeyVaultManagedStorageAccountKey
Regenerates the specified key of Key Vault managed Azure Storage Account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Update-AzKeyVaultManagedStorageAccountKey) )
#### Update-AzKeyVaultNetworkRuleSet
Updates the network rule set on a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Update-AzKeyVaultNetworkRuleSet) )
#### Update-AzKeyVaultSecret
Updates attributes of a secret in a key vault.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.keyvault/Update-AzKeyVaultSecret) )
#### Update-AzKustoCluster
Update an existing Kusto cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Update-AzKustoCluster) )
#### Update-AzKustoDatabase
Update an existing Kusto database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.kusto/Update-AzKustoDatabase) )
#### Update-AzManagementGroup
Updates a Management Group(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.resources/Update-AzManagementGroup) )
#### Update-AzManagementPartner
Updates the Microsoft Partner Network(MPN) ID of the current authenticated user or service principal.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.managementpartner/Update-AzManagementPartner) )
#### Update-AzMlCommitmentPlan
Updates properties of an existing commitment plan resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Update-AzMlCommitmentPlan) )
#### Update-AzMlOpClusterSystemService
Starts an update on the operationalization cluster's system services.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Update-AzMlOpClusterSystemService) )
#### Update-AzMlWebService
Updates properties of an existing web service resource.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.machinelearning/Update-AzMlWebService) )
#### Update-AzNetAppFilesAccount
Amend the properties of an Azure NetApp Files (ANF) account.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Update-AzNetAppFilesAccount) )
#### Update-AzNetAppFilesPool
Updates an Azure NetApp Files (ANF) pool.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Update-AzNetAppFilesPool) )
#### Update-AzNetAppFilesVolume
Updates an Azure NetApp Files (ANF) volume.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.netappfiles/Update-AzNetAppFilesVolume) )
#### Update-AzPeering
Sets the Peering. Use this Command in conjunction with Set-AzDirectPeeringConnectionObject or Set-AzExchangePeeringConnectionObject.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.peering/Update-AzPeering) )
#### Update-AzPowerBIEmbeddedCapacity
Modifies an instance of PowerBI Embedded Capacity.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.powerbiembedded/Update-AzPowerBIEmbeddedCapacity) )
#### Update-AzRecoveryServicesAsrMobilityService
Push mobility service agent updates to protected machines.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrMobilityService) )
#### Update-AzRecoveryServicesAsrNetworkMapping
Updates the specified azure site recovery network mapping.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrNetworkMapping) )
#### Update-AzRecoveryServicesAsrPolicy
Updates an Azure Site Recovery replication policy.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrPolicy) )
#### Update-AzRecoveryServicesAsrProtectionDirection
Updates the replication direction for the specified replication protected item or recovery plan. Used to re-protect/reverse replicate a failed over replicated item or recovery plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrProtectionDirection) )
#### Update-AzRecoveryServicesAsrRecoveryPlan
Updates the contents of an Azure Site recovery plan.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrRecoveryPlan) )
#### Update-AzRecoveryServicesAsrServicesProvider
Refreshes (Refresh server) the information received from the Azure Site Recovery Services Provider.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrServicesProvider) )
#### Update-AzRecoveryServicesAsrvCenter
Update discovery details for a registered vCenter.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Update-AzRecoveryServicesAsrvCenter) )
#### Update-AzReservation
Update a Reservation.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.reservations/Update-AzReservation) )
#### Update-AzRmStorageContainer
Modifies a Storage blob container(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Update-AzRmStorageContainer) )
#### Update-AzServiceFabricDurability
Update the durability tier or VmSku of a node type in the cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Update-AzServiceFabricDurability) )
#### Update-AzServiceFabricReliability
Update the reliability tier of the primary node type in a cluster.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.servicefabric/Update-AzServiceFabricReliability) )
#### Update-AzSmartGroupState
Updates smart group state(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.alertsmanagement/Update-AzSmartGroupState) )
#### Update-AzSnapshot
Updates a snapshot.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzSnapshot) )
#### Update-AzSqlDatabaseAdvancedThreatProtectionSettings
Sets a advanced threat protection settings on a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlDatabaseAdvancedThreatProtectionSettings) )
#### Update-AzSqlDatabaseVulnerabilityAssessmentSetting
Updates the vulnerability assessment settings of a database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlDatabaseVulnerabilityAssessmentSetting) )
#### Update-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting
Updates the vulnerability assessment settings of a managed database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlInstanceDatabaseVulnerabilityAssessmentSetting) )
#### Update-AzSqlInstanceVulnerabilityAssessmentSetting
Updates the vulnerability assessment settings of a managed instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlInstanceVulnerabilityAssessmentSetting) )
#### Update-AzSqlServerAdvancedThreatProtectionSettings
Sets a advanced threat protection settings on a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlServerAdvancedThreatProtectionSettings) )
#### Update-AzSqlServerVulnerabilityAssessmentSetting
Updates the vulnerability assessment settings of a server.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlServerVulnerabilityAssessmentSetting) )
#### Update-AzSqlSyncGroup
Updates an Azure SQL Database Sync Group.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlSyncGroup) )
#### Update-AzSqlSyncMember
Updates an Azure SQL Database Sync Member.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlSyncMember) )
#### Update-AzSqlSyncSchema
Update the sync schema for a sync member database or a sync hub database.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.sql/Update-AzSqlSyncSchema) )
#### Update-AzStorageAccountNetworkRuleSet
Update the NetworkRule property of a Storage account(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Update-AzStorageAccountNetworkRuleSet) )
#### Update-AzStorageBlobServiceProperty
Modifies the service properties for the Azure Storage Blob service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Update-AzStorageBlobServiceProperty) )
#### Update-AzStorageServiceProperty
Modifies the properties for the Azure Storage service.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.storage/Update-AzStorageServiceProperty) )
#### Update-AzVirtualHub
Updates a virtual hub.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Update-AzVirtualHub) )
#### Update-AzVirtualWan
Updates an Azure Virtual WAN.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Update-AzVirtualWan) )
#### Update-AzVM
Updates the state of an Azure virtual machine.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzVM) [3.1c.01](#31c01) [3.1e.02](#31e02) [3.3a.02](#33a02) [3.3c.02](#33c02))
#### Update-AzVmss
Updates the state of a VMSS.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzVmss) )
#### Update-AzVmssInstance
Starts a manual upgrade of the VMSS instance.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzVmssInstance) )
#### Update-AzVmssVM
Updates the state of a Vmss VM.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.compute/Update-AzVmssVM) )
#### Update-AzVpnConnection
Updates a VPN connection.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Update-AzVpnConnection) )
#### Update-AzVpnGateway
Updates a scalable VPN gateway.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Update-AzVpnGateway) )
#### Update-AzVpnSite
Updates a VPN site.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.network/Update-AzVpnSite) )
#### Use-AzHDInsightCluster
Selects a cluster to be used with the Invoke-RmAzureHDInsightHiveJob cmdlet.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Use-AzHDInsightCluster) )
#### Wait-AzDataLakeAnalyticsJob
Waits for a job to complete.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.datalakeanalytics/Wait-AzDataLakeAnalyticsJob) )
#### Wait-AzHDInsightJob
Waits for the completion or failure of a specified job.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.hdinsight/Wait-AzHDInsightJob) )
#### Wait-AzRecoveryServicesBackupJob
Waits for a Backup job to finish.(refs [MD](https://docs.microsoft.com/en-us/powershell/module/az.recoveryservices/Wait-AzRecoveryServicesBackupJob) )
