// --------------------------------------------------------------------------------------------------------------------
// <copyright file="IPanellistProfileVariableDataType" company="OnePoint Global">
//   Copyright (c) 2012 OnePoint Global Ltd. All rights reserved.
// </copyright>
// <summary>
//   This file was autogenerated and you should not edit it. It will be 
//   regenerated whenever the schema changes.
//   All changes should be made in PanellistProfileVariableDataType.cs and the mode.xml. 
// </summary>
// --------------------------------------------------------------------------------------------------------------------


/// <summary>
/// The IPanellistProfileVariableDataType Interface Data Object Base
/// </summary>

#import <Foundation/Foundation.h>


/// <summary>
/// The IPanellistProfileVariableDataTypeFactoryBase Interface Data Object Base
/// </summary>
	
@protocol IPanellistProfileVariableDataTypeFactoryBase <NSObject>
   
-(NSString *) SelectAllStatement;
-(NSString *)TableName;
-(NSString *)ByPkClause;
-(NSString *)InsertStatement;
-(NSString *)UpdateStatement;
-(NSString *)DeleteStatement;
-(NSString *)DeleteByPk;


-(void) AddTypeIDParameter:(DataHandler *) dataHandler withTypeID:(NSNumber*) TypeID;     
-(void) AddTypeParameter:(DataHandler *) dataHandler withType:(NSNumber*) Type;     
-(void) AddNameParameter:(DataHandler *) dataHandler withName:(NSString *) Name;  
-(void) AddDescriptionParameter:(DataHandler *) dataHandler withDescription:(NSString *) Description;  
-(void) AddIsDeletedParameter:(DataHandler *) dataHandler withIsDeleted:(NSNumber*) IsDeleted;     
-(void) AddCreatedDateParameter:(DataHandler *) dataHandler withCreatedDate:(NSDate *) CreatedDate; 
-(id<IPanellistProfileVariableDataTypeData>) FindByTypeID:(NSNumber *) fieldValue;
        
-(id<IPanellistProfileVariableDataTypeData>) FindByType:(NSNumber *) fieldValue;
        
-(id<IPanellistProfileVariableDataTypeData>) FindByName:(NSString *) fieldValue;
        
-(id<IPanellistProfileVariableDataTypeData>) FindByDescription:(NSString *) fieldValue;
        
-(id<IPanellistProfileVariableDataTypeData>) FindByIsDeleted:(NSNumber *) fieldValue;
        
-(id<IPanellistProfileVariableDataTypeData>) FindByCreatedDate:(NSDate *) fieldValue;
        
-(id<IPanellistProfileVariableDataTypeData>) CreatePanellistProfileVariableDataType:(id<IDataReader>)reader;

@end
    

   
    
