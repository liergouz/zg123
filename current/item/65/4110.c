
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ե��");
        set_picid_1(6542);
        set_picid_2(6542);

        set_level(110);
        set_value(30000);
        set_max_lasting(10899);
        set("dp", 93);
        set("pp", 69);

        setup();

        set_gender(1);
        set_head_code(48);
}

// ��������ȡ����
string get_desc()
{
        return "��Ե��";
}
