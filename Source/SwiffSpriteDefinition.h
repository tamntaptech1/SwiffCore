/*
    SwiffSprite.h
    Copyright (c) 2011-2012, musictheory.net, LLC.  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of musictheory.net, LLC nor the names of its contributors
          may be used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL MUSICTHEORY.NET, LLC BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <SwiffImport.h>
#import <SwiffParser.h>
#import <SwiffDefinition.h>

@class SwiffFrame, SwiffScene, SwiffMovie, SwiffSceneAndFrameLabelData, SwiffSparseArray, SwiffSoundDefinition, SwiffSoundStreamData;


@interface SwiffSpriteDefinition : NSObject <SwiffDefinition> {
@private
    NSMutableArray   *m_frames;
    NSDictionary     *m_labelToFrameMap;
    SwiffFrame       *m_lastFrame;
    NSArray          *m_scenes;
    NSDictionary     *m_sceneNameToSceneMap;

    SwiffSparseArray *m_placedObjects;

    UInt16            m_libraryID;
    CGRect            m_bounds;
    CGRect            m_renderBounds;

@protected
    SwiffUnretained SwiffMovie *m_movie;
}

- (id) initWithParser:(SwiffParser *)parser movie:(SwiffMovie *)movie;

- (SwiffFrame *) frameWithLabel:(NSString *)label;

- (SwiffFrame *) frameAtIndex1:(NSUInteger)index1;
- (NSUInteger) index1OfFrame:(SwiffFrame *)frame;

- (SwiffFrame *) frameAtIndex:(NSUInteger)index1;
- (NSUInteger) indexOfFrame:(SwiffFrame *)frame;

- (SwiffScene *) sceneWithName:(NSString *)name;

@property (nonatomic, strong, readonly) NSArray *scenes;
@property (nonatomic, strong, readonly) NSArray *frames;

@end
