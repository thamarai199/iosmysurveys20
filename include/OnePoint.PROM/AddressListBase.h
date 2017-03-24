// --------------------------------------------------------------------------------------------------------------------
// <copyright file="AddressListBase.java" company="OnePoint Global">
//   Copyright (c) 2012 OnePoint Global Ltd. All rights reserved.
// </copyright>
// <summary>
//   This file was autogenerated and you should not edit it. It will be 
//   regenerated whenever the schema changes.
//   All changes should be made in AddressList.cs and the mode.xml. 
// </summary>
// --------------------------------------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <OnePointFramework/DataObject.h>
#import "IAddressListData.h"




//package OnePoint.PROM.Model 
    


    
@interface  AddressListBase : DataObject<DataObject, IAddressListData>
{
@private NSNumber *AddressListID;
        
@private NSString *Description;
        
@private NSString *Name;
        
@private NSNumber *UserID;
        
@private NSDate *CreatedDate;
        
@private NSDate *LastUpdatedDate;
        
@private NSNumber *IsDeleted;
        
}


	  
/// <summary>
/// Gets or sets the 
/// </summary>

	@property(nonatomic,retain) NSNumber *AddressListID;

	
	@property(readwrite,strong) NSString *Description;

	
	@property(readwrite,strong) NSString *Name;

	/// <summary>
/// Gets or sets the 
/// </summary>

	@property(nonatomic,retain) NSNumber *UserID;

	/// <summary>
/// Gets or sets the 
/// </summary>

	@property(readwrite,strong) NSDate *CreatedDate;

	
	@property(readwrite,strong) NSDate *LastUpdatedDate;

	
	@property(nonatomic,retain) NSNumber *IsDeleted;

	@end
         

    

    