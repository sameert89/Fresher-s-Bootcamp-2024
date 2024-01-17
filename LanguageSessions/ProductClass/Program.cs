using System;
using System.Collections.Generic;

namespace ECommerce
{
    class Program
    {
        static void Main(string[] args)
        {
            bool decision = true;
            int choice = 1;
            List<Product> products = new List<Product>();

            do
            {
                Console.WriteLine("Please enter a choice: \n 1) Add Product, 2) Display Products, 3) Exit");
                choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        Console.WriteLine("Enter product ID:");
                        int prodID = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter warranty:");
                        int warranty = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter item stock:");
                        int itemStock = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter GST percent:");
                        int gstPercent = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter discount percent:");
                        int discountPercent = Convert.ToInt32(Console.ReadLine());

                        Console.WriteLine("Enter product name:");
                        string name = Console.ReadLine();

                        Console.WriteLine("Enter manufacturing date:");
                        string mfgDate = Console.ReadLine();

                        Console.WriteLine("Enter price:");
                        double price = Convert.ToDouble(Console.ReadLine());

                        Console.WriteLine("Enter tax value:");
                        double taxVal = Convert.ToDouble(Console.ReadLine());

                        products.Add(new Product(prodID, warranty, itemStock, gstPercent, discountPercent, name, mfgDate, price, taxVal));
                        break;

                    case 2:
                        foreach (var prod in products)
                        {
                            Console.WriteLine(prod.display());
                        }
                        break;

                    case 3:
                        decision = false;
                        break;

                    default:
                        Console.WriteLine("Invalid choice. Please try again.");
                        break;
                }
            } while(decision);
	}
    }
}
