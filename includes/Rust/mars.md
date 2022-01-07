```rs
fn main() {
    let mut input = String::new();
    println!("Enter weight in kilograms: ");

    std::io::stdin().read_line(&mut input);
    
    let input: f32 = match input.trim().parse() {
        Ok(num) => num,
        Err(_) => 0.0,
    };

    let mars_weight = calculate_weight_on_mars(input);
    println!("Weight on Mars: {} kg", &mars_weight);
}

fn calculate_weight_on_mars(weight: f32) -> f32 {
    (weight / 9.81) * 3.711
}
```