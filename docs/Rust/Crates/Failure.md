# failure

The failure crate is an error-handling library

## API

#### Fail
:   
    The [Fail trait](https://boats.gitlab.io/failure/fail.html) extends errors with a variety of traits and methods.
    

    ```rs
    use failure_derive::Fail;
    
    #[derive(Fail)]
    enum CustomErr {
        #[fail(display="Foo error")]
        CustomErrorFoo(String),
        #[fail(display="Bar error")]
        CustomErrorBar(String),
    }
    ```