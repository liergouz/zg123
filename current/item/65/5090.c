
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("���ƹ�");
        set_picid_1(6560);
        set_picid_2(6560);

        set_level(90);
        set_value(40000);
        set_max_lasting(9099);
        set("dp", 62);
        set("pp", 102);

        setup();

        set_gender(1);
        set_head_code(46);
}

// ��������ȡ����
string get_desc()
{
        return "���ƹ�";
}
