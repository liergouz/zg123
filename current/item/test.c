
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 1; }
// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("����˧����");
        set_picid_1(6003);
        set_picid_2(6003);

        set_level(0);
        set_value(80);
        set_max_lasting(2599);
        set("dp", 10);
        set("pp", 0);

        setup();

        set_gender(1);
        set_back_type(1);
}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "˧������õ���Ʒ��";
}
