# Arbitrary Precedence Calculator (APC)

A powerful C-based arithmetic engine designed to perform operations on **large integers** using **Doubly Linked Lists**, enabling calculations beyond native data type limits.

Overview

The **Arbitrary Precedence Calculator (APC)** processes extremely large numbers by storing them digit-by-digit in a doubly linked list. It mimics manual arithmetic logic and performs:

* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`)

The project demonstrates strong grasp of **Data Structures**, **Algorithms**, and **modular C programming**.

# Features

* Works with numbers of **any size**
* Supports all major arithmetic operations
* Sign-aware calculations (`+`, `-`)
* Input validation for safe execution
* Efficient use of dynamic memory
* Modular and clean directory structure

---

# How It Works

Each number is converted to a doubly linked list via `CLA_to_list()`. Arithmetic functions then operate on these lists similar to how you would do calculations on paper:

* **Addition** → carry-forward logic
* **Subtraction** → borrow mechanism
* **Multiplication** → partial product accumulation
* **Division** → long-division technique

This structure enables APC to handle thousands of digits without overflow.

---

## Command Format

```
./apc <num1> <operator> <num2>
```

## Example

```
./apc 9999999999999999 + 1
```

### Output

```
Result: 10000000000000000
```
