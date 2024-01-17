using System;
using System.Collections.Generic;
using System.Linq;

namespace ECommerce {
    
  class Program {
    static void Main(string[] args) {
      bool decision = true;
      int choice = 1;
      List<Product> products = new List<Product>();

      do {
        Console.WriteLine(
            "Please enter a choice: \n 1) Add Product, 2) Display Products, 3) Find Product, 4) Exit");
        choice = Convert.ToInt32(Console.ReadLine());

        switch (choice) {
          case 1:
            Console.WriteLine("Enter product ID:");
            int prodID = Convert.ToInt32(Console.ReadLine());

            if (prodID < 0)
              throw new Exception("Product ID cannot be negative");

            Console.WriteLine("Enter warranty (months):");
            int warranty = Convert.ToInt32(Console.ReadLine());

            if (warranty < 0)
              throw new Exception(
                  "Warranty cannot be less than or equal to zero");

            Console.WriteLine("Enter item stock:");
            int itemStock = Convert.ToInt32(Console.ReadLine());

            if (itemStock < 0)
              throw new Exception("itemStock canot be less than 0");

            Console.WriteLine("Enter GST percent:");
            int gstPercent = Convert.ToInt32(Console.ReadLine());

            if (!new[] { 5, 12, 18, 28 }.Contains(gstPercent))
              throw new Exception("gst can be only 5, 12, 18, 28 %");

            Console.WriteLine("Enter discount percent:");
            int discountPercent = Convert.ToInt32(Console.ReadLine());

            if (discountPercent < 0)
              throw new Exception("discount Percent cannot be negative");

            Console.WriteLine("Enter product name:");
            string name = Console.ReadLine();

            Console.WriteLine("Enter manufacturing date(YY/MM/DD):");
            string mfgDate = Console.ReadLine();

            Console.WriteLine("Enter price:");
            double price = Convert.ToDouble(Console.ReadLine());

            if (price < 0)
              throw new Exception("price cannot be less than equal to 0");

            products.Add(new Product(prodID, warranty, itemStock, gstPercent,
                                     discountPercent, name, mfgDate, price));
            break;

          case 2:
            foreach (var prod in products) {
              Console.WriteLine(prod.display());
            }
            break;
          case 3:
            Console.WriteLine("Please Enter the ProdID");
            prodID = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(prodID);
            bool found = false;
            foreach(var prod in products){
                if(prod._prodID == prodID){
                    Console.WriteLine(prod._prodID);
                    Console.WriteLine(prod.display());
                    flag = true;
                    break;
                }
            }
            if(!flag)
                Console.WriteLine("Product Not Found");
            break;
          case 4:
            decision = false;
            break;

          default:
            Console.WriteLine("Invalid choice. Please try again.");
            break;
        }
      } while (decision);
    }
  }
}
