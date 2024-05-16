# MobiCash - Mobile Banking System

---

## Description

MobiCash is a comprehensive mobile banking system implemented in C++. It provides users with a convenient and secure platform to perform various banking transactions remotely, such as checking balances, transferring funds, mobile recharges, and more. The system incorporates features like user and agent registration, login authentication, transaction tracking, and administrative functionalities. Utilizing file handling for data storage ensures persistent user information and transaction records.

---

## Features

1. **User Registration:**
    - Users can register by providing their mobile number, username, and password.
    - Each registered user's information is stored securely for future authentication.

2. **Agent Registration:**
    - Agents can register by submitting their contact number, allowing them to facilitate cash transactions.

3. **Login Authentication:**
    - Registered users can securely log in using their mobile number and password.
    - Authentication ensures only authorized users can access their accounts.

4. **Balance Inquiry:**
    - Users can check their account balances to monitor their financial status.

5. **Cash In:**
    - Users can deposit money into their accounts through designated agents.

6. **Cash Out:**
    - Users can withdraw money from their accounts via authorized agents.

7. **Mobile Recharge:**
    - Users can recharge mobile phone balances directly through the system.

8. **Send Money:**
    - Users can transfer funds to other registered users seamlessly.

9. **Transaction Details:**
    - Users can view detailed transaction histories to track their financial activities.

10. **Administrative Interface:**
    - Admins have access to functionalities such as viewing registered users and agents.
    - Admins can monitor system activities and manage user and agent data efficiently.

---

## File Structure

- **`main.cpp ` : ** Contains the core program logic and user interface.
- **`README.md `:** Detailed project documentation and instructions.
- **`Balance.txt`:** Stores user account balances.
- **`User.txt`:** Records registered usernames.
- **`UserMobile.txt`:** Stores registered user mobile numbers.
- **`Agent.txt`:** Stores registered agent contact numbers.
- **`data<user_mobile_number>.txt`:** Stores user data (mobile number, username, password).
- **`Balance<user_mobile_number>.txt`:** Records individual user account balances.
- **`Tran<user_mobile_number>.txt`:** Logs user transaction details for each user.

---

## Instructions for Running the Program

1. **Compile:**
    - Compile the `main.cpp` file using a C++ compiler (e.g., g++).
    ```bash
    g++ main.cpp -o mobicash
    ```

2. **Run:**
    - Execute the compiled program.
    ```bash
    ./mobicash
    ```

3. **Usage:**
    - Follow the on-screen prompts to navigate through the various features of the MobiCash system.

---

## Contributors

- Tirtho Mondal (GitHub: [tirtho-mondal](https://github.com/tirtho-mondal))

---


## Contact

For any inquiries or issues, please contact the project owner at [Tirtho Mondal](mailto:tirthomondal@gmail.com).

---

## Additional Resources

- [YouTube](https://youtu.be/rMoXmBDAlz0?si=1pfvHnduVh7x6Rrx)
