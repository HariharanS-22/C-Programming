# 🔐 Password Validator & Credential Storage

This C program checks if a password is strong based on specific criteria and stores the username-password pair in a `.csv` file if the password passes all checks.

## 📦 Features

- ✅ Takes user input for username and password (password is masked).
- ✅ Validates password against:
  - Minimum **12 characters**
  - At least **one uppercase** letter
  - At least **one lowercase** letter
  - At least **one digit**
  - At least **one special character**
- ✅ Stores valid credentials in a file (`credentials.csv`).

## 🧠 Password Criteria Logic

Password is considered **strong** if it meets:
- `length >= 12`
- Contains `A–Z` (uppercase)
- Contains `a–z` (lowercase)
- Contains `0–9` (numbers)
- Contains any special character like `!@#$%^&*()`

## 🛠 Build Instructions

Make sure `checking.c` and `checking.h` are in the same directory as `main.c`.

  ```bash
    gcc main.c checking.c -o password_validator
    ./password_validator
  ```
## 📸 Example
```bash
  Enter your username : JohnDoe
  Enter your password : ************

  You have entered a strong password
```
If the password fails, output:
```bash
The password must contains 
    -> atleast 12 characters
    -> atleast one Capital character
    -> atleast one small character
    -> atleast one number character
    -> atleast one special character
```

## 🔐 Output File Format
A CSV file credentials.csv will store:
```
username,password
JohnDoe,MyStr0ngP@ss!
```
⚠️ Note: Passwords are stored in plaintext. For real-world applications, use hashing and encryption!

## 🚀 Improvements Suggested
- Password encryption using hashing (e.g., SHA-256)

- Unique username check

 - GUI or cross-platform support

 - Replace getch() with secure alternatives for Unix/Linux

