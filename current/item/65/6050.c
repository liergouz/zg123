
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��ͷñ");
        set_picid_1(6578);
        set_picid_2(6578);

        set_level(50);
        set_value(18000);
        set_max_lasting(6699);
        set("dp", 35);
        set("pp", 58);

        setup();

        set_gender(1);
        set_head_code(43);
}

// ��������ȡ����
string get_desc()
{
        return "��ͷñ";
}
