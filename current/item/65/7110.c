
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("���۹�");
        set_picid_1(6542);
        set_picid_2(6542);

        set_level(110);
        set_value(51000);
        set_max_lasting(10299);
        set("dp", 73);
        set("pp", 141);

        setup();

        set_gender(1);
        set_head_code(48);
}

// ��������ȡ����
string get_desc()
{
        return "���۹�";
}
