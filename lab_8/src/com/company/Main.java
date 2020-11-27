package com.company;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;


public class Main {

    public static void main(String[] args) {
        /**
         * task1
         */
        try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("person.dat")))
        {
            Customer customer = new Customer("Name","Surname", "SecondName", Bank.Pumb, "1234123412341234", 100000, 20000);
            oos.writeObject(customer);
        }
        catch(Exception ex){

            System.out.println(ex.getMessage());
        }

        /**
         * task2
         */
        Customer customer = new Customer("Name","Surname", "SecondName", Bank.Pumb, "1234123412361234", 100000, 200000);
        Customer customer1 = new Customer("Name1","Surname1", "SecondName1", Bank.PrivatBank, "163412341234123", 100000, 200);
        Customer customer2 = new Customer("Name2","Surname2", "SecondName2", Bank.Pumb, "1234124667341234", 100000, 100);
        Customer customer3 = new Customer("Name3","Surname3", "SecondName3", Bank.MonoBank, "1236123412341234", 100000, 120000);
        Customer customer4 = new Customer("Name4","Surname4", "SecondName4", Bank.MonoBank, "123615253412341234", 100000, 210000);
        Customer customer5 = new Customer("Name5","Surname5", "SecondName5", Bank.Pumb, "1234123618441234", 100000, 20400);
        Customer customer6 = new Customer("Name6","Surname6", "SecondName6", Bank.Pumb, "9234123619641234", 100000, 20910);
        Customer customer7 = new Customer("Name7","Surname7", "SecondName7", Bank.PrivatBank, "9634123412341234", 100000, 50000);

        List<Customer> arrayList = new ArrayList<>();
        arrayList.add(customer);
        arrayList.add(customer1);
        arrayList.add(customer2);
        arrayList.add(customer3);
        arrayList.add(customer4);
        arrayList.add(customer5);
        arrayList.add(customer6);
        arrayList.add(customer7);



        /**
         * a)
         */
        System.out.println("A: ");
        for(int i = 0; i < arrayList.size(); i++) {
            if ( arrayList.get(i).getBank() == Bank.MonoBank) {
                if ( arrayList.get(i).getLimit() < arrayList.get(i).getState() ) {
                    System.out.println(arrayList.get(i));
                }
            }
        }

        /**
         * b)
         */
        System.out.println("B: ");
        for(int i = 0; i < arrayList.size(); i++) {
            if ( Double.parseDouble(arrayList.get(i).getCardId()) > Double.parseDouble("9111111111111111") && Double.parseDouble(arrayList.get(i).getCardId()) < Double.parseDouble("9999111111111111")) {
                System.out.println(arrayList.get(i));
            }
        }

        /**
         * c)
         */
        System.out.println("C: ");
        for(int i = 0; i < arrayList.size(); i++) {
            if ( arrayList.get(i).getState()/arrayList.get(i).getLimit() > 0.8  ) {
                System.out.println(arrayList.get(i));
            }
        }


    }
}
