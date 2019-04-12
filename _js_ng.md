Angular 5
## Directory structure
- _src/app_ contains multiple _.ts_ files (TypeScript)
## Angular 5 components
Use Angular CLI
- $`ng generate component home` or shorthand $`ng g c about` 
  - these component names become folders within _/src/app_

component.ts
- `@Component` decorator
  Properties:
  - `selector` component name
  - `templateUrl` or `template` can have a multiline template string as value if HTML is very simple
  - `styleUrls`: array of URL strings or `styles` which takes a template string within a array for inline styling

## Syntax
- $`ng new ng5` create new Angular 5 project
- $`ng serve` run a development server for your Angular project
### Directives
- `routerLink`
### Components
- `router-outlet` 