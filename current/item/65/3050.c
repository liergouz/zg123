
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ս���");
        set_picid_1(6578);
        set_picid_2(6578);

        set_level(50);
        set_value(12000);
        set_max_lasting(9099);
        set("dp", 68);
        set("pp", 28);

        setup();

        set_gender(1);
        set_head_code(43);
}

// ��������ȡ����
string get_desc()
{
        return "ս���";
}
