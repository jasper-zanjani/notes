# Observations on the learning process

## Anki
Made good progress incorporating task-based learning by simplifying procedures into command sequences with no parameters or (at most) one or two. Used a spreadsheet to concatenate hand-entered text values in a cloze Anki flashcard.

#### Two tasks with related forms
```
* Get connection string of account
  constring=$(az storage account show-connection-string)
* Create file share with connection string
  az storage share create
    --connection-string $constring
```
Here, both instances of `storage` are tested at once.