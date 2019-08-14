To run the program:
1. Go into the main and enter the desired product: phone, Video or hamburger
and include a letter to reference the object when printing it.

Ex: phone a (Only has 1 accesory, therefore accessory slot 2 is not necessary)
    Video b (Has no accesories, therefore accessory slot 1 is not necessary)
    hamburger c (Has 2 accessories, 1 for condiments and 1 for buns, there for an extra 1 or 0 must be included at the end)

2. Include data for the product. Product insurance, overnight shipping and extra accessories are turned on by inputting a 1, turn off by inputting a 0

phone a("Customer Name", "Street Name", "City State", home number, zipcode, product amount, insurance, overnight shipping, phone cases);
Ex: phone a("John Smith", "Winsley Avenue", "Tuscon AZ", 1234, 85641, 1, 0, 1, 0);

Video c("Customer Name", "Street Name", "City State", home number, zipcode, product amount, insurance, overnight shipping);
Ex: Video c("John Smith", "Downrow Street", "San Fransisco CA", 1501, 95151, 1, 0, 1);

Hamburger f("Customer Name", "Street Name", "City State", home number, zipcode, product amount, insurance, overnight shipping, hamburger buns, condiments);
Ex:hamburger f("John Smith", "Main Street", "Irvine CA", 1501, 92605, 1, 0, 1, 1,0);


Ex: phone a("John Smith", "Winsley Avenue", "Tuscon AZ", 1234, 85641, 1, 0, 1, 0);s
This example prints: 
Customer: John Smith    Expected Arrival Date: 12/12/19
1234 Winsley Avenue
Tuscon AZ, 85641
1 phones ordered: $799.99 overnight delivery is $25.00. No phone cases added to order.
No insurance specified
Total cost is $824.99
Discount percentage is 2.9% for a discount of $23.92.
Total cost after discount is $801.07.