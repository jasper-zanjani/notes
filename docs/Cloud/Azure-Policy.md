Sources
- [What is Azure Policy?](https://docs.microsoft.com/en-us/azure/governance/policy/overview)
- [Azure Policy Samples](https://github.com/Azure/azure-policy)

**Azure Policy** is a service that can create, assign, and manage policies to enforce governance. Policy definitions, authored in JSON, implement policy by describing desired behavior for Azure resources when they are created or updated. <sup>AZ-103: p. 72</sup>

To implement policy, a **policy definition** is created first, then a **policy assignment** assigns it to a scope. Policy definitions can be packaged together using **initiative definitions** and applied to a scope using **initiative assignments**

[RBAC roles](RBAC#roles) **deny by default and allow explicitly**. But Azure Policy **allows by default and denies explicitly**

Policies can be applied at the **management group**, **subscription**, or **resource group** scope, with all child resources and resource groups being affected.

## Effects
Sources:
- [Understand Azure Policy effects](https://docs.microsoft.com/en-us/azure/governance/policy/concepts/effects)

Every policy definition has a single **effect**, which includes:

- **Audit**: create a warning event in the log
- **Modify**: used to add, update, or remove properties or tags on a resource during creation or update.
- Append
- AuditIfNotExists
- Deny
- DeployIfNotExists
- Disabled

The order of evaluation of effects is: Disabled, Append, Deny, Audit ("DADA")

## Schema
Sources:
- AZ-103: p.17
```json
{ 
  "mode": "all",
  "policyRule": 
  {
    "if": 
    {
      "allOf": 
      [
        { "field": "type",
          "equals": "Microsoft.Compute/virtualMachines" },
        { "not": {
            "field": "Microsoft.Compute/virtualMachines/sku.name",
            "in": "[parameters('listOfAllowedSKUs')]" }
        }
      ]
    },
    "then": {
      "effect": "deny"
    }
  },
  "parameters": {
    "listOfAllowedSKUs": {
      "type": "array",
      "metadata": {
      "displayName": "Allowed VM SKUs",
      "description": "The list of allowed SKUs for virtual machines.",
      "strongType": "vmSKUs"
      }
    }
  }
}
```

:point_right: [Schema](https://schema.management.azure.com/schemas/2018-05-01/policyDefinition.json)

```json
{
  "id": "https://schema.management.azure.com/schemas/2018-05-01/policyDefinition.json#",
  "$schema": "http://json-schema.org/draft-04/schema#",
  "title": "Policy Definition",
  "description": "This schema defines Azure resource policy definition, please see https://azure.microsoft.com/en-us/documentation/articles/resource-manager-policy/ for more details.",
  "type": "object",
  "properties": {
    "if": {
      "oneOf": [
        { "$ref": "#/definitions/condition" },
        { "$ref": "#/definitions/operatorNot" },
        { "$ref": "#/definitions/operatorAnyOf" },
        { "$ref": "#/definitions/operatorAllOf" }
      ]
    },
    "then": {
      "type": "object",
      "properties": {
        "effect": {
          "type": "string",
          "enum": [
            "append",
            "audit",
            "auditIfNotExists",
            "deny",
            "deployIfNotExists"
          ]
        },
        "details": {
          "oneOf": [
            { "$ref": "#/definitions/ifNotExistsDetails" },
            { "$ref": "#/definitions/appendDetails" }
          ]
        }
      },
      "required": [
        "effect"
      ],
      "additionalProperties": false
    }
  },
  "required": [
    "if",
    "then"
  ],
  "additionalProperties": false,
  "definitions": {
    "appendDetails": {
      "type": "array",
      "items": {
        "properties": {
          "field": {
            "type": "string"
          },
          "value": {}
        },
        "required": [
          "field",
          "value"
        ],
        "additionalProperties": false
      },
      "minItems": 1,
      "additionalItems": false
    },
    "ifNotExistsDetails": {
      "type": "object",
      "properties": {
        "type": {
          "type": "string"
        },
        "name": {
          "type": "string"
        },
        "resourceGroupName": {
          "type": "string"
        },
        "existenceScope": {
          "type": "string",
          "enum": [
            "resourceGroup",
            "subscription"
          ]
        },
        "roleDefinitionIds": {
          "type": "array",
          "items": {
            "type": "string"
          }
        },
        "existenceCondition": {
          "oneOf": [
            { "$ref": "#/definitions/condition" },
            { "$ref": "#/definitions/operatorNot" },
            { "$ref": "#/definitions/operatorAnyOf" },
            { "$ref": "#/definitions/operatorAllOf" }
          ]
        },
        "deployment": {
          "type": "object",
          "properties": {
            "properties": {
              "$ref": "https://schema.management.azure.com/schemas/2018-05-01/Microsoft.Resources.json#/definitions/DeploymentProperties"
            }
          }
        }
      },
      "required": [
        "type"
      ],
      "additionalProperties": false
    },
    "condition": {
      "allOf": [
        {
          "oneOf": [
            {
              "properties": {
                "source": {
                  "type": "string"
                }
              },
              "required": [
                "source"
              ]
            },
            {
              "properties": {
                "field": {
                  "type": "string"
                }
              },
              "required": [
                "field"
              ]
            }
          ]
        },
        {
          "oneOf": [
            {
              "properties": {
                "equals": {
                  "type": "string"
                }
              },
              "required": [
                "equals"
              ]
            },
            {
              "properties": {
                "notEquals": {
                  "type": "string"
                }
              },
              "required": [
                "notEquals"
              ]
            },
            {
              "properties": {
                "like": {
                  "type": "string"
                }
              },
              "required": [
                "like"
              ]
            },
            {
              "properties": {
                "notLike": {
                  "type": "string"
                }
              },
              "required": [
                "notLike"
              ]
            },
            {
              "properties": {
                "contains": {
                  "type": "string"
                }
              },
              "required": [
                "contains"
              ]
            },
            {
              "properties": {
                "notContains": {
                  "type": "string"
                }
              },
              "required": [
                "notContains"
              ]
            },
            {
              "properties": {
                "in": {
                  "oneOf": [
                    {
                      "type": "array"
                    },
                    {
                      "type": "string"
                    }
                  ]
                }
              },
              "required": [
                "in"
              ]
            },
            {
              "properties": {
                "notIn": {
                  "oneOf": [
                    {
                      "type": "array"
                    },
                    {
                      "type": "string"
                    }
                  ]
                }
              },
              "required": [
                "notIn"
              ]
            },
            {
              "properties": {
                "containsKey": {
                  "type": "string"
                }
              },
              "required": [
                "containsKey"
              ]
            },
            {
              "properties": {
                "notContainsKey": {
                  "type": "string"
                }
              },
              "required": [
                "notContainsKey"
              ]
            },
            {
              "properties": {
                "match": {
                  "type": "string"
                }
              },
              "required": [
                "match"
              ]
            },
            {
              "properties": {
                "notMatch": {
                  "type": "string"
                }
              },
              "required": [
                "notMatch"
              ]
            },
            {
              "properties": {
                "exists": {
                  "type": "string"
                }
              },
              "required": [
                "exists"
              ]
            }
          ]
        }
      ]
    },
    "operatorNot": {
      "properties": {
        "not": {
          "oneOf": [
            { "$ref": "#/definitions/condition" },
            { "$ref": "#/definitions/operatorNot" },
            { "$ref": "#/definitions/operatorAnyOf" },
            { "$ref": "#/definitions/operatorAllOf" }
          ]
        }
      },
      "required": [
        "not"
      ],
      "additionalProperties": false
    },
    "operatorAnyOf": {
      "properties": {
        "anyOf": {
          "type": "array",
          "minItems": 1,
          "items": {
            "oneOf": [
              { "$ref": "#/definitions/condition" },
              { "$ref": "#/definitions/operatorNot" },
              { "$ref": "#/definitions/operatorAnyOf" },
              { "$ref": "#/definitions/operatorAllOf" }
            ]
          }
        }
      },
      "required": [
        "anyOf"
      ],
      "additionalProperties": false
    },
    "operatorAllOf": {
      "properties": {
        "allOf": {
          "type": "array",
          "minItems": 1,
          "items": {
            "oneOf": [
              { "$ref": "#/definitions/condition" },
              { "$ref": "#/definitions/operatorNot" },
              { "$ref": "#/definitions/operatorAnyOf" },
              { "$ref": "#/definitions/operatorAllOf" }
            ]
          }
        }
      },
      "required": [
        "allOf"
      ],
      "additionalProperties": false
    }
  }
}
```