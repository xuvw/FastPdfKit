//
//  SearchManager.h
//  FastPDFKitTest
//
//  Created by Nicolò Tosi on 1/10/11.
//  Copyright 2011 com.mobfarm. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MFDocumentOverlayDataSource.h"

@class MFDocumentManager;

@interface SearchManager : UIView <MFDocumentOverlayDataSource> {

	// Status.
	
    NSUInteger status;
    
	BOOL stopped;
	BOOL running;
	
	// Data.
	NSUInteger startingPage;		// Starting page for the sarch.
	NSUInteger maxPage;				// Max page of the document.
	NSUInteger currentPage;			// Current page.
	NSString * currentSearchTerm;	// Current search term.
	
    // Options.
    BOOL ignoreCase;
    BOOL exactMatch;
    
	// Concurrent operations.
	NSOperation * currentSearchOperation;		// Reference to the current op.
	NSOperationQueue * searchOperationQueue;	// The operation queue.
	
	MFDocumentManager * document;	// Our document.
	
	NSMutableArray * searchResults;	// Array of results. It's an array of array.
}

@property (nonatomic,strong) NSOperation * currentSearchOperation;
@property (nonatomic,strong) MFDocumentManager * document;
@property (nonatomic,copy) NSString * searchTerm;
@property (nonatomic,strong) NSMutableArray * searchResults;
@property (nonatomic,copy) NSString *currentSearchTerm;

-(BOOL)isRunning;
-(BOOL)isCancelled;
-(BOOL)isStopped;

-(NSArray *)searchResultsAsPlainArray;
-(void)stopSearch;
-(void)cancelSearch; 
-(void)startSearchOfTerm:(NSString *)term 
                fromPage:(NSUInteger)startingPage;
-(void)startSearchOfTerm:(NSString *)term 
                fromPage:(NSUInteger)page 
              ignoreCase:(BOOL)ignoreCaseOrNot 
              exactMatch:(BOOL)exactMatchOrNot;
@end
