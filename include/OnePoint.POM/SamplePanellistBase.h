// --------------------------------------------------------------------------------------------------------------------
// <copyright file="SamplePanellistBase.java" company="OnePoint Global">
//   Copyright (c) 2012 OnePoint Global Ltd. All rights reserved.
// </copyright>
// <summary>
//   This file was autogenerated and you should not edit it. It will be 
//   regenerated whenever the schema changes.
//   All changes should be made in SamplePanellist.cs and the mode.xml. 
// </summary>
// --------------------------------------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <OnePointFramework/DataObject.h>
#import "ISamplePanellistData.h"



#import "IPanellistProfileData.h";
#import "PanellistProfileFactory.h";

//package OnePoint.POM.Model 
    
	

    
@interface  SamplePanellistBase : DataObject<DataObject, ISamplePanellistData>
{
@private NSNumber *SamplePanellistID;
        
@private NSNumber *SampleID;
        
@private NSNumber *PanellistID;
        
@private NSNumber *PanelID;
        
@private NSNumber *Excluded;
        
@private NSNumber *IsDeleted;
        
@private NSDate *CreatedDate;
        
@private NSDate *LastUpdatedDate;
        
@private id<IPanellistProfileData> relPanellistProfile; 
}


	  

	@property(nonatomic,retain) NSNumber *SamplePanellistID;

	
	@property(nonatomic,retain) NSNumber *SampleID;

	
	@property(nonatomic,retain) NSNumber *PanellistID;

	
	@property(nonatomic,retain) NSNumber *PanelID;

	
	@property(nonatomic,retain) NSNumber *Excluded;

	
	@property(nonatomic,retain) NSNumber *IsDeleted;

	
	@property(readwrite,strong) NSDate *CreatedDate;

	
	@property(readwrite,strong) NSDate *LastUpdatedDate;

	@property(readwrite,strong) id<IPanellistProfileData> RelPanellistProfile; 
@end
         

    

    