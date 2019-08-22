## Processing workflows
#### Cookbooks
**Cookbooks** are collections of tasks with representative implementations (e.g. Azure commands and procedures for [AZ-103](az-103.md))
1. **Number** tasks for easy reference, indexing, and linking in markdown
2. **Catalog** tasks and desciptions in a spreadsheet
3. **Copy** catalog with task and description to markdown. This will serve as both an index of tasks as well as the skeleton for the content. Use multiple cursors to introduce `####` heading syntax before the task identifier, followed by a carriage return before the one-line description of the task. This will ensure that the task is easily found by identifier. These should be collected in a single-cell table, producing a "cloud" of tasks."
4. **Fill** markdown with syntax, producing a true reference of the source's syntax
5. **Map** each form-based feature (e.g. commands) to tasks in a spreadsheet (Command | Task). Once organized by command, the resulting associations can form another table of content which associates form features to tasks. These should be placed in another single-cell cloud where each token is followed by links to the tasks in which it appears. The tokens should be organized, either by command group or roughly by domain.
6. **Index** form-based features at the top of the markdown as a concordance.