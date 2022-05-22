#### elvish
:
    Conditional logic
    ```elvish
    if $true { echo good } else { echo bad }
    ```

    Iterating over an array
    ```elvish
    for x [lorem ipsum] {
        echo $x.pdf
    }
    ```

    Raising and catching an error
    ```elvish
    try {
        fail 'bad error'
    } except e {
        echo error $e
    } else {
        echo ok
    }
    ```