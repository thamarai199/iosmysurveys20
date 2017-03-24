// --------------------------------------------------------------------------------------------------------------------
// <copyright file="IMediaAttachment" company="OnePoint Global">
//   Copyright (c) 2012 OnePoint Global Ltd. All rights reserved.
// </copyright>
// <summary>
//   This file was autogenerated and you should not edit it. It will be 
//   regenerated whenever the schema changes.
//   All changes should be made in MediaAttachment.cs and the mode.xml. 
// </summary>
// --------------------------------------------------------------------------------------------------------------------


/// <summary>
/// The IMediaAttachment Interface Data Object Base
/// </summary>
 
#import <Foundation/Foundation.h>   

/// <summary>
/// The IMediaAttachmentData Interface Data Object Base
/// </summary>
@protocol IMediaAttachmentData <NSObject>
    
-(NSNumber *) MediaID;
-(void) setMediaID:(NSNumber *) value;
-(NSNumber *) MediaTypeID;
-(void) setMediaTypeID:(NSNumber *) value;
-(NSNumber *) MediaUsageTypeID;
-(void) setMediaUsageTypeID:(NSNumber *) value;
-(BOOL) MediaUsageTypeIDSpecified;
-(void) setMediaUsageTypeIDSpecified:(BOOL) value;
-(NSString *) NameSpecified;
-(void) setNameSpecified:(NSString *) value;
-(NSString *) DescriptionSpecified;
-(void) setDescriptionSpecified:(NSString *) value;
-(NSNumber *) IsDeleted;
-(void) setIsDeleted:(NSNumber *) value;
-(NSString *) CommentsSpecified;
-(void) setCommentsSpecified:(NSString *) value;
-(NSString *) RemarkSpecified;
-(void) setRemarkSpecified:(NSString *) value;
-(NSMutableData *) Blob;
-(void) setBlob:(NSMutableData *) value;
-(NSMutableData *) FlashBlob;
-(void) setFlashBlob:(NSMutableData *) value;
-(BOOL) FlashBlobSpecified;
-(void) setFlashBlobSpecified:(BOOL) value;
-(NSMutableData *) SnapshotBlob;
-(void) setSnapshotBlob:(NSMutableData *) value;
-(BOOL) SnapshotBlobSpecified;
-(void) setSnapshotBlobSpecified:(BOOL) value;
-(NSDate *) CreatedDate;
-(void) setCreatedDate:(NSDate *) value;
-(BOOL) CreatedDateSpecified;
-(void) setCreatedDateSpecified:(BOOL) value;
-(NSNumber *) UserID;
-(void) setUserID:(NSNumber *) value;
-(BOOL) UserIDSpecified;
-(void) setUserIDSpecified:(BOOL) value;
-(NSMutableData *) MovBlob;
-(void) setMovBlob:(NSMutableData *) value;
-(BOOL) MovBlobSpecified;
-(void) setMovBlobSpecified:(BOOL) value;
-(NSMutableData *) T3gBlob;
-(void) setT3gBlob:(NSMutableData *) value;
-(BOOL) T3gBlobSpecified;
-(void) setT3gBlobSpecified:(BOOL) value;
-(NSMutableData *) Mp4Blob;
-(void) setMp4Blob:(NSMutableData *) value;
-(BOOL) Mp4BlobSpecified;
-(void) setMp4BlobSpecified:(BOOL) value;
-(NSMutableData *) OggBlob;
-(void) setOggBlob:(NSMutableData *) value;
-(BOOL) OggBlobSpecified;
-(void) setOggBlobSpecified:(BOOL) value;
-(NSMutableData *) WebmBlob;
-(void) setWebmBlob:(NSMutableData *) value;
-(BOOL) WebmBlobSpecified;
-(void) setWebmBlobSpecified:(BOOL) value;
-(NSDate *) LastUpdatedDate;
-(void) setLastUpdatedDate:(NSDate *) value;
-(BOOL) LastUpdatedDateSpecified;
-(void) setLastUpdatedDateSpecified:(BOOL) value;

@end
   

   
    

