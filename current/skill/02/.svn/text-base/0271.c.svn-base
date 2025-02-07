
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0271);
        set_name( "降魔法咒" );
}

// 函数：能否特殊技
void can_perform( object me )
{	
	me->set_attack_move(1);
        __DIR__ "02711"->can_perform(me);
        __DIR__ "02712"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 02711 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_cp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［降魔法咒］提升法术的攻击力，每级提升2点。\n";
}
