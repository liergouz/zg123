
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("���");
        set_picid_1(6638);
        set_picid_2(6638);

        set_level(15);
        set_value(2400);
        set_max_lasting(4899);
        set("dp", 14);
        set("pp", 0);

        setup();

        set_gender(2);
        set_head_code(51);
}

// ��������ȡ����
string get_desc()
{
        return "���";
}
