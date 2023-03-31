#include "../include/graphics/object.h"
#include <gtest/gtest.h>


/*
 * check if the object's properties start with the
 * correct value
 */

TEST(Objects, InitialValues)
{
	Object object;

	ASSERT_EQ(0, object.position().x);
	ASSERT_EQ(0, object.position().y);
	ASSERT_EQ(0, object.position().z);

	ASSERT_EQ(0, object.rotation().x);
	ASSERT_EQ(0, object.rotation().y);
	ASSERT_EQ(0, object.rotation().z);

	ASSERT_EQ(1, object.scale().x);
	ASSERT_EQ(1, object.scale().y);
	ASSERT_EQ(1, object.scale().z);

}

/*
 * check if the transformations are correct
 */

TEST(Objects, Transforms)
{
	Object object;
	object.setPosition(glm::vec3(10, 20, 30));
	glm::mat4 transform = object.getTransform();
	glm::vec3 v(0);
	v = glm::vec3(transform * glm::vec4(v, 1));
	EXPECT_EQ(10, v.x);
	EXPECT_EQ(20, v.y);
	EXPECT_EQ(30, v.z);
}

int main()
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
