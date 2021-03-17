# Windows programming

## 📘 Glossary

### COM

The **Component Object Model** is a binary standard interface specification for objects.
It originated in 1993 as a renaming of OLE (Object Linking and Embedding) 2.0, used by Microsoft Office at the time to link data between applications.

COM objects support a collection of interfaces, most importantly **`IUnknown`** which all COM objects must implement.
IUnknown includes `QueryInteface()` which returns pointers to the other interfaces also implemented by the COM object.
It also includes `AddRef()` and `Release()`, which manage the object's lifetime.

COM uses HRESULTs, 32-bit longs, to indicate success or failure.
Bit 31 indicates success (0) or failure (1).
With .NET [interop](#interop), a failed HRESULT turns into a thrown COMException.
Common HRESULTs include `S_OK`, `S_FALSE`, `E_FAIL`, and many other failure codes also beginning with `E_`.

COM objects are created by calling `CoCreateInstance()`.
This function, which is stored in ole32.dll, searches the Registry for the given class ID, then loads the apropriate **COM Server** DLL file.
This DLL file then creates a class factory which then creates the COM instance, which is passed back to the client as an interface pointer.
([src](https://app.pluralsight.com/course-player?clipId=741b49fc-646c-49ba-8ec3-497d046bbaf1))

COM classes must be registered in the Registry, at minimum by mapping the class ID (a GUID) to a DLL, in the **HKEY_CLASSES_ROOT** hive.
This is done using the **regsvr32.exe** utility.
([src](https://app.pluralsight.com/course-player?clipId=dc4cc210-1265-48c2-aafe-36da5481e544))

### DirectX

DirectX is a gaming API that was created by Eric Engstrom (d. 2020), Alex St. John, and Craig Eisler in 1994 to support game development on Windows 95.


### Interop



### WinRT

The **Windows Runtime** is implemented as [COM](#com) components.