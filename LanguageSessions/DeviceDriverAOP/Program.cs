using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeviceDriver
{
    class Device
    {
        [Required(ErrorMessage = "ID Property Requires Value")]
        public string Id { get; set; }

        [Range(10, 100, "Code Value Must Be Within 10-100")]
        public int Code { get; set; }

        [MaxLength(100, "Max of 100 Charcters are allowed")]
        public string Description { get; set; }

        [Regex("^Z[A-Z]{3}\\d{12}$", "Barcode should start with 4 alphabets, Z being the first & End with 12 digits")]
        public string BarCode { get; set; }

        public Device(string Id, int Code, string Description, string BarCode)
        {
            this.Id = Id;
            this.Code = Code;
            this.Description = Description;
            this.BarCode = BarCode;
        }

    }
    

    internal class Program
    {
        static void Main()
        {
            /* UI */
            Console.WriteLine("Please Enter the Device ID");
            string Id = Console.ReadLine();
            Console.WriteLine("Please Enter the Device Code");
            int Code;
            try {
                Code = Int32.Parse(Console.ReadLine());
            } catch (Exception e)
            {
                Console.WriteLine(e.Message, "Code defaulted to 0");
                Code = 0;
            }
            Console.WriteLine("Please Enter the Device Description");
            string Description = Console.ReadLine();

            Console.WriteLine("Please Enter the Device BarCode");
            string BarCode = Console.ReadLine();

            Device deviceObj = new Device(Id, Code, Description, BarCode);
            List<string> errors;
            bool isValid = ObjectValidator.Validate(deviceObj,out errors);
            if (!isValid)
            {
                foreach (string item in errors)
                {
                    Console.WriteLine(item);
                }
            }
            Console.ReadLine();
        }
    }
}
