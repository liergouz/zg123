
// �Զ����ɣ�/make/item/make90
#include <item.h>
#include <skill.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;

inherit "/inh/item/poison";

// ��������ȡ���Ե���
int get_poison() { return 100; }

// ��������������
int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 106; }


// ������ԭ����ɫ
int get_item_color() { return 0; }

// ���������촦��
void create()
{
        set_name("��˪");
        set_picid_1(5210);
        set_picid_2(5210);
        set_value(40);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ�ֱȽϳ����Ķ�ҩ��ÿ2��ʹ�����Ѫֵ�½�10�㣬����20�롣";
}

// ������ʹ��Ч��
int get_poison_effect( object me, object who, int poison ) { return __FILE__ ->get_poison_effect_callout(me, who, poison); }

// ������ʹ��Ч��(���߸���)
int get_poison_effect_callout( object me, object who, int poison )
{
        if(    !get_effect(who, EFFECT_CHAR_POISON)
        &&     !get_effect(who, EFFECT_CHAR_9140)    // �ٶ�ɢ
        &&      random(100) < 100 - who->get_anti_poison() )
        {
                who->set_poison(poison);
                set_effect_2(who, EFFECT_CHAR_POISON, 10, 2);
                send_user( who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD );
        }
        return 1;
}
