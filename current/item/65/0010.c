
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�޲�ñ");
        set_picid_1(6523);
        set_picid_2(6523);

        set_level(10);
        set_value(1800);
        set_max_lasting(4299);
        set("dp", 11);
        set("pp", 0);

        setup();

        set_gender(1);
        set_head_code(40);
}

// ��������ȡ����
string get_desc()
{
        return "�޲�ñ";
}
