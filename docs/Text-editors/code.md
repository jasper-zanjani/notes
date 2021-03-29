# VS Code

- Code can be folded by placing markers [:material-file-document-multiple-outline:](https://code.visualstudio.com/docs/editor/codebasics#_folding)

=== "Markdown"

    ```md
    <!-- #region -->
    ...
    <!-- #endregion -->
    ```

=== "C#"

    ```csharp
    #region 
    ...
    #endregion
    ```

=== "Python"

    ```python
    #region
    ...
    #endregion
    ```

[Snippets](https://code.visualstudio.com/docs/editor/userdefinedsnippets)


"Editor group" refers to window panes.

Default keyboard binding  | Command                                       | Effect
:---                      | :---                                          | :---
<kb>Ctrl</kbd><kbd>\</kbd>                    | `workbench.action.splitEditor`                | Split Editor
<kb>Ctrl</kbd><kbd>k</kbd> Ctrl+UpArrow       | `workbench.action.focusAboveGroup`            | View: Focus Above Editor Group
<kb>Ctrl</kbd><kbd>k</kbd> Ctrl+RightArrow    | `workbench.action.focusRightGroup`            | View: Focus Right Editor Group
<kb>Ctrl</kbd><kbd>k</kbd> Ctrl+DownArrow     | `workbench.action.focusBelowGroup`            | View: Focus Below Editor Group
<kb>Ctrl</kbd><kbd>k</kbd> Ctrl+LeftArrow     | `workbench.action.focusLeftGroup`             | View: Focus Left Editor Group
<kb>Ctrl</kbd><kbd>k</kbd> UpArrow            | `workbench.action.moveActiveEditorGroupUp`    | View: Move Editor Group Up
<kb>Ctrl</kbd><kbd>k</kbd> RightArrow         | `workbench.action.moveActiveEditorGroupRight` | View: Move Editor Group Right
<kb>Ctrl</kbd><kbd>k</kbd> DownArrow          | `workbench.action.moveActiveEditorGroupDown`  | View: Move Editor Group Down
<kb>Ctrl</kbd><kbd>k</kbd> LeftArrow          | `workbench.action.moveActiveEditorGroupLeft`  | View: Move Editor Group Left
<kb>Alt</kbd><kbd>UpArrow</kbd>               | `editor.action.moveLinesUpAction`             | Move line up
<kb>Alt</kbd><kbd>DownArrow</kbd>             | `editor.action.moveLinesDownAction`           | Move line down
<kb>Option</kbd><kbd>Command</kbd>-DownArrow  |                                               | Add a cursor down
<kb>Option</kbd><kbd>Command</kbd>-UpArrow    |                                               | Add a cursor up
<kb>Option</kbd><kbd>Shift</kbd>-Left Click   |                                               | Click and drag to add cursors
<kb>Ctrl</kbd><kbd>Shift</kbd>+5              |                                               | Terminal: Split terminal
<kb>Ctrl</kbd><kbd>h</kbd>                    |                                               | Replace
<kb>Ctrl</kbd><kbd>l</kbd>                    |                                               | Expand line selection
<kb>Ctrl</kbd><kbd>j</kbd>                    | `workbench.action.togglePanel`                | View: Toggle Panel
<kb>Ctrl</kbd><kbd>b</kbd>                    |                                               | View: Toggle Side Bar Visibility