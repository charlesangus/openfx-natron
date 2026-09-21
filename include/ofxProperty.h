#ifndef _ofxPropertyHost_h_
#define _ofxPropertyHost_h_

/*
Software License :

Copyright (c) 2003-2009, The Open Effects Association Ltd. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name The Open Effects Association Ltd, nor the names of its 
      contributors may be used to endorse or promote products derived from this
      software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "ofxCore.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @file ofxProperty.h
Contains the API for manipulating generic properties. For more details see \ref PropertiesPage.
*/

#define kOfxPropertySuite "OfxPropertySuite"

/** @brief The OFX suite used to access properties on OFX objects.

*/
typedef struct OfxPropertySuiteV1 {
  /** @brief Set a single value in a pointer property 

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index is for multidimenstional properties and is dimension of the one we are setting
      \arg value is the value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
  */
  OfxStatus (*propSetPointer)(OfxPropertySetHandle properties, const char *property, int index, void *value);

  /** @brief Set a single value in a string property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index is for multidimenstional properties and is dimension of the one we are setting
      \arg value is the value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
 */
  OfxStatus (*propSetString) (OfxPropertySetHandle properties, const char *property, int index, const char *value);

  /** @brief Set a single value in a double property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index is for multidimenstional properties and is dimension of the one we are setting
      \arg value is the value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
 */
  OfxStatus (*propSetDouble) (OfxPropertySetHandle properties, const char *property, int index, double value);

  /** @brief Set a single value in  an int property 

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index is for multidimenstional properties and is dimension of the one we are setting
      \arg value is the value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
*/
  OfxStatus (*propSetInt)    (OfxPropertySetHandle properties, const char *property, int index, int value);

  /** @brief Set multiple values of the pointer property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are setting in that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
 */
  OfxStatus (*propSetPointerN)(OfxPropertySetHandle properties, const char *property, int count, void *const*value);

  /** @brief Set multiple values of a string property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are setting in that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
  */
  OfxStatus (*propSetStringN) (OfxPropertySetHandle properties, const char *property, int count, const char *const*value);

  /** @brief Set multiple values of  a double property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are setting in that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue

  */
  OfxStatus (*propSetDoubleN) (OfxPropertySetHandle properties, const char *property, int count, const double *value);

  /** @brief Set multiple values of an int property 

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are setting in that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue

 */
  OfxStatus (*propSetIntN)    (OfxPropertySetHandle properties, const char *property, int count, const int *value);
  
  /** @brief Get a single value from a pointer property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index refers to the index of a multi-dimensional property
      \arg value is a pointer the return location

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetPointer)(OfxPropertySetHandle properties, const char *property, int index, void **value);

  /** @brief Get a single value of a string property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index refers to the index of a multi-dimensional property
      \arg value is a pointer the return location

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetString) (OfxPropertySetHandle properties, const char *property, int index, const char **value);

  /** @brief Get a single value of a double property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index refers to the index of a multi-dimensional property
      \arg value is a pointer the return location

      See the note \ref ArchitectureStrings for how to deal with strings.

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetDouble) (OfxPropertySetHandle properties, const char *property, int index, double *value);

  /** @brief Get a single value of an int property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg index refers to the index of a multi-dimensional property
      \arg value is a pointer the return location

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetInt)    (OfxPropertySetHandle properties, const char *property, int index, int *value);

  /** @brief Get multiple values of a pointer property 

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are getting of that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of where we will return the property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetPointerN)(OfxPropertySetHandle properties, const char *property, int count, void **value);

  /** @brief Get multiple values of a string property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are getting of that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of where we will return the property values

      See the note \ref ArchitectureStrings for how to deal with strings.

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetStringN) (OfxPropertySetHandle properties, const char *property, int count, const char **value);

  /** @brief Get multiple values of a double property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are getting of that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of where we will return the property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetDoubleN) (OfxPropertySetHandle properties, const char *property, int count, double *value);

  /** @brief Get multiple values of an int property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property
      \arg count is the number of values we are getting of that property (ie: indicies 0..count-1)
      \arg value is a pointer to an array of where we will return the property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetIntN)    (OfxPropertySetHandle properties, const char *property, int count, int *value);

  /** @brief Resets all dimensions of a property to its default value

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property we are resetting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
   */
  OfxStatus (*propReset)    (OfxPropertySetHandle properties, const char *property);

  /** @brief Gets the dimension of the property

      \arg properties is the handle of the thing holding the property
      \arg property is the string labelling the property we are resetting
      \arg count is a pointer to an integer where the value is returned

    @returns
      - ::kOfxStatOK
      - ::kOfxStatErrBadHandle
      - ::kOfxStatErrUnknown
 */
  OfxStatus (*propGetDimension)  (OfxPropertySetHandle properties, const char *property, int *count);
} OfxPropertySuiteV1;

/** @brief Identifies the underlying C type used to store a property's value.

    @version Added in OpenFX NEXT
 */
typedef enum OfxPropDataType
{
  /** @brief The property does not exist, or its type is not yet known. A zero-initialised
      OfxPropDataType reads as this value. */
  kOfxPropDataTypeNone = 0,

  /** @brief The property is fetched with OfxPropertySuiteV1::propGetPointer or OfxPropertySuiteV1::propGetPointerN */
  kOfxPropDataTypePointer = 1,

  /** @brief The property is fetched with OfxPropertySuiteV1::propGetString or OfxPropertySuiteV1::propGetStringN */
  kOfxPropDataTypeString = 2,

  /** @brief The property is fetched with OfxPropertySuiteV1::propGetDouble or OfxPropertySuiteV1::propGetDoubleN */
  kOfxPropDataTypeDouble = 3,

  /** @brief The property is fetched with OfxPropertySuiteV1::propGetInt or OfxPropertySuiteV1::propGetIntN */
  kOfxPropDataTypeInteger = 4
} OfxPropDataType;

/** @brief The OFX suite used to access properties on OFX objects.

    This extends OfxPropertySuiteV1, and should be considered a replacement to version 1.

    Note that this suite has been extended in a strictly backwards compatible manner: the
    first eighteen members are identical in type and order to OfxPropertySuiteV1, so a host
    may return this same struct for a ::kOfxPropertySuite fetchSuite request for either
    version 1 or version 2.

    @version Added in OpenFX NEXT
*/
typedef struct OfxPropertySuiteV2 {
  /** @brief Set a single value in a pointer property 

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index for multidimenstional properties and is dimension of the one we are setting
      \arg \c value value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
  */
  OfxStatus (*propSetPointer)(OfxPropertySetHandle properties, const char *property, int index, void *value);

  /** @brief Set a single value in a string property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index for multidimenstional properties and is dimension of the one we are setting
      \arg \c value value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
 */
  OfxStatus (*propSetString) (OfxPropertySetHandle properties, const char *property, int index, const char *value);

  /** @brief Set a single value in a double property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index for multidimenstional properties and is dimension of the one we are setting
      \arg \c value value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
 */
  OfxStatus (*propSetDouble) (OfxPropertySetHandle properties, const char *property, int index, double value);

  /** @brief Set a single value in  an int property 

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index for multidimenstional properties and is dimension of the one we are setting
      \arg \c value value of the property we are setting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
*/
  OfxStatus (*propSetInt)    (OfxPropertySetHandle properties, const char *property, int index, int value);

  /** @brief Set multiple values of the pointer property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are setting in that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
 */
  OfxStatus (*propSetPointerN)(OfxPropertySetHandle properties, const char *property, int count, void *const*value);

  /** @brief Set multiple values of a string property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are setting in that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue
  */
  OfxStatus (*propSetStringN) (OfxPropertySetHandle properties, const char *property, int count, const char *const*value);

  /** @brief Set multiple values of  a double property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are setting in that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue

  */
  OfxStatus (*propSetDoubleN) (OfxPropertySetHandle properties, const char *property, int count, const double *value);

  /** @brief Set multiple values of an int property 

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are setting in that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
        - ::kOfxStatErrValue

 */
  OfxStatus (*propSetIntN)    (OfxPropertySetHandle properties, const char *property, int count, const int *value);
  
  /** @brief Get a single value from a pointer property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index refers to the index of a multi-dimensional property
      \arg \c value pointer the return location

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetPointer)(OfxPropertySetHandle properties, const char *property, int index, void **value);

  /** @brief Get a single value of a string property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index refers to the index of a multi-dimensional property
      \arg \c value pointer the return location

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetString) (OfxPropertySetHandle properties, const char *property, int index, const char **value);

  /** @brief Get a single value of a double property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index refers to the index of a multi-dimensional property
      \arg \c value pointer the return location

      See the note \ref ArchitectureStrings for how to deal with strings.

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetDouble) (OfxPropertySetHandle properties, const char *property, int index, double *value);

  /** @brief Get a single value of an int property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c index refers to the index of a multi-dimensional property
      \arg \c value pointer the return location

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
 */
  OfxStatus (*propGetInt)    (OfxPropertySetHandle properties, const char *property, int index, int *value);

  /** @brief Get multiple values of a pointer property 

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are getting of that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of where we will return the property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetPointerN)(OfxPropertySetHandle properties, const char *property, int count, void **value);

  /** @brief Get multiple values of a string property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are getting of that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of where we will return the property values

      See the note \ref ArchitectureStrings for how to deal with strings.

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetStringN) (OfxPropertySetHandle properties, const char *property, int count, const char **value);

  /** @brief Get multiple values of a double property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are getting of that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of where we will return the property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetDoubleN) (OfxPropertySetHandle properties, const char *property, int count, double *value);

  /** @brief Get multiple values of an int property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c count number of values we are getting of that property (ie: indices 0..count-1)
      \arg \c value pointer to an array of where we will return the property values

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
        - ::kOfxStatErrBadIndex
  */
  OfxStatus (*propGetIntN)    (OfxPropertySetHandle properties, const char *property, int count, int *value);

  /** @brief Resets all dimensions of a property to its default value

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property we are resetting

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
   */
  OfxStatus (*propReset)    (OfxPropertySetHandle properties, const char *property);

  /** @brief Gets the dimension of the property

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property we are resetting
      \arg \c count pointer to an integer where the value is returned

    @returns
      - ::kOfxStatOK
      - ::kOfxStatErrBadHandle
      - ::kOfxStatErrUnknown
 */
  OfxStatus (*propGetDimension)  (OfxPropertySetHandle properties, const char *property, int *count);

  /** @brief Get the underlying data type of a property.

      \arg \c properties handle of the thing holding the property
      \arg \c property string labelling the property
      \arg \c type pointer to the return location for the property's data type

      This lets a plugin determine which \c propGet* call to use for a property name it
      discovers at runtime, for example when enumerating an unfamiliar property set. If
      \e property does not exist on \e properties, ::kOfxStatErrUnknown is returned and
      the value written to \e type is undefined.

      Because the type is returned through a pointer to an OfxPropDataType, the host and
      plugin must agree on the enum's underlying width, so neither may be built with a
      compiler option such as \c -fshort-enums that changes it from the platform default.

      @returns
        - ::kOfxStatOK
        - ::kOfxStatErrBadHandle
        - ::kOfxStatErrUnknown
  */
  OfxStatus (*propGetType) (OfxPropertySetHandle properties, const char *property, OfxPropDataType *type);

} OfxPropertySuiteV2;

/**
   \addtogroup ErrorCodes 
*/
/*@{*/


/*@}*/



#ifdef __cplusplus
}
#endif


#endif
