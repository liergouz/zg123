
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��¶ñ");
        set_picid_1(6574);
        set_picid_2(6574);

        set_level(30);
        set_value(7000);
        set_max_lasting(5499);
        set("dp", 26);
        set("pp", 36);

        setup();

        set_gender(1);
        set_head_code(42);
}

// ��������ȡ����
string get_desc()
{
        return "��¶ñ";
}
