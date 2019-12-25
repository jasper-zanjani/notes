# DSC

Syntax           | Effect
:---             | :---
`Configuration`  | precedes title of script, at top (e.g. `Configuration ContosoSimple`)
`Ensure`         | property within `WindowsFeature` that can be set to `Present` or `Absent` (e.g. `Ensure = "Present"`)
`WindowsFeature` | declares code block representing a DSC resource to be installed (e.g. `WindowsFeature IIS`)