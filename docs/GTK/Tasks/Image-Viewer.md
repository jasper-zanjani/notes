# Image Viewer

```rs
use gtk4::prelude::*;
use gtk4::{Application, ApplicationWindow, Box, Picture};

fn main() {
    let app = Application::builder()
        .application_id("org.gtk-rs.example")
        .build();
    app.connect_activate(build_ui);
    app.run();
}

fn build_ui(app: &Application) {
    let img = Picture::for_filename("C:\\Users\\4472936\\Rust\\gtk\\pic.png");

    let container = Box::new( gtk::Orientation::Vertical,  12);
    container.append(&img);
    
    let window = ApplicationWindow::builder()
        .application(app)
        .title("My GTK App")
        .child(&container)
        .build();

    window.present();
}
```