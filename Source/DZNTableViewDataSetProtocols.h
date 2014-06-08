//
//  DZNTableViewDataSetProtocols.h
//  UITableView-DataSet
//  https://github.com/dzenbot/UITableView-DataSet
//
//  Created by Ignacio Romero Zurbuchen on 6/1/14.
//  Copyright (c) 2014 DZN Labs. All rights reserved.
//  Licence: MIT-Licence
//

#import <Foundation/Foundation.h>

/**
 * The object that acts as the data source of the data sets.
 * The data source must adopt the DZNTableViewDataSetSource protocol. The data source is not retained.
 *
 * @discussion All data source methods are optional.They will not be considered in the layout if they either return nil or the view controller doesn't conform to them.
 */
@protocol DZNTableViewDataSetSource <NSObject>
@required

@optional

/**
 * Asks the data source for the title of the data set.
 * The data set uses a fixed font style by default, if no attributes are set. If you want a different font style, return a attributed string.
 *
 * @param tableView A table-view object informing the data source.
 * @return An attributed string for the data set title, combining font, text color, text pararaph style, etc.
 */
- (NSAttributedString *)titleForTableViewDataSet:(UITableView *)tableView;

/**
 * Asks the data source for the description of the data set.
 * The data set uses a fixed font style by default, if no attributes are set. If you want a different font style, return a attributed string.
 *
 * @param tableView A table-view object informing the data source.
 * @return An attributed string for the data set description text, combining font, text color, text pararaph style, etc.
 */
- (NSAttributedString *)descriptionForTableViewDataSet:(UITableView *)tableView;

/**
 * Asks the data source for the image of the data set.
 *
 * @param tableView A table-view object informing the data source.
 * @return An image for the data set.
 */
- (UIImage *)imageForTableViewDataSet:(UITableView *)tableView;

/**
 * Asks the data source for the title to be used for the specified button state.
 * The data set uses a fixed font style by default, if no attributes are set. If you want a different font style, return a attributed string.
 *
 * @param tableView A table-view object informing the data source.
 * @param state The state that uses the specified title. The possible values are described in UIControlState.
 * @return An attributed string for the data set button title, combining font, text color, text pararaph style, etc.
 */
- (NSAttributedString *)buttonTitleForTableViewDataSet:(UITableView *)tableView forState:(UIControlState)state;

/**
 * Asks the data source for a background image to be used for the specified button state.
 * There is no default style for this call.
 *
 * @param tableView A table-view object informing the data source.
 * @param state The state that uses the specified image. The values are described in UIControlState.
 * @return An attributed string for the data set button title, combining font, text color, text pararaph style, etc.
 */
- (UIImage *)buttonBackgroundImageForTableViewDataSet:(UITableView *)tableView forState:(UIControlState)state;

/**
 * Asks the data source for the background color of the data set. Default is clear color.
 *
 * @param tableView A table-view object informing the data source.
 * @return An color to be applied to the data set background view.
 */
- (UIColor *)backgroundColorForTableViewDataSet:(UITableView *)tableView;

/**
 * Aks the data source for a custom vertical space. Default is 11 pts.
 *
 * @param tableView A table-view object informing the delegate.
 * @return The space height between elements.
 */
- (CGFloat)spaceHeightForTableViewDataSet:(UITableView *)tableView;

@end


/**
 * The object that acts as the delegate of the data sets.
 * The delegate must adopt the DZNTableViewDataSetDelegate protocol. The delegate is not retained.
 *
 * @discussion All delegate methods are optional. Use this delegate for receiving action callbacks.
 */
@protocol DZNTableViewDataSetDelegate <NSObject>
@required
@optional

/**
 * Aks the delegate for touch permission. Default is YES.
 *
 * @param tableView A table-view object informing the delegate.
 * @return YES if the data set receives touch gestures.
 */
- (BOOL)tableViewDataSetShouldAllowTouch:(UITableView *)tableView;

/**
 * Aks the delegate for scroll permission. Default is NO.
 *
 * @param tableView A table-view object informing the delegate.
 * @return YES if the data set is allowed to be scrollable.
 */
- (BOOL)tableViewDataSetShouldAllowScroll:(UITableView *)tableView;

/**
 * Tells the delegate that the data set view was tapped.
 * Use this method either to resignFirstResponder of a textfield or searchBar.
 *
 * @param tableView A table-view object informing the delegate.
 */
- (void)tableViewDataSetDidTapView:(UITableView *)tableView;

/**
 * Tells the delegate that the option button was tapped.
 *
 * @param tableView A table-view object informing the delegate.
 */
- (void)tableViewDataSetDidTapButton:(UITableView *)tableView;


@end
