# grep ports

The success of [ripgrep](https://github.com/BurntSushi/ripgrep) has inspired many ports of other GNU utilities to Rust.

Porting grep to Rust provides the opportunity to explore various ways of using [iterators](/Rust/Glossary#iterator), evolving from a naive `for in` loop to the [**`filter()`**](/Rust/Glossary#filter) iterator method using a [closure](/Rust/Glossary#closure).

```rs title="Loop"
fn main() {
    let mut results = Vec::new();

    for line in contents.lines() {
        if line.contains(query) {
            results.push(line);
        }
    }
    results
}
```

```rs title="filter"
fn main() {
    contents.lines()
        .filter(|line| line.contains(query))
        .collect()
}
```

#### grep-lite

--8<-- "includes/Rust/grep/grep-lite.md"

#### minigrep

--8<-- "includes/Rust/grep/minigrep.md"

