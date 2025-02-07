
inherit SKILL;

// 函数：命令处理
int main( object me, object npc, object item )
{
	int ret;
	if (!npc) return 1;
	if (!item) return 1;
	if (npc->get_name()!="修理店老板") return 1;
	if( !inside_screen_2(me, npc) ) return 1;
	if (item->if_in_user(me)==0) return 1;
	"/sys/item/product"->make_stuff(me, npc, item);
	return 1;		
}