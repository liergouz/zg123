/*---------------------------------------------------------------------------------*\
	新手物品：战国宝典。详情见文档《战国宝典设定》
	由 cjxx 于 2007-09-04 创建
\*---------------------------------------------------------------------------------*/
inherit ITEM;
#define ZG_DICTIONARY		"/quest/zg_dict"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}

//	道具是否可用
int is_usable() {
	return 1;
}
//	构造函数
void create() {
	set_name("战国宝典");
	set_picid_1(1017);
	set_picid_2(1017);	
	set_value(0);		//	价值为0
	//set_no_get(1);	//	不可存当铺
	set_no_give(1);		//	不可给予
	set_no_sell(1);		//	不可出售
}
//	道具描述
string get_desc() {
	return "相传宝典上记载着每个层次的玩家可以去冒险的地方。\n玩家每提升一级都会有一次摇奖的机会，但是如果不把握住这次机会，就会流失掉。";
}
//	执行使用效果函数
int get_use_effect(object me) {
	return __FILE__->get_use_effect_callout(me,this_object());
}
//	实际使用效果函数
int get_use_effect_callout(object me,object item) {
	ZG_DICTIONARY->search_in_user(me);
}