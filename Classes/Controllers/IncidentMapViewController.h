/*****************************************************************************
 ** Copyright (c) 2010 Ushahidi Inc
 ** All rights reserved
 ** Contact: team@ushahidi.com
 ** Website: http://www.ushahidi.com
 **
 ** GNU Lesser General Public License Usage
 ** This file may be used under the terms of the GNU Lesser
 ** General Public License version 3 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file. Please review the following information to
 ** ensure the GNU Lesser General Public License version 3 requirements
 ** will be met: http://www.gnu.org/licenses/lgpl.html.
 **
 **
 ** If you have questions regarding the use of this file, please contact
 ** Ushahidi developers at team@ushahidi.com.
 **
 *****************************************************************************/

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import <MapKit/MKAnnotation.h>
#import "BaseViewController.h"
#import "ItemPicker.h"
#import "Ushahidi.h"

@class IncidentTabViewController;
@class IncidentAddViewController;
@class IncidentDetailsViewController;
@class MapViewController;
@class Deployment;
@class Category;

@interface IncidentMapViewController : BaseViewController<UshahidiDelegate, 
														  MKMapViewDelegate, 
														  ItemPickerDelegate> {
@public
	IncidentTabViewController *incidentTabViewController;
	IncidentAddViewController *incidentAddViewController;
	IncidentDetailsViewController *incidentDetailsViewController;
	Deployment *deployment;
	UIBarButtonItem *refreshButton;
	UIBarButtonItem *filterButton;
	UISegmentedControl *mapType;
	UILabel *filterLabel;
	MKMapView *mapView;
  
@private
	NSMutableArray *incidents;	
	NSMutableArray *pending;
	ItemPicker *itemPicker;
	NSMutableArray *categories;
	Category *category;
}

@property(nonatomic,retain) IBOutlet IncidentTabViewController *incidentTabViewController;
@property(nonatomic,retain) IBOutlet IncidentAddViewController *incidentAddViewController;
@property(nonatomic,retain) IBOutlet IncidentDetailsViewController *incidentDetailsViewController;
@property(nonatomic,retain) IBOutlet UISegmentedControl *mapType;
@property(nonatomic,retain) IBOutlet UIBarButtonItem *refreshButton;
@property(nonatomic,retain) IBOutlet UIBarButtonItem *filterButton;
@property(nonatomic,retain) IBOutlet UILabel *filterLabel;
@property(nonatomic,retain) IBOutlet MKMapView *mapView;
@property(nonatomic,retain) Deployment *deployment;

- (IBAction) addReport:(id)sender;
- (IBAction) refresh:(id)sender;
- (IBAction) mapTypeChanged:(id)sender;
- (IBAction) filterChanged:(id)sender event:(UIEvent*)event;
- (void) populate:(BOOL)refresh resize:(BOOL)resize;

@end
