
#include <skill.h>
#include <effect.h>

inherit "/inh/item/poison";

// ��������ȡ���Ե���
int get_poison() { return 300; }

// ��������Ʒ���
int get_fin_type() { return 1820; }

// ���������촦��
void create()
{
        set_name( "�׶���" );
        set_picid_1(5211);
        set_picid_2(5211);
        set_unit( "ƿ" );
        set_value(2000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ�ֺ��������Զ�ҩ��ÿ2��ʹ�����Ѫֵ�½�15�㣬����40�롣";
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
