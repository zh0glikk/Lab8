package com.company;

public class Customer {
    private String name;
    private String surname;
    private String secondName;
    private Bank bank;
    private String cardId;
    private double limit;
    private double state;

    public Customer(String name, String surname, String secondName, Bank bank, String cardId, double limit, double state) {
        this.name = name;
        this.surname = surname;
        this.secondName = secondName;
        this.bank = bank;
        this.cardId = cardId;
        this.limit = limit;
        this.state = state;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getSecondName() {
        return secondName;
    }

    public Bank getBank() {
        return bank;
    }

    public String getCardId() {
        return cardId;
    }

    public double getLimit() {
        return limit;
    }

    public double getState() {
        return state;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setSecondName(String secondName) {
        this.secondName = secondName;
    }

    public void setBank(Bank bank) {
        this.bank = bank;
    }

    public void setCardId(String cardId) {
        this.cardId = cardId;
    }

    public void setLimit(double limit) {
        this.limit = limit;
    }

    public void setState(double state) {
        this.state = state;
    }

    public String toString() {
        String result = "";
        result += "Customer: " + this.surname + " " + this.name + " " + this.secondName + "\n";
        result += "Bank: " + this.bank + "\n";
        result += "CardId: " + this.cardId + "\n";
        result += "Limit: " + this.limit + "\n";
        result += "State: " + this.state + "\n";
        return result;
    }
}
