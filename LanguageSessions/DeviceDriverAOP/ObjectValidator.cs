using System.Collections.Generic;

namespace DeviceDriver
{
    internal class ObjectValidator
    {
        public static bool Validate(object obj, out List<string> errors)
        {
            errors = new List<string>();
            System.Type type= obj.GetType();
            System.Reflection.PropertyInfo[] properties = type.GetProperties(/* binding flags */); // type has metadata
            
            foreach (var property in properties)
            {
                object[] attributes = property.GetCustomAttributes(typeof(ValidationAttribute), false); // typeof className gives metadata

                foreach (var attr in attributes)
                {
                    ValidationAttribute vAttr = attr as ValidationAttribute;
                    if (!vAttr.isValid(property.GetValue(obj)))
                    {
                        errors.Add(vAttr.ErrorMessage);
                    }
                }
            }

            return (errors.Count == 0);
        }
    }
}
