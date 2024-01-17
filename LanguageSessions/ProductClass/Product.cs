using System;
using System.Text;

namespace ECommerce
{
    internal class Product
    {
    public int _prodID{ get; private set;}
	private int  _warranty, _itemStock, _gstPercent, _discountPercent;
	private string _name, _mfgDate;
	private double _price, _taxVal, _discountVal;
	internal Product(int prodID, int warranty, int itemStock, int gstPercent, int discountPercent, string name, string mfgDate, double price){
		this._prodID = prodID;
		this._warranty = warranty;
		this._itemStock = itemStock;
		this._gstPercent = gstPercent;
		this._discountPercent = discountPercent;
		this._name = name;
		this._mfgDate = mfgDate;
		this._price = price;
		this._taxVal = price + price * (gstPercent / 100);
		this._discountVal = this._taxVal * (discountPercent / 100);

		
	}
	internal string display(){
		Console.WriteLine("--------Product Details-------- ");
		StringBuilder prodDetailsBuffer = new StringBuilder();
		prodDetailsBuffer.Append($"Product ID: {_prodID}");
		prodDetailsBuffer.Append(Environment.NewLine);
		prodDetailsBuffer.Append($"Product Name: {_name}");
		prodDetailsBuffer.Append(Environment.NewLine);
		prodDetailsBuffer.Append($"Date of Manufacturing: {_mfgDate}");
		prodDetailsBuffer.Append(Environment.NewLine);
		prodDetailsBuffer.Append($"Tax Price: {_taxVal}");
		prodDetailsBuffer.Append(Environment.NewLine);
		prodDetailsBuffer.Append($"Discount: {_discountVal}");
		return prodDetailsBuffer.ToString();
	}
    }
}
