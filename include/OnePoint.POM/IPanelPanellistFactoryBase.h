// --------------------------------------------------------------------------------------------------------------------
// <copyright file="IPanelPanellist" company="OnePoint Global">
//   Copyright (c) 2012 OnePoint Global Ltd. All rights reserved.
// </copyright>
// <summary>
//   This file was autogenerated and you should not edit it. It will be 
//   regenerated whenever the schema changes.
//   All changes should be made in PanelPanellist.cs and the mode.xml. 
// </summary>
// --------------------------------------------------------------------------------------------------------------------


/// <summary>
/// The IPanelPanellist Interface Data Object Base
/// </summary>

#import <Foundation/Foundation.h>


/// <summary>
/// The IPanelPanellistFactoryBase Interface Data Object Base
/// </summary>
	
@protocol IPanelPanellistFactoryBase <NSObject>
   
-(NSString *) SelectAllStatement;
-(NSString *)TableName;
-(NSString *)ByPkClause;
-(NSString *)InsertStatement;
-(NSString *)UpdateStatement;
-(NSString *)DeleteStatement;
-(NSString *)DeleteByPk;


-(void) AddPanelPanellistIDParameter:(DataHandler *) dataHandler withPanelPanellistID:(NSNumber*) PanelPanellistID;     
-(void) AddPanelIDParameter:(DataHandler *) dataHandler withPanelID:(NSNumber*) PanelID;     
-(void) AddPanellistIDParameter:(DataHandler *) dataHandler withPanellistID:(NSNumber*) PanellistID;     
-(void) AddIncludedParameter:(DataHandler *) dataHandler withIncluded:(NSNumber*) Included;     
-(void) AddIncludedNullParameter:(DataHandler *) dataHandler;
-(void) AddCreatedDateParameter:(DataHandler *) dataHandler withCreatedDate:(NSDate *) CreatedDate; 
-(void) AddLastUpdatedDateParameter:(DataHandler *) dataHandler withLastUpdatedDate:(NSDate *) LastUpdatedDate; 
-(void) AddIsDeletedParameter:(DataHandler *) dataHandler withIsDeleted:(NSNumber*) IsDeleted;     
-(id<IPanelPanellistData>) FindByPanelPanellistID:(NSNumber *) fieldValue;
        
-(id<IPanelPanellistData>) FindByPanelID:(NSNumber *) fieldValue;
        
-(id<IPanelPanellistData>) FindByPanellistID:(NSNumber *) fieldValue;
        
-(id<IPanelPanellistData>) FindByIncluded:(NSNumber *) fieldValue;
        
-(id<IPanelPanellistData>) FindByCreatedDate:(NSDate *) fieldValue;
        
-(id<IPanelPanellistData>) FindByLastUpdatedDate:(NSDate *) fieldValue;
        
-(id<IPanelPanellistData>) FindByIsDeleted:(NSNumber *) fieldValue;
        
-(id<IPanelPanellistData>) CreatePanelPanellist:(id<IDataReader>)reader;

@end
    

   
    

