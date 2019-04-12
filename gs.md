Google Apps Scripts

Several ways of making a Hello World application
- Print to `Logger.log`
- Writing to a new file
  `DocumentApp.create('New file').getBody().appendParagraph('Hello World'))` (ud1.003.gs)
  `SpreadsheetApp.create('New file').`
- Using a UiApp application within a Spreadsheet (deprectaed)
  `UiApp.createApplication().add(app.createLabel('Hello World!'))` (or1.11.gs)
- Rendering an HTML sidebar in a Document


#   O'Reilly
3 ways to create a UI
1. Pop-up window or sidebar in a spreadsheet
2. Webpage or web app because the UI is accessed from a special URL hosted in Google's cloud
3. Gadget in a Google Sites page

## HtmlService
2 ways of displaying content from an HTML file

#   Udemy (Google Apps Script Complete Course - Beginner to Advanced)
- 1.003 Apps Script power example
- 1.004 Source code
- 1.005 IDE
- Variables declared in other script files in the same project are accessible by other files.
- Tour of options in menu
- 1.006 First script using online IDE and Google script
- Debugging and running script
  - Each service has classes, attributes, and methods
  URLs
  - `https://developers.google.com/apps-script/reference` Reference for services
  - `https://developers.google.com/apps-script/reference/document` DocumentApp class
  - `https://myaccount.google.com/permissions` Permissions granted to scripts
- `Logger.log()`
Using debugger mode to step through iterations of a loop
- 1.007 Google Script Classes
- `https://developers.google.com/apps-script/reference/calendar/`
- `https://developers.google.com/apps-script/reference/document/document-app` Document > DocumentApp
Bound vs standalone
You have to choose which function to run from the dropdown
- 1.009 JavaScript Intro
Fundamentals of JS
- 1.010 Source Code
- 2.011 Explore Document =- Class DocumentApp
- 2.012 DocumentApp Class overview
- 2.013 Get Document Contents
- `.getText()`
- `LanguageApp.translate(text, sourceLanguage, targetLanguage)`
- 2.014 Document body contents
- 2.015 Source code 7 class documentapp
- 2.016 Document Body Updates
Passing an object with `Attribute` enums as properties and values to style text
- 2.017 Document Body Children
- 2.018 Source Code 10
- 2.019 Document Classes and Methods
- 2.020 Source Code 11
- 2.021 Simple Copy Doc Script
- 2.022 Source Code 12
- 2.023 DocumentApp Bound Script
- 2.024 Base Values within Script
- 2.025 HTML in Google Documents
- 2.026 Bound Content Interaction
- 2.027 Ranged elements in Document
- 2.028 Translate Selected Content
- 2.029 Source Code 18
- 2.030 Search Content Replace With
- 2.031 Find Content Update Attributes
- 2.032 Content Selection Exercise
- 2.033 Source Code 21
- 2.034 DocumentApp Exercise
- 2.035 Source Code 22
- 2.036 DocumentApp Create Content
- 2.037 Insert Image DocumentApp
- 2.038 DocumentApp Template Exercise
- 2.039 Source Code 25
- 3.040 StandAlone SpreadsheetApp
  - `.getRange()`
- 3.041 Google SpreadSheetApp Methods CheatSheet
- 3.042 Creating Content and Styling
- 3.043 Spreadsheet data to Doc Table
- 3.044 Spreadsheet data dynamic
- 3.045 Spreadsheet Tracker Exercise
- 3.046 SpreadSheet Sheet Class
- 3.047 From one sheet to another
- 3.048 Source Code 33
- 3.049 Bound Spreadsheet App
- 3.050 Google Sheets Functions
- 3.051 Source Code
- 3.052 UI menu options Spreadsheet
- 3.053 Spreadsheet UI Sidebar Modal
- 3.054 Get Selected Content
- 3.055 Exercise Cell Selection Add to Sheet
- 3.056 Range to another sheet CopyTo
- 3.057 Selecting Cell Values Loops
- 3.058 Source Code
- 3.059 Sidebar content HTML
- 3.060 Script more UI options
- 3.061 HTML to backend GS code
- 3.062 GoogleSheet content to clientside
- 3.063 Source Code
- 3.064 Triggers onEdit onChange
- 3.065 Source
- 3.066 Exercise Google SpreadsheetApp
- 3.067 Exercise Generate Random content
- 3.068 Adding new column
- 3.069 Add formulas, set colors
- 3.070 HTML modal to spreadsheet
- 3.071 Sheet data to HTML file
- 3.072 Source code
- 3.073 Get Sheet data
- 3.074 Run script clientside
- 3.075 Response with Google Sheet data
- 3.076 Source code HTML index file
- 3.077 Source code GS
- 4.078 Intro to Google Sites
- 4.079 New Google sites
- 4.080 Publish web app Google Script
- 4.081 Google Site scripting
- 4.082 Source code
- 4.083 Google Script web app HTML page
- 5.084 Google DriveApp class
- 5.085 Select folder by ID
- 5.086 Create folder DriveApp
- 5.087 DriveApp create file
- 5.088 Spreadsheet with DriveApp Data
- 5.089 Source code
- 5.090 Create Doc and move it
- 5.091 Source code
- 5.092 DriveApp Search
- 5.093 DriveApp search files
- 5.094 Source code
- 5.095 DriveApp searchFolders params
- 5.096 Add editors and Delete
- 5.097 Source code
- 5.098 Redirect on search string
- 5.099 Exercise WebApp redirector
- 5.100 Source code
- 6.101 Intro to GmailApp class
- 6.102 Make draft GmailApp
- 6.103 View your draft email
- 6.104 Use HTML Template email
- 6.105 Send out a bunch of emails
- 6.106 Source code
- 6.107 Chat threads GmailApp
- 6.108 Get Gmail messages
- 6.109 Source code
- 7.110 Calendar app service
- 7.111 Add location info Calendar app
- 7.112 Calendar event with options
- 7.113 Full day events Calendar app
- 7.114 Calendar app event series
- 7.115 Calendar app date time
- 7.116 Easy way to enter Events
- 7.117 More Calendars
- 7.118 Calendar settings
- 7.119 Get all calendars
- 7.120 Calendars by name
- 7.121 Source code
- 7.122 Calendar events
- 7.123 Calendar events explored
- 7.124 Calendar events into spreadsheet
- 7.125 Google Calendar events invites no
- 7.126 Source code
- 7.127 Send weekly Calendar events
- 7.128 Source code
- 7.129 Review Google Script
- 8.130 Apps Script image uploader project intro
- 8.131 HTML content service
- 8.132 HTML content template file
- 8.133 HTML content from file
- 8.134 Create the HTML form
- 8.135 Send data to Google Script backend
- 8.136 Send image to Google Script
- 8.137 Image upload tweaks
- 8.138 Spreadsheet App tracking uploads
- 8.139 Send email notification
- 8.140 Final application image uploader
- 8.141 Project source code
- 9.142 Setup Google Form
- 9.143 Spreadsheet bound script
- 9.144 Google Script Setup Project triggers
- 9.145 Setup Email to Send
- 9.146 MailApp send email
- 9.147 Email HTML template
- 9.148 HTML service replace content
- 9.149 Source code
- 9.150 HTML to PDF and Attach it
- 9.151 Send automatic emails
- 9.152 Iterate sheet data send emails
- 9.153 Review and update code for project
- 9.154 Project source code
