
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����ñ");
        set_picid_1(6558);
        set_picid_2(6558);

        set_level(65);
        set_value(26300);
        set_max_lasting(7599);
        set("dp", 44);
        set("pp", 75);

        setup();

        set_gender(1);
        set_head_code(45);
}

// ��������ȡ����
string get_desc()
{
        return "����ñ";
}
