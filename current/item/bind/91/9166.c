
inherit ITEM;
inherit USABLE;

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_value() {return 500 ;}
int get_item_value_2() {return 450 ;}
int get_item_number() {return 10001019 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name( "���ɵ�" );
        set_picid_1(9166);
        set_picid_2(9166);
        set_unit( "��" );
        set_value(50);
        // -- ��ԭװ��������Ӱ�����
        set_no_give(1);
        set_no_sell(1);
        //       
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ഫ���ɹ�λ�󣬼��ϰ����������ƶ��ɡ�\n��ʹ������ȫ�ָ�����ȴʱ��30�롣";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
      	if( gone_time( me->get_time("eat_bx") ) < 30 )
        {
                send_user( me, "%c%s", '!', sprintf("���ð��ɵ�����Ⱥ�%d��", 30 - gone_time( me->get_time("eat_bx") ) ) );
                return 0;
        }
        if (me->get_strength()>=200)
        {
                send_user( me, "%c%s", '!', "��������������" );
                return 0;
        }        
        me->set_time( "eat_bx", time() );  

        me->add_strength(200);

        return 1;
}
